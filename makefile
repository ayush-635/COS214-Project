# Simple Makefile for Plant Game
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.

# Source files with their respective directories
SRCS = src/PlantData/PlantData.cpp \
       src/PlantDataFactory/PlantDataFactory.cpp \
       src/Seedling/Seedling.cpp \
       src/Growing/Growing.cpp \
       src/Mature/Mature.cpp \
       src/ReadyToSell/ReadyToSell.cpp \
       src/Dead/Dead.cpp \
       src/Plant/Plant.cpp \
       src/FlowerPlant/FlowerPlant.cpp \
       src/TreePlant/TreePlant.cpp \
       src/HerbPlant/HerbPlant.cpp \
       src/GrassPlant/GrassPlant.cpp \
       src/SucculentPlant/SucculentPlant.cpp \
       src/HealthCheckVisitor/HealthCheckVisitor.cpp \
       src/Game/Game.cpp \
       main.cpp

OBJS = $(SRCS:.cpp=.o)
EXEC = plant_game

# Default target
all: $(EXEC)

# Main game
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the game
run: $(EXEC)
	./$(EXEC)

# Clean up
clean:
	rm -f $(EXEC) $(OBJS)

# Help
help:
	@echo "Available commands:"
	@echo "  make all    - Build the game (default)"
	@echo "  make run    - Build and run the game"
	@echo "  make clean  - Remove build files"
	@echo "  make help   - Show this help"

.PHONY: all run clean help