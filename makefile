# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Target executable
TARGET = $(BIN_DIR)/nursery

# Source files - based on your attached files
SOURCES = main.cpp \
	$(SRC_DIR)/Plant/Plant.cpp \
	$(SRC_DIR)/PlantData/PlantData.cpp \
	$(SRC_DIR)/PlantDataFactory/PlantDataFactory.cpp \
	$(SRC_DIR)/Inventory/Inventory.cpp \
	$(SRC_DIR)/FlowerPlant/FlowerPlant.cpp \
	$(SRC_DIR)/TreePlant/TreePlant.cpp \
	$(SRC_DIR)/HerbPlant/HerbPlant.cpp \
	$(SRC_DIR)/GrassPlant/GrassPlant.cpp \
	$(SRC_DIR)/SucculentPlant/SucculentPlant.cpp \
	$(SRC_DIR)/PlantFactory/PlantFactory.cpp \
	$(SRC_DIR)/FlowerFactory/FlowerFactory.cpp \
	$(SRC_DIR)/Game/Game.cpp \
	$(SRC_DIR)/Subject/Subject.cpp \
	$(SRC_DIR)/HealthCheckVisitor/HealthCheckVisitor.cpp \
	$(SRC_DIR)/PlantState/PlantState.cpp \
	$(SRC_DIR)/Seedling/Seedling.cpp \
	$(SRC_DIR)/Growing/Growing.cpp \
	$(SRC_DIR)/Mature/Mature.cpp \
	$(SRC_DIR)/ReadyToSell/ReadyToSell.cpp \
	$(SRC_DIR)/Dying/Dying.cpp \
	$(SRC_DIR)/Dead/Dead.cpp

# Object files
OBJECTS = $(SOURCES:%.cpp=$(OBJ_DIR)/%.o)

# Create necessary directories
$(shell mkdir -p $(OBJ_DIR))
$(shell mkdir -p $(OBJ_DIR)/$(SRC_DIR))
$(shell mkdir -p $(OBJ_DIR)/$(SRC_DIR)/Plant)
$(shell mkdir -p $(OBJ_DIR)/$(SRC_DIR)/PlantData)
$(shell mkdir -p $(OBJ_DIR)/$(SRC_DIR)/PlantDataFactory)
$(shell mkdir -p $(OBJ_DIR)/$(SRC_DIR)/Inventory)
$(shell mkdir -p $(OBJ_DIR)/$(SRC_DIR)/FlowerPlant)
$(shell mkdir -p $(OBJ_DIR)/$(SRC_DIR)/TreePlant)
$(shell mkdir -p $(OBJ_DIR)/$(SRC_DIR)/HerbPlant)
$(shell mkdir -p $(OBJ_DIR)/$(SRC_DIR)/GrassPlant)
$(shell mkdir -p $(OBJ_DIR)/$(SRC_DIR)/SucculentPlant)
$(shell mkdir -p $(OBJ_DIR)/$(SRC_DIR)/PlantFactory)
$(shell mkdir -p $(OBJ_DIR)/$(SRC_DIR)/FlowerFactory)
$(shell mkdir -p $(OBJ_DIR)/$(SRC_DIR)/Game)
$(shell mkdir -p $(OBJ_DIR)/$(SRC_DIR)/Subject)
$(shell mkdir -p $(OBJ_DIR)/$(SRC_DIR)/HealthCheckVisitor)
$(shell mkdir -p $(OBJ_DIR)/$(SRC_DIR)/PlantState)
$(shell mkdir -p $(OBJ_DIR)/$(SRC_DIR)/Seedling)
$(shell mkdir -p $(OBJ_DIR)/$(SRC_DIR)/Growing)
$(shell mkdir -p $(OBJ_DIR)/$(SRC_DIR)/Mature)
$(shell mkdir -p $(OBJ_DIR)/$(SRC_DIR)/ReadyToSell)
$(shell mkdir -p $(OBJ_DIR)/$(SRC_DIR)/Dying)
$(shell mkdir -p $(OBJ_DIR)/$(SRC_DIR)/Dead)
$(shell mkdir -p $(BIN_DIR))

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	@echo "Linking..."
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Build complete: $(TARGET)"

# Compile source files to object files
$(OBJ_DIR)/%.o: %.cpp
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	@echo "Cleaning..."
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "Clean complete"

# Run the program
run: $(TARGET)
	@echo "Running nursery system..."
	./$(TARGET)

# Phony targets
.PHONY: all clean run