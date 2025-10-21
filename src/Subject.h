#ifndef SUBJECT_H
#define SUBJECT_H

class Subject {

private:
	Observer* observer;

public:
	void attach(Observer* observer);

	virtual void notifyStockChange(Plant* plant) = 0;

	Subject();
};

#endif
