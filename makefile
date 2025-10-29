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
       src/Dying/Dying.cpp \
       src/Dead/Dead.cpp \
       src/Plant/Plant.cpp \
       src/FlowerPlant/FlowerPlant.cpp \
       src/TreePlant/TreePlant.cpp \
       src/HerbPlant/HerbPlant.cpp \
       src/GrassPlant/GrassPlant.cpp \
       src/SucculentPlant/SucculentPlant.cpp \
       src/HealthCheckVisitor/HealthCheckVisitor.cpp \
       src/Game/Game.cpp \
       src/PlantFactory/PlantFactory.cpp \
       src/FlowerFactory/FlowerFactory.cpp \
       src/TreeFactory/TreeFactory.cpp \
       src/HerbFactory/HerbFactory.cpp \
       src/GrassFactory/GrassFactory.cpp \
       src/SucculentFactory/SucculentFactory.cpp \
       main.cpp

OBJS = $(SRCS:.cpp=.o)
EXEC = plant_game

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all run clean help

TEST_DIR = tests
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)
TEST_EXEC = plant_game_tests

# Build and run tests
test: $(TEST_EXEC)
	./$(TEST_EXEC)

$(TEST_EXEC): $(TEST_OBJS) $(filter-out main.o, $(OBJS))
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile test files
$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean tests too
clean:
	rm -f $(EXEC) $(TEST_EXEC) $(OBJS) $(TEST_OBJS)

.PHONY: all run clean help test