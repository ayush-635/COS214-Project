# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I. -Itests
WEB_LDFLAGS = -lboost_system -lboost_json -pthread

# Directories
SRC_DIR = src
TEST_DIR = tests

# Source files - ALL CPP FILES INCLUDING STAFF/CUSTOMER SYSTEM
SOURCES = main.cpp \
          $(SRC_DIR)/SpaceBuilder/SpaceBuilder.cpp \
          $(SRC_DIR)/ConcreteSpaceBuilder/ConcreteSpaceBuilder.cpp \
          $(SRC_DIR)/NurseryManager/NurseryManager.cpp \
          $(SRC_DIR)/PlanterBox/PlanterBox.cpp \
          $(SRC_DIR)/PlanterBoxCollection/PlanterBoxCollection.cpp \
          $(SRC_DIR)/Plant/Plant.cpp \
          $(SRC_DIR)/PlantData/PlantData.cpp \
          $(SRC_DIR)/PlantState/PlantState.cpp \
          $(SRC_DIR)/Seedling/Seedling.cpp \
          $(SRC_DIR)/Growing/Growing.cpp \
          $(SRC_DIR)/Mature/Mature.cpp \
          $(SRC_DIR)/ReadyToSell/ReadyToSell.cpp \
          $(SRC_DIR)/Dying/Dying.cpp \
          $(SRC_DIR)/Dead/Dead.cpp \
          $(SRC_DIR)/PlantDataFactory/PlantDataFactory.cpp \
          $(SRC_DIR)/FlowerFactory/FlowerFactory.cpp \
          $(SRC_DIR)/GrassFactory/GrassFactory.cpp \
          $(SRC_DIR)/HerbFactory/HerbFactory.cpp \
          $(SRC_DIR)/TreePlant/TreePlant.cpp \
          $(SRC_DIR)/SucculentFactory/SucculentFactory.cpp \
          $(SRC_DIR)/FlowerPlant/FlowerPlant.cpp \
          $(SRC_DIR)/SucculentPlant/SucculentPlant.cpp \
          $(SRC_DIR)/GrassPlant/GrassPlant.cpp \
          $(SRC_DIR)/HerbPlant/HerbPlant.cpp \
          $(SRC_DIR)/Iterator/Iterator.cpp \
          $(SRC_DIR)/PlantIterator/PlantIterator.cpp \
          $(SRC_DIR)/PlantFactory/PlantFactory.cpp \
          $(SRC_DIR)/HealthCheckVisitor/HealthCheckVisitor.cpp \
          $(SRC_DIR)/WaterPlantCommand/WaterPlantCommand.cpp \
          $(SRC_DIR)/GiveFertilizerCommand/GiveFertilizerCommand.cpp \
          $(SRC_DIR)/PlantSeedCommand/PlantSeedCommand.cpp \
          $(SRC_DIR)/RemovePlantCommand/RemovePlantCommand.cpp \
          $(SRC_DIR)/LightWateringStrategy/LightWateringStrategy.cpp \
          $(SRC_DIR)/IntermediateWateringStrategy/IntermediateWateringStrategy.cpp \
          $(SRC_DIR)/WateringStrategy/WateringStrategy.cpp \
          $(SRC_DIR)/HeavyWateringStrategy/HeavyWateringStrategy.cpp \
          $(SRC_DIR)/CareForPlantCommand/CareForPlantCommand.cpp \
          $(SRC_DIR)/Duty/Duty.cpp \
          $(SRC_DIR)/BankAccount/BankAccount.cpp \
          $(SRC_DIR)/BuyAssetsCommand/BuyAssetsCommand.cpp \
          $(SRC_DIR)/SaleCommand/SaleCommand.cpp \
          $(SRC_DIR)/TransactionCommand/TransactionCommand.cpp \
          $(SRC_DIR)/TransactionManager/TransactionManager.cpp \
          $(SRC_DIR)/Order/Order.cpp \
          $(SRC_DIR)/OrderItem/OrderItem.cpp \
          $(SRC_DIR)/Pot/Pot.cpp \
          $(SRC_DIR)/Mediator/Mediator.cpp \
          $(SRC_DIR)/Colleague/Colleague.cpp \
          $(SRC_DIR)/InteractionManager/InteractionManager.cpp \
          $(SRC_DIR)/StaffMember/StaffMember.cpp \
          $(SRC_DIR)/Sales/Sales.cpp \
          $(SRC_DIR)/Cashier/Cashier.cpp \
          $(SRC_DIR)/Customer/Customer.cpp \
          $(SRC_DIR)/Pathologist/Pathologist.cpp \
          $(SRC_DIR)/Gardner/Gardner.cpp \
          $(SRC_DIR)/Inventory/Inventory.cpp \
          $(SRC_DIR)/Subject/Subject.cpp \
          $(SRC_DIR)/InventoryObserver/InventoryObserver.cpp \
          $(SRC_DIR)/DeliveryStrategy/DeliveryStrategy.cpp \
          $(SRC_DIR)/ExpressDelivery/ExpressDelivery.cpp \
          $(SRC_DIR)/PickupDelivery/PickupDelivery.cpp \
          $(SRC_DIR)/StandardDelivery/StandardDelivery.cpp \
          $(SRC_DIR)/ResourceManager/ResourceManager.cpp \
          $(SRC_DIR)/Game/Game.cpp

