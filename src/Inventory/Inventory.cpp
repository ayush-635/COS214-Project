#include "Inventory.h"
#include <iostream>
#include "../PlantFactory/PlantFactory.h"
#include"../Plant/Plant.h"

Inventory* Inventory::instance = 0;

Inventory::Inventory() : factory(0) {
}

Inventory::~Inventory(){
	std::map<std::string, Plant*>::iterator it = protoByName.begin();
	for(; it != protoByName.end(); ++it){
		delete it->second;
		it->second = 0;
	}
	protoByName.clear();
}

Inventory* Inventory::getInstance(){
	if (!instance){
		instance = new Inventory();
	}
	return instance;
}

void Inventory::setFactory(PlantFactory* f){
	factory = f;
}

Plant* Inventory::ensurePrototype(const std::string& name){
	std::map<std::string, Plant*>::iterator it = protoByName.find(name);
	if(it != protoByName.end()){
		return it->second;
	}
	if(!factory){
		return NULL;
	}

	std::map<std::string, Plant*>& protos = factory->getPlantPrototypes();
	std::map<std::string, Plant*>::iterator pit = protos.find(name);
	Plant* p = NULL;

	if(pit != protos.end() && pit->second){
		p = pit->second->clone();
	}else{
		p = factory->createPlant(name);
	}

	if(p){
		protoByName[name] = p;
	}

	return p;
}

void Inventory::addStockType(PlantFactory* f,const std::string name,const std::string idealSeason) {
	if(qtyByName.find(name) == qtyByName.end()){
		qtyByName[name] = 0;
	}

	idealSeasonByName[name] = idealSeason;

	if(f){
		factory = f;
	}
	
	ensurePrototype(name);
}

int Inventory::getStock(const std::string& name) const{
	std::map<std::string, int>::const_iterator it = qtyByName.find(name);
	return (it != qtyByName.end()) ? it->second : 0;
}

void Inventory::updateStock(const std::string& name, int count) {
	int current = getStock(name);
	int next = current + count;
	if(next < 0){
		next = 0;
	}

	qtyByName[name] = next;

	Plant* p = getPrototype(name);
	if(!p){
		p = ensurePrototype(name);
	}
	if(p){
		notifyStockChange(p);
	}
}

bool Inventory::trySell(const std::string& name, int qty){
	if(qty <= 0){
		return true;
	}
	int current = getStock(name);
	if(current < qty){
		return false;
	}
	updateStock(name, -qty);
	return true;
}

void Inventory::restock(const std::string& name, int qty){
	if(qty > 0){
		updateStock(name, qty);
	}
}

Plant* Inventory::getPrototype(const std::string& name) const{
	std::map<std::string, Plant*>::const_iterator it = protoByName.find(name);
	return(it != protoByName.end()) ? it->second : NULL;
}

std::string Inventory::getIdealSeason(const std::string& name) const {
    std::map<std::string, std::string>::const_iterator it = idealSeasonByName.find(name);
    return (it != idealSeasonByName.end()) ? it->second : std::string();
}