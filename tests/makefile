CXX = g++
CXXFLAGS = -std=c++98 -Wall -Wextra -pedantic
INCLUDES = -I.. -I../src/Observer

SRC = 	../src/Subject/Subject.cpp \
		../src/InventoryObserver/InventoryObserver.cpp \
		../src/Inventory/Inventory.cpp \
		ObserverTestMain.cpp

TARGET = ObserverTest

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f ./$(TARGET)