# Test files (in tests/ directory)
TEST_SOURCES = $(TEST_DIR)/test_main.cpp \
               $(TEST_DIR)/test_Plants.cpp \
               $(TEST_DIR)/test_bankAccount.cpp \
               $(TEST_DIR)/test_composite_simple.cpp \
               $(TEST_DIR)/test_DyingState.cpp \
               $(TEST_DIR)/test_Game.cpp \
               $(TEST_DIR)/test_order.cpp \
               $(TEST_DIR)/test_orderitem.cpp \
               $(TEST_DIR)/test_PlantData.cpp \
               $(TEST_DIR)/test_PlantStates.cpp \
               $(TEST_DIR)/test_Prototypes.cpp \
               $(TEST_DIR)/test_transaction_manager.cpp \
               $(TEST_DIR)/test_Visitors.cpp \
               $(TEST_DIR)/ObserverTestMain.cpp \
               $(TEST_DIR)/test_Builder.cpp \
               $(TEST_DIR)/test_DeliveryStrategy.cpp \
               $(TEST_DIR)/StaffCreationTestMain.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)

# Filter out main.o for tests and web server
MAIN_OBJ = main.o
BASE_OBJECTS = $(filter-out $(MAIN_OBJ), $(OBJECTS))
TEST_BASE_OBJECTS = $(BASE_OBJECTS)

# Executable names
TARGET = nursery_game
WEB_TARGET = webserver
TEST_TARGETS = test_Plants test_bankAccount test_composite_simple test_DyingState test_Game test_order test_orderitem test_PlantData test_PlantStates test_Prototypes test_transaction_manager test_Visitors test_Builder test_DeliveryStrategy ObserverTestMain StaffCreationTestMain

# Doctest configuration
DOCTEST_HEADER = tests/doctest.h

# Default target - build both console and web versions
all: $(TARGET) $(WEB_TARGET)
	@echo "============================================"
	@echo "Build complete!"
	@echo "  Console version: ./$(TARGET)"
	@echo "  Web version: ./$(WEB_TARGET)"
	@echo "============================================"

# Link object files to create console executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "✅ Console version built: ./$(TARGET)"

