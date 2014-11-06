#pragma once
#include <iostream>
#include <list>
#include <string>

#include "Account.h"
#include "Customer.h"
#include "Transaction.h"

class BankManager
{
public:
	BankManager(std::istream&, std::ostream&);
	~BankManager();

	void run();

private:
	void menuInput(std::string);
	void update();

	void printMenu();
	void printHeader();

	void handleInput();

	bool inMenu;
	bool running;

	int currentState;

	std::string choice;

	std::istream& in;
	std::ostream& out;

	Customer* currentCustomer;

	list<Customer> customers;
	list<Account> accounts;
	list<Transaction> transactions;
};

