#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer : Colleague {

private:
	HashMap<string> preferences;
	int rand;

public:
	boolean requestSale(Plant* plant);

	void sendPreference();

	void receiveAdvice();

	Customer();
};

#endif