# Build web server executable
$(WEB_TARGET): WebServer.cpp $(BASE_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(WEB_TARGET) WebServer.cpp $(BASE_OBJECTS) $(WEB_LDFLAGS)
	@echo "✅ Web version built: ./$(WEB_TARGET)"
	@echo "   Run with: ./$(WEB_TARGET)"
	@echo "   Then open: http://localhost:8080"

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile test files from tests directory
$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp $(DOCTEST_HEADER)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build only console version
console: $(TARGET)
	@echo "Console version ready: ./$(TARGET)"

# Build only web version
web: $(WEB_TARGET)
	@echo "Web version ready: ./$(WEB_TARGET)"
	@echo "Run with: ./$(WEB_TARGET)"
	@echo "Then open: http://localhost:8080"

# Run console version
run: $(TARGET)
	./$(TARGET)

# Run web server
run-web: $(WEB_TARGET)
	@echo "Starting web server on http://localhost:8080"
	@echo "Press Ctrl+C to stop"
	./$(WEB_TARGET)

# Test targets
test: $(TEST_TARGETS)
	@echo "============================================"
	@echo "Running all tests..."
	@echo "============================================"
	@for test in $(TEST_TARGETS); do \
		if [ -f "./$$test" ]; then \
			echo "=== Running $$test ==="; \
			./$$test || echo "$$test failed ❌"; \
			echo ""; \
		else \
			echo "❌ $$test not found"; \
		fi \
	done
	@echo "============================================"
	@echo "Test run completed!"
	@echo "============================================"

# Individual test executables
test_Plants: $(TEST_DIR)/test_main.o $(TEST_DIR)/test_Plants.o $(TEST_BASE_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

test_bankAccount: $(TEST_DIR)/test_main.o $(TEST_DIR)/test_bankAccount.o $(TEST_BASE_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

test_composite_simple: $(TEST_DIR)/test_main.o $(TEST_DIR)/test_composite_simple.o $(TEST_BASE_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

test_DyingState: $(TEST_DIR)/test_main.o $(TEST_DIR)/test_DyingState.o $(TEST_BASE_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

test_Game: $(TEST_DIR)/test_main.o $(TEST_DIR)/test_Game.o $(TEST_BASE_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

test_order: $(TEST_DIR)/test_main.o $(TEST_DIR)/test_order.o $(TEST_BASE_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

test_orderitem: $(TEST_DIR)/test_main.o $(TEST_DIR)/test_orderitem.o $(TEST_BASE_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

test_PlantData: $(TEST_DIR)/test_main.o $(TEST_DIR)/test_PlantData.o $(TEST_BASE_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

test_PlantStates: $(TEST_DIR)/test_main.o $(TEST_DIR)/test_PlantStates.o $(TEST_BASE_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

test_Prototypes: $(TEST_DIR)/test_main.o $(TEST_DIR)/test_Prototypes.o $(TEST_BASE_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

test_transaction_manager: $(TEST_DIR)/test_main.o $(TEST_DIR)/test_transaction_manager.o $(TEST_BASE_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

test_Visitors: $(TEST_DIR)/test_main.o $(TEST_DIR)/test_Visitors.o $(TEST_BASE_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

test_Builder: $(TEST_DIR)/test_main.o $(TEST_DIR)/test_Builder.o $(TEST_BASE_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

test_DeliveryStrategy: $(TEST_DIR)/test_main.o $(TEST_DIR)/test_DeliveryStrategy.o $(TEST_BASE_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

ObserverTestMain: $(TEST_DIR)/ObserverTestMain.o $(TEST_BASE_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

StaffCreationTestMain: $(TEST_DIR)/StaffCreationTestMain.o $(TEST_BASE_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Test categories
test_plants: test_Plants test_PlantData test_PlantStates test_Prototypes
	@echo "=== Running Plant Tests ==="
	@for test in $^; do \
		if [ -f "./$$test" ]; then \
			echo "Running $$test..."; \
			./$$test || echo "$$test failed ❌"; \
		fi \
	done

test_patterns: test_Visitors test_transaction_manager test_composite_simple
	@echo "=== Running Pattern Tests ==="
	@for test in $^; do \
		if [ -f "./$$test" ]; then \
			echo "Running $$test..."; \
			./$$test || echo "$$test failed ❌"; \
		fi \
	done

test_integration: test_Game test_DyingState ObserverTestMain StaffCreationTestMain test_bankAccount
	@echo "=== Running Integration Tests ==="
	@for test in $^; do \
		if [ -f "./$$test" ]; then \
			echo "Running $$test..."; \
			./$$test || echo "$$test failed ❌"; \
		fi \
	done

# Clean build artifacts
clean:
	rm -f $(OBJECTS) $(TARGET) $(WEB_TARGET) $(TEST_OBJECTS) $(TEST_TARGETS)
	@echo "Clean complete! All objects and executables removed."

# Rebuild everything
rebuild: clean all

# Debug build with symbols
debug: CXXFLAGS += -g -DDEBUG
debug: rebuild

# Check for missing source files
check:
	@echo "Checking for source files..."
	@for src in $(SOURCES); do \
		if [ ! -f $$src ]; then \
			echo "❌ Missing: $$src"; \
		fi \
	done
	@if [ -f "WebServer.cpp" ]; then \
		echo "✅ WebServer.cpp found"; \
	else \
		echo "❌ Missing: WebServer.cpp"; \
	fi
	@echo "Check complete!"

# Check for Boost libraries
check-boost:
	@echo "Checking for Boost libraries..."
	@$(CXX) -x c++ -c - -o /dev/null -lboost_system -lboost_json 2>/dev/null <<< 'int main(){}' \
		&& echo "✅ Boost libraries found" \
		|| echo "❌ Boost libraries not found. Install with: sudo apt-get install libboost-all-dev"

# Show all source files
list:
	@echo "Source files in build:"
	@for src in $(SOURCES); do \
		echo "  - $$src"; \
	done
	@echo "Web server:"
	@echo "  - WebServer.cpp"

# Documentation
doc:
	doxygen Doxyfile
	@echo "Documentation generated in docs/html/"
	@echo "Open docs/html/index.html to view"

# Check if doctest header exists
check-doctest:
	@if [ -f "$(DOCTEST_HEADER)" ]; then \
		echo "✅ Doctest header found at $(DOCTEST_HEADER)"; \
	else \
		echo "❌ Doctest header not found at $(DOCTEST_HEADER)"; \
		echo "Please download doctest.h and place it in the tests/ directory"; \
	fi

# Quick test build for debugging
test-quick: clean
	@echo "Building all tests quickly..."
	@for test_src in $(TEST_SOURCES); do \
		if [ "$$test_src" != "$(TEST_DIR)/test_main.cpp" ]; then \
			test_name=$$(basename $$test_src .cpp); \
			echo "Building $$test_name..."; \
			$(CXX) $(CXXFLAGS) -o $$test_name $(TEST_DIR)/test_main.cpp $$test_src $(TEST_BASE_OBJECTS) 2>/dev/null && echo "✅ $$test_name built" || echo "❌ $$test_name failed"; \
		fi \
	done

# Help target
help:
	@echo "Nursery Manager - Build System"
	@echo "=============================="
	@echo ""
	@echo "Main targets:"
	@echo "  all          - Build both console and web versions (default)"
	@echo "  console      - Build only console version"
	@echo "  web          - Build only web server"
	@echo "  run          - Run console version"
	@echo "  run-web      - Run web server (http://localhost:8080)"
	@echo ""
	@echo "Testing:"
	@echo "  test         - Run all tests"
	@echo "  test_plants  - Run plant-related tests"
	@echo "  test_patterns- Run design pattern tests"
	@echo "  test_integration - Run integration tests"
	@echo ""
	@echo "Utilities:"
	@echo "  clean        - Remove all build artifacts"
	@echo "  rebuild      - Clean and build everything"
	@echo "  check        - Check for missing source files"
	@echo "  check-boost  - Check if Boost libraries are installed"
	@echo "  list         - List all source files"
	@echo "  help         - Show this help message"

.PHONY: all clean rebuild run run-web debug check check-boost list test test_plants test_patterns test_integration doc check-doctest test-quick console web help