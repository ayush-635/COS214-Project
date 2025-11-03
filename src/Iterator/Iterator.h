#ifndef ITERATOR_H
#define ITERATOR_H

#include "../Plant/Plant.h"

/**
 * @class Iterator
 * 
 * @brief Abstract base class for iterators.
 */

class Iterator { 
public:
	/**
	 * @brief Virtual destructor for the Iterator class
	 */
	virtual ~Iterator() = default;

	/**
	 * @brief Checks if there are more elements to iterate over
	 */
	virtual bool hasNext() = 0;

	/**
	 * @brief Returns the next element in the iteration
	 */
	virtual Plant* next() = 0;

	/**
	 * @brief Returns the first element in the iteration
	 */
	virtual Plant* first() = 0;

	/**
	 * @brief Returns the current element in the iteration
	 */
	virtual Plant* currItem() = 0;
};

#endif // ITERATOR_H
