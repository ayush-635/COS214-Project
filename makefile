# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.

# Directories
SRC_DIR = src

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
          $(SRC_DIR)/FlowerPlant/FlowerPlant.cpp \
          $(SRC_DIR)/GrassPlant/GrassPlant.cpp \
          $(SRC_DIR)/HerbPlant/HerbPlant.cpp \
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
          $(SRC_DIR)/pot/Pot.cpp \
          $(SRC_DIR)/Mediator/Mediator.cpp \
          $(SRC_DIR)/Colleague/Colleague.cpp \
          $(SRC_DIR)/InteractionManager/InteractionManager.cpp \
          $(SRC_DIR)/StaffMember/StaffMember.cpp \
          $(SRC_DIR)/Sales/Sales.cpp \
          $(SRC_DIR)/Cashier/Cashier.cpp \
          $(SRC_DIR)/Customer/Customer.cpp \
          $(SRC_DIR)/Inventory/Inventory.cpp \
          $(SRC_DIR)/Subject/Subject.cpp \
          $(SRC_DIR)/InventoryObserver/InventoryObserver.cpp \
          $(SRC_DIR)/DeliveryStrategy/DeliveryStrategy.cpp \
          $(SRC_DIR)/ExpressDelivery/ExpressDelivery.cpp \
          $(SRC_DIR)/PickupDelivery/PickupDelivery.cpp \
          $(SRC_DIR)/StandardDelivery/StandardDelivery.cpp \
          $(SRC_DIR)/Game/Game.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Executable name
TARGET = nursery_game

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "============================================"
	@echo "Build complete! Run with ./$(TARGET)"
	@echo "Integrated Systems:"
	@echo "  ✓ Mediator Pattern (Staff Communication)"
	@echo "  ✓ Observer Pattern (Inventory Updates)"
	@echo "  ✓ Singleton (Inventory & InteractionManager)"
	@echo "  ✓ Customer & Staff Integration"
	@echo "============================================"

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(OBJECTS) $(TARGET)
	@echo "Clean complete!"

# Rebuild everything
rebuild: clean all

# Run the program
run: $(TARGET)
	./$(TARGET)

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
	@echo "Check complete!"

# Show all source files
list:
	@echo "Source files in build:"
	@for src in $(SOURCES); do \
		echo "  - $$src"; \
	done

.PHONY: all clean rebuild run debug check list