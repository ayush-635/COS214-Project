#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio.hpp>
#include <boost/json.hpp>
#include <iostream>
#include <string>
#include <memory>
#include <sstream>
#include "src/Game/Game.h"

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
namespace json = boost::json;
using tcp = net::ip::tcp;

std::string get_html_content();

class CoutRedirector {
    std::streambuf* old;
    std::stringstream buffer;
public:
    CoutRedirector() : old(std::cout.rdbuf(buffer.rdbuf())) {}
    ~CoutRedirector() { std::cout.rdbuf(old); }
    std::string getString() { return buffer.str(); }
};

class GameSession : public std::enable_shared_from_this<GameSession> {
    tcp::socket socket_;
    beast::flat_buffer buffer_;
    http::request<http::string_body> request_;
    Game* game_;

public:
    GameSession(tcp::socket socket) : socket_(std::move(socket)) {
        game_ = Game::getInstance();
    }

    void run() {
        do_read();
    }

private:
    void do_read() {
        auto self = shared_from_this();
        http::async_read(socket_, buffer_, request_,
            [self](beast::error_code ec, std::size_t) {
                if (!ec) {
                    self->handle_request();
                } else {
                    std::cerr << "Read error: " << ec.message() << std::endl;
                }
            });
    }

    void handle_request() {
        try {
            if (request_.method() == http::verb::get && request_.target() == "/") {
                serve_html();
            } else if (request_.method() == http::verb::post) {
                handle_api();
            } else {
                send_response(http::status::not_found, "{\"error\":\"Not Found\"}", "application/json");
            }
        } catch (std::exception& e) {
            std::cerr << "Request handling error: " << e.what() << std::endl;
            send_response(http::status::internal_server_error, 
                         "{\"error\":\"Internal server error\"}", "application/json");
        }
    }

    void serve_html() {
        std::string html = get_html_content();
        send_response(http::status::ok, html, "text/html");
    }

