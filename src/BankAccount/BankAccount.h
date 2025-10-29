#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class BankAccount {

public:
	double balance;
	vector<Observer*> observers;

	void deposit(double amt);

	void withdraw(double amt);

	void addObserver(Observer* o);

	void removeObserver(Observer* o);

	void notifyObservers();

	BankAccount();
};

#endif
