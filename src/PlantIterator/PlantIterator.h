#ifndef PLANTITERATOR_H
#define PLANTITERATOR_H

class PlantIterator : Iterator {


public:
	bool hasNext();

	Plant2* next();

	Plant2* first();

	Plant2* currItem();
};

#endif