    void handle_api() {
        std::string target = std::string(request_.target());
        std::string body = request_.body();
        
        json::object response;
        
        try {
            if (!game_) {
                response["error"] = "Game not initialized";
                send_response(http::status::internal_server_error, json::serialize(response), "application/json");
                return;
            }
            
            json::value parsed;
            if (!body.empty()) {
                try {
                    parsed = json::parse(body);
                } catch (std::exception& e) {
                    response["error"] = "Invalid JSON";
                    send_response(http::status::bad_request, json::serialize(response), "application/json");
                    return;
                }
            }
            json::object data = parsed.is_object() ? parsed.as_object() : json::object();
            
            CoutRedirector capture;
            
            if (target == "/api/build") {
                int type = static_cast<int>(data["type"].as_int64());
                bool success = game_->buildSpace(type);
                std::string output = capture.getString();
                response["success"] = success;
                response["message"] = success ? "Space built!" : "Failed to build";
                response["output"] = output;
            }
            else if (target == "/api/buySeeds") {
                std::string plant = std::string(data["plant"].as_string().c_str());
                int qty = static_cast<int>(data["qty"].as_int64());
                bool success = game_->buySeed(plant, qty);
                std::string output = capture.getString();
                response["success"] = success;
                response["message"] = success ? "Seeds purchased!" : "Failed to buy";
                response["output"] = output;
            }
            else if (target == "/api/plant") {
                std::string plant = std::string(data["plant"].as_string().c_str());
                int space = static_cast<int>(data["space"].as_int64());
                int box = static_cast<int>(data["box"].as_int64());
                bool success = game_->plantSeed(plant, space, box);
                std::string output = capture.getString();
                response["success"] = success;
                response["message"] = success ? "Plant queued!" : "Failed to queue - check space/box exists";
                response["output"] = output;
            }
            else if (target == "/api/execute") {
                game_->executeCommands();
                std::string output = capture.getString();
                response["message"] = "Commands executed!";
                response["output"] = output;
            }
            else if (target == "/api/water") {
                int space = static_cast<int>(data["space"].as_int64());
                int box = static_cast<int>(data["box"].as_int64());
                bool success = game_->waterPlants(space, box);
                std::string output = capture.getString();
                response["success"] = success;
                if (!success) {
                    response["message"] = "Failed - check: space exists, resources available, balance >= R1";
                } else {
                    response["message"] = "Water queued!";
                }
                response["output"] = output;
            }
            else if (target == "/api/fertilize") {
                int space = static_cast<int>(data["space"].as_int64());
                int box = static_cast<int>(data["box"].as_int64());
                bool success = game_->fertilizePlants(space, box);
                std::string output = capture.getString();
                response["success"] = success;
                if (!success) {
                    response["message"] = "Failed - check: space exists, fertilizer available, balance >= R3";
                } else {
                    response["message"] = "Fertilize queued!";
                }
                response["output"] = output;
            }
            else if (target == "/api/refill") {
                bool success = game_->refillResources();
                std::string output = capture.getString();
                response["success"] = success;
                response["message"] = success ? "Resources refilled!" : "Insufficient funds (need R50)";
                response["output"] = output;
            }
            else if (target == "/api/strategy") {
                int strategy = static_cast<int>(data["strategy"].as_int64());
                game_->changeWateringStrategy(strategy);
                std::string output = capture.getString();
                response["message"] = "Strategy changed!";
                response["output"] = output;
            }
            else if (target == "/api/hire") {
                int type = static_cast<int>(data["type"].as_int64());
                bool success = game_->hireStaff(type);
                std::string output = capture.getString();
                response["success"] = success;
                response["message"] = success ? "Staff hired!" : "Insufficient funds";
                response["output"] = output;
            }
            else if (target == "/api/customer") {
                game_->triggerCustomerVisit();
                std::string output = capture.getString();
                response["message"] = "Customer visited!";
                response["output"] = output;
            }
            else if (target == "/api/advance") {
                game_->advanceDay();
                std::string output = capture.getString();
                response["message"] = "Day advanced!";
                response["output"] = output;
            }
            else if (target == "/api/health") {
                game_->performHealthCheck();
                std::string output = capture.getString();
                response["message"] = "Health check complete!";
                response["output"] = output;
            }
            else if (target == "/api/iterator") {
                game_->useIterator();
                std::string output = capture.getString();
                response["message"] = "Iterator demonstration complete!";
                response["output"] = output;
            }
            else if (target == "/api/status") {
                try {
                    response["day"] = game_->getDayCounter();
                    response["balance"] = game_->getBalance();
                    response["plants"] = game_->getTotalPlants();
                    response["happiness"] = game_->getHappinessScore();
                    response["waterLevel"] = game_->getWaterLevel();
                    response["waterCapacity"] = game_->getWaterCapacity();
                    response["fertLevel"] = game_->getFertilizerLevel();
                    response["fertCapacity"] = game_->getFertilizerCapacity();
                    response["readyPlants"] = game_->getReadyPlantsCount();
                } catch (std::exception& e) {
                    std::cerr << "Status retrieval error: " << e.what() << std::endl;
                }
            }
            else if (target == "/api/viewSpaces") {
                game_->viewAllSpaces();
                std::string output = capture.getString();
                response["message"] = "Spaces information retrieved";
                response["output"] = output;
            }
            else if (target == "/api/viewInventory") {
                json::object inventory;
                inventory["Rose"] = game_->getInventoryStock("Rose");
                inventory["Tulip"] = game_->getInventoryStock("Tulip");
                inventory["Lawn Grass"] = game_->getInventoryStock("Lawn Grass");
                inventory["Basil"] = game_->getInventoryStock("Basil");
                inventory["Mint"] = game_->getInventoryStock("Mint");
                response["inventory"] = inventory;
                
                game_->viewInventoryStock();
                std::string output = capture.getString();
                response["output"] = output;
                response["message"] = "Inventory loaded";
            }
            else if (target == "/api/viewOrders") {
                game_->viewOrders();
                std::string output = capture.getString();
                response["orderCount"] = game_->getOrderCount();
                response["message"] = std::to_string(game_->getOrderCount()) + " orders completed";
                response["output"] = output;
            }
            else if (target == "/api/viewResources") {
                game_->viewResources();
                std::string output = capture.getString();
                response["message"] = "Resources displayed";
                response["output"] = output;
            }
            else if (target == "/api/bankLog") {
                game_->viewBankLog();
                std::string output = capture.getString();
                response["message"] = "Bank log displayed";
                response["output"] = output;
            }
            else if (target == "/api/gameStatus") {
                game_->displayGameStatus();
                std::string output = capture.getString();
                response["message"] = "Game status displayed";
                response["output"] = output;
            }
            else if (target == "/api/reset") {
                game_->initialize();
                std::string output = capture.getString();
                response["message"] = "Game reset!";
                response["output"] = output;
            }
            else {
                response["error"] = "Unknown endpoint";
            }
            
        } catch (std::exception& e) {
            std::cerr << "API error: " << e.what() << std::endl;
            response["error"] = std::string("Request processing failed: ") + e.what();
        }
        
        send_response(http::status::ok, json::serialize(response), "application/json");
    }

