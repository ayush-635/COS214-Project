/* #ifndef ITERATOR_H
#define ITERATOR_H

#include "../Plant/Plant.h"

class Iterator { // interface
public:
	virtual ~Iterator() = default;
	virtual bool hasNext() = 0;
	virtual Plant* next() = 0;
	virtual Plant* first() = 0;
	virtual Plant* currItem() = 0;
};

#endif
 */