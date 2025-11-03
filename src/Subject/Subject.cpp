#include "Subject.h"
#include "../Observer/Observer.h"

void Subject::attach(Observer* observer) {
	if (observer) {
		observers.push_back(observer);
	}
}

void Subject::notifyStockChange(Plant* plant) {
	for(std::size_t i = 0; i < observers.size(); ++i){
		if (observers[i]) {
			observers[i]->onStockChange(plant);
		} 
	}
}