    void send_response(http::status status, const std::string& body, 
                      const std::string& content_type = "text/plain") {
        try {
            auto self = shared_from_this();
            auto res = std::make_shared<http::response<http::string_body>>();
            res->result(status);
            res->version(request_.version());
            res->set(http::field::server, "Nursery Manager");
            res->set(http::field::content_type, content_type);
            res->set(http::field::access_control_allow_origin, "*");
            res->keep_alive(false);
            res->body() = body;
            res->prepare_payload();

            http::async_write(socket_, *res,
                [self, res](beast::error_code ec, std::size_t) {
                    if (ec && ec != beast::http::error::end_of_stream) {
                        std::cerr << "Write error: " << ec.message() << std::endl;
                    }
                    beast::error_code shutdown_ec;
                    self->socket_.shutdown(tcp::socket::shutdown_send, shutdown_ec);
                });
        } catch (std::exception& e) {
            std::cerr << "Response error: " << e.what() << std::endl;
        }
    }
};

class WebServer {
    net::io_context& ioc_;
    tcp::acceptor acceptor_;

public:
    WebServer(net::io_context& ioc, unsigned short port)
        : ioc_(ioc), acceptor_(ioc, {tcp::v4(), port}) {
        
        std::cout << "\n========================================" << std::endl;
        std::cout << "  Nursery Manager Web Server" << std::endl;
        std::cout << "========================================\n" << std::endl;
        
        std::cout << "Initializing game..." << std::endl;
        try {
            Game* game = Game::getInstance();
            game->initialize();
            std::cout << "✓ Game initialized successfully!" << std::endl;
        } catch (std::exception& e) {
            std::cerr << "✗ Game initialization error: " << e.what() << std::endl;
            throw;
        }
        
        std::cout << "\n========================================" << std::endl;
        std::cout << "  Server: http://localhost:" << port << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "\n✓ Server running. Press Ctrl+C to stop.\n" << std::endl;
        
        accept();
    }

private:
    void accept() {
        acceptor_.async_accept(
            [this](beast::error_code ec, tcp::socket socket) {
                if (!ec) {
                    std::make_shared<GameSession>(std::move(socket))->run();
                } else {
                    std::cerr << "Accept error: " << ec.message() << std::endl;
                }
                accept();
            });
    }
};

