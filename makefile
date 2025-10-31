# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.

# Directories
SRC_DIR = src

# Source files - ADD ALL YOUR CPP FILES
SOURCES = main.cpp \
          $(SRC_DIR)/SpaceBuilder/SpaceBuilder.cpp \
          $(SRC_DIR)/ConcreteSpaceBuilder/ConcreteSpaceBuilder.cpp \
          $(SRC_DIR)/NurseryManager/NurseryManager.cpp \
          $(SRC_DIR)/PlanterBox/PlanterBox.cpp \
          $(SRC_DIR)/PlanterBoxCollection/PlanterBoxCollection.cpp \
          $(SRC_DIR)/Plant/Plant.cpp \
          $(SRC_DIR)/GrassPlant/GrassPlant.cpp \
          $(SRC_DIR)/FlowerPlant/FlowerPlant.cpp \
          $(SRC_DIR)/PlantData/PlantData.cpp \
          $(SRC_DIR)/PlantState/PlantState.cpp \
          $(SRC_DIR)/Seedling/Seedling.cpp \
          $(SRC_DIR)/Growing/Growing.cpp \
          $(SRC_DIR)/Mature/Mature.cpp \
          $(SRC_DIR)/ReadyToSell/ReadyToSell.cpp \
          $(SRC_DIR)/Dying/Dying.cpp \
          $(SRC_DIR)/Dead/Dead.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Executable name
TARGET = nursery_game

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "Build complete! Run with ./$(TARGET)"

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

.PHONY: all clean rebuild run