std::string get_html_content() {
    return 
"<!DOCTYPE html>\n"
"<html>\n"
"<head>\n"
"<meta charset=\"UTF-8\">\n"
"<title>Nursery Manager</title>\n"
"<style>\n"
"* { margin: 0; padding: 0; box-sizing: border-box; }\n"
"body { font-family: 'Segoe UI', Arial, sans-serif; background: #f0f4f0; }\n"
".header { background: linear-gradient(135deg, #2d5016 0%, #4a7c2d 100%); color: white; padding: 20px; box-shadow: 0 2px 10px rgba(0,0,0,0.1); }\n"
".header h1 { font-size: 28px; margin-bottom: 10px; }\n"
".stats { display: flex; gap: 30px; font-size: 14px; flex-wrap: wrap; }\n"
".stat { background: rgba(255,255,255,0.1); padding: 8px 15px; border-radius: 5px; }\n"
".container { max-width: 1400px; margin: 20px auto; padding: 0 20px; }\n"
".grid { display: grid; grid-template-columns: repeat(auto-fit, minmax(350px, 1fr)); gap: 20px; margin-bottom: 20px; }\n"
".panel { background: white; border-radius: 8px; padding: 20px; box-shadow: 0 2px 8px rgba(0,0,0,0.1); }\n"
".panel h2 { font-size: 18px; margin-bottom: 15px; color: #2d5016; border-bottom: 2px solid #e0e0e0; padding-bottom: 10px; }\n"
".btn { background: #4a7c2d; color: white; border: none; padding: 10px 20px; border-radius: 5px; cursor: pointer; font-size: 14px; margin: 5px; transition: all 0.2s; }\n"
".btn:hover { background: #3a6220; transform: translateY(-1px); }\n"
".btn:active { transform: translateY(0); }\n"
".btn-secondary { background: #6b9b4e; }\n"
".btn-secondary:hover { background: #5a8440; }\n"
".btn-danger { background: #c44; }\n"
".btn-danger:hover { background: #a33; }\n"
".btn-small { padding: 6px 12px; font-size: 12px; }\n"
"input, select { padding: 8px; border: 1px solid #ddd; border-radius: 4px; margin: 5px; font-size: 14px; }\n"
".input-group { display: flex; gap: 5px; align-items: center; margin: 10px 0; flex-wrap: wrap; }\n"
".input-group label { font-size: 13px; color: #666; min-width: 80px; }\n"
".resource-bar { background: #e0e0e0; border-radius: 10px; height: 20px; margin: 10px 0; overflow: hidden; }\n"
".resource-fill { background: linear-gradient(90deg, #4a7c2d 0%, #6b9b4e 100%); height: 100%; transition: width 0.3s; display: flex; align-items: center; justify-center; color: white; font-size: 12px; font-weight: bold; }\n"
".log { background: #f9f9f9; border: 1px solid #e0e0e0; border-radius: 5px; padding: 15px; max-height: 500px; overflow-y: auto; font-family: 'Courier New', monospace; font-size: 12px; line-height: 1.6; }\n"
".log-entry { padding: 8px; margin: 4px 0; border-left: 3px solid #4a7c2d; background: white; white-space: pre-wrap; word-wrap: break-word; }\n"
".log-entry.detailed { background: #f0f8ff; border-left-color: #2d5016; font-size: 11px; }\n"
".modal { display: none; position: fixed; z-index: 1000; left: 0; top: 0; width: 100%; height: 100%; background: rgba(0,0,0,0.5); }\n"
".modal-content { background: white; margin: 5% auto; padding: 30px; border-radius: 10px; width: 80%; max-width: 600px; max-height: 70vh; overflow-y: auto; box-shadow: 0 4px 20px rgba(0,0,0,0.3); }\n"
".modal-header { display: flex; justify-content: space-between; align-items: center; margin-bottom: 20px; padding-bottom: 15px; border-bottom: 2px solid #e0e0e0; }\n"
".modal-header h2 { margin: 0; color: #2d5016; }\n"
".close { font-size: 28px; font-weight: bold; cursor: pointer; color: #999; }\n"
".close:hover { color: #333; }\n"
".inventory-grid { display: grid; grid-template-columns: 2fr 1fr; gap: 10px; margin-top: 15px; }\n"
".inventory-item { padding: 10px; background: #f9f9f9; border-radius: 5px; display: flex; justify-content: space-between; align-items: center; }\n"
".inventory-item strong { color: #2d5016; }\n"
".help-text { font-size: 12px; color: #666; margin: 5px 0; padding: 5px; background: #f9f9f9; border-radius: 3px; }\n"
"@media (max-width: 768px) { .grid { grid-template-columns: 1fr; } }\n"
"</style>\n"
"</head>\n"
"<body>\n"
"<div class=\"header\">\n"
"<h1>🌱 Nursery Manager</h1>\n"
"<div class=\"stats\">\n"
"<div class=\"stat\">Day: <span id=\"day\">0</span></div>\n"
"<div class=\"stat\">Balance: R<span id=\"balance\">1000</span></div>\n"
"<div class=\"stat\">Plants: <span id=\"plants\">0</span></div>\n"
"<div class=\"stat\">Ready: <span id=\"ready\">0</span></div>\n"
"<div class=\"stat\">Happiness: <span id=\"happiness\">100</span>/100</div>\n"
"</div></div>\n"
"<div class=\"container\">\n"
"<div class=\"grid\">\n"
"<div class=\"panel\"><h2>🏗️ Building & Viewing</h2>\n"
"<button class=\"btn\" onclick=\"buildSpace(1)\">Build Small (R50)</button>\n"
"<button class=\"btn\" onclick=\"buildSpace(2)\">Build Medium (R80)</button>\n"
"<button class=\"btn\" onclick=\"buildSpace(3)\">Build Big (R120)</button>\n"
"<button class=\"btn btn-secondary\" onclick=\"viewSpaces()\">View Spaces</button>\n"
"<button class=\"btn btn-secondary\" onclick=\"viewInventory()\">View Inventory</button>\n"
"<button class=\"btn btn-secondary\" onclick=\"viewOrders()\">View Orders</button>\n"
"<button class=\"btn btn-secondary\" onclick=\"viewResources()\">View Resources</button>\n"
"<button class=\"btn btn-secondary\" onclick=\"bankLog()\">Bank Log</button>\n"
"</div>\n"
"<div class=\"panel\"><h2>🌱 Plant Operations</h2>\n"
"<div class=\"help-text\">💡 First: Build space → Buy seeds → Plant → Execute</div>\n"
"<div><select id=\"plantType\">\n"
"<option value=\"Rose\">Rose (R8)</option>\n"
"<option value=\"Tulip\">Tulip (R6)</option>\n"
"<option value=\"Lawn Grass\">Lawn Grass (R4)</option>\n"
"<option value=\"Basil\">Basil (R5)</option>\n"
"<option value=\"Mint\">Mint (R5)</option>\n"
"</select>\n"
"<input type=\"number\" id=\"seedQty\" placeholder=\"Qty\" min=\"1\" value=\"5\" style=\"width: 60px;\">\n"
"<button class=\"btn\" onclick=\"buySeeds()\">Buy Seeds</button></div>\n"
"<div class=\"help-text\">📍 Space 0 = first space built, Box 0-9 = box index</div>\n"
"<div class=\"input-group\">\n"
"<input type=\"number\" id=\"spaceIdx\" placeholder=\"Space (0, 1, 2...)\" min=\"0\" value=\"0\" style=\"width: 150px;\">\n"
"<input type=\"number\" id=\"boxIdx\" placeholder=\"Box (0-9)\" min=\"0\" max=\"9\" value=\"0\" style=\"width: 100px;\">\n"
"</div>\n"
"<button class=\"btn\" onclick=\"plantSeed()\">🌱 Plant</button>\n"
"<button class=\"btn btn-secondary\" onclick=\"executeCommands()\">⚡ Execute All</button>\n"
"</div>\n"
"<div class=\"panel\"><h2>💧 Plant Care</h2>\n"
"<div class=\"help-text\">🎯 Use same Space/Box values from Plant Operations</div>\n"
"<div class=\"input-group\">\n"
"<button class=\"btn\" onclick=\"waterPlants()\">💧 Water (R1)</button>\n"
"<button class=\"btn\" onclick=\"fertilizePlants()\">🌿 Fertilize (R3)</button>\n"
"</div>\n"
"<div style=\"margin-top: 10px;\">\n"
"<select id=\"strategy\">\n"
"<option value=\"2\">Intermediate (3💧)</option>\n"
"<option value=\"1\">Light (1💧)</option>\n"
"<option value=\"3\">Heavy (5💧)</option>\n"
"</select>\n"
"<button class=\"btn btn-secondary btn-small\" onclick=\"changeStrategy()\">Set Strategy</button>\n"
"</div>\n"
"</div>\n"
"</div>\n"
"<div class=\"grid\">\n"
"<div class=\"panel\"><h2>💧 Resources</h2>\n"
"<div>Water: <span id=\"waterLevel\">1000</span>/<span id=\"waterCap\">1000</span></div>\n"
"<div class=\"resource-bar\"><div class=\"resource-fill\" id=\"waterBar\" style=\"width: 100%\">100%</div></div>\n"
"<div>Fertilizer: <span id=\"fertLevel\">500</span>/<span id=\"fertCap\">500</span></div>\n"
"<div class=\"resource-bar\"><div class=\"resource-fill\" id=\"fertBar\" style=\"width: 100%\">100%</div></div>\n"
"<button class=\"btn\" onclick=\"refillResources()\">Refill All (R50)</button>\n"
"</div>\n"
"<div class=\"panel\"><h2>👥 Staff & Customers</h2>\n"
"<button class=\"btn\" onclick=\"hireStaff(1)\">Hire Sales (R100)</button>\n"
"<button class=\"btn\" onclick=\"hireStaff(2)\">Hire Cashier (R80)</button>\n"
"<button class=\"btn btn-secondary\" onclick=\"triggerCustomer()\">👤 Customer Visit</button>\n"
"<div class=\"help-text\">⚠️ Need staff + ready plants to sell!</div>\n"
"</div>\n"
"<div class=\"panel\"><h2>⏰ Time & Analysis</h2>\n"
"<button class=\"btn\" onclick=\"advanceDay()\">📅 Advance Day</button>\n"
"<button class=\"btn btn-secondary\" onclick=\"healthCheck()\">🏥 Health Check</button>\n"
"<button class=\"btn btn-secondary\" onclick=\"useIterator()\">🔄 Iterator</button>\n"
"<button class=\"btn btn-secondary\" onclick=\"gameStatus()\">📊 Game Status</button>\n"
"<button class=\"btn btn-danger\" onclick=\"resetGame()\">🔄 Reset Game</button>\n"
"</div>\n"
"</div>\n"
"<div class=\"panel\"><h2>📜 Game Output</h2>\n"
"<div class=\"log\" id=\"gameLog\"></div></div></div>\n"
"<div id=\"inventoryModal\" class=\"modal\">\n"
"<div class=\"modal-content\">\n"
"<div class=\"modal-header\"><h2>🌱 Inventory Stock</h2><span class=\"close\" onclick=\"closeModal()\">&times;</span></div>\n"
"<div id=\"inventoryContent\"></div>\n"
"</div></div>\n"
"<script>\n"
"function log(msg, detailed=false){var e=document.getElementById('gameLog'),d=document.createElement('div');d.className=detailed?'log-entry detailed':'log-entry';d.textContent=msg;e.insertBefore(d,e.firstChild);while(e.children.length>100)e.removeChild(e.lastChild);}\n"
"function showModal(){document.getElementById('inventoryModal').style.display='block';}\n"
"function closeModal(){document.getElementById('inventoryModal').style.display='none';}\n"
"window.onclick=function(e){if(e.target.className==='modal'){closeModal();}}\n"
"function updateStats(){fetch('/api/status',{method:'POST',body:'{}'}).then(r=>r.json()).then(d=>{document.getElementById('day').textContent=d.day||0;document.getElementById('balance').textContent=d.balance||0;document.getElementById('plants').textContent=d.plants||0;document.getElementById('ready').textContent=d.readyPlants||0;document.getElementById('happiness').textContent=d.happiness||100;var wl=d.waterLevel||1000,wc=d.waterCapacity||1000,fl=d.fertLevel||500,fc=d.fertCapacity||500;var wp=(wl/wc*100).toFixed(0),fp=(fl/fc*100).toFixed(0);document.getElementById('waterLevel').textContent=wl;document.getElementById('waterCap').textContent=wc;document.getElementById('fertLevel').textContent=fl;document.getElementById('fertCap').textContent=fc;document.getElementById('waterBar').style.width=wp+'%';document.getElementById('waterBar').textContent=wp+'%';document.getElementById('fertBar').style.width=fp+'%';document.getElementById('fertBar').textContent=fp+'%';}).catch(e=>log('Status update failed: '+e));}\n"
"function apiCall(e,d={}){return fetch('/api/'+e,{method:'POST',headers:{'Content-Type':'application/json'},body:JSON.stringify(d)}).then(r=>r.json()).then(r=>{var ts=new Date().toLocaleTimeString();if(r.output&&r.output.trim()){log('['+ts+'] '+r.message,false);log(r.output,true);}else{log('['+ts+'] '+(r.message||r.error||'Action completed'),false);}updateStats();return r;}).catch(e=>{log('Error: '+e,false);throw e;});}\n"
"function buildSpace(t){apiCall('build',{type:t});}\n"
"function buySeeds(){var p=document.getElementById('plantType').value,q=parseInt(document.getElementById('seedQty').value);apiCall('buySeeds',{plant:p,qty:q});}\n"
"function plantSeed(){var p=document.getElementById('plantType').value,s=parseInt(document.getElementById('spaceIdx').value),b=parseInt(document.getElementById('boxIdx').value);apiCall('plant',{plant:p,space:s,box:b});}\n"
"function executeCommands(){apiCall('execute',{});}\n"
"function waterPlants(){var s=parseInt(document.getElementById('spaceIdx').value),b=parseInt(document.getElementById('boxIdx').value);apiCall('water',{space:s,box:b});}\n"
"function fertilizePlants(){var s=parseInt(document.getElementById('spaceIdx').value),b=parseInt(document.getElementById('boxIdx').value);apiCall('fertilize',{space:s,box:b});}\n"
"function refillResources(){apiCall('refill',{});}\n"
"function changeStrategy(){var s=parseInt(document.getElementById('strategy').value);apiCall('strategy',{strategy:s});}\n"
"function hireStaff(t){apiCall('hire',{type:t});}\n"
"function triggerCustomer(){apiCall('customer',{});}\n"
"function advanceDay(){apiCall('advance',{});}\n"
"function healthCheck(){apiCall('health',{});}\n"
"function useIterator(){apiCall('iterator',{});}\n"
"function gameStatus(){apiCall('gameStatus',{});}\n"
"function viewSpaces(){apiCall('viewSpaces',{});}\n"
"function viewResources(){apiCall('viewResources',{});}\n"
"function bankLog(){apiCall('bankLog',{});}\n"
"function viewInventory(){apiCall('viewInventory',{}).then(r=>{if(r.inventory){var html='<div class=\"inventory-grid\">';for(var p in r.inventory){html+='<div class=\"inventory-item\"><strong>'+p+'</strong><span>'+r.inventory[p]+' seeds</span></div>';}html+='</div>';document.getElementById('inventoryContent').innerHTML=html;showModal();}});}\n"
"function viewOrders(){apiCall('viewOrders',{});}\n"
"function resetGame(){if(confirm('Reset game? All progress will be lost.')){apiCall('reset',{});}}\n"
"setTimeout(updateStats,1000);setInterval(updateStats,5000);\n"
"log('🌱 Welcome to Nursery Manager!',false);\n"
"log('Quick Start: 1) Build Space → 2) Buy Seeds → 3) Plant → 4) Execute → 5) Advance Days → 6) Sell!',false);\n"
"</script>\n"
"</body>\n"
"</html>";
}

int main() {
    try {
        std::cout << "Starting Nursery Manager Web Server..." << std::endl;
        
        net::io_context ioc{1};
        WebServer server(ioc, 8080);
        
        ioc.run();
    } catch (std::exception& e) {
        std::cerr << "\n✗ Fatal error: " << e.what() << std::endl;
        std::cerr << "\nTroubleshooting:" << std::endl;
        std::cerr << "  1. Check that port 8080 is not in use" << std::endl;
        std::cerr << "  2. Ensure Boost libraries are installed" << std::endl;
        std::cerr << "  3. Check that all Game components are properly initialized" << std::endl;
        return 1;
    }
    return 0;
}