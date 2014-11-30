#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>

#include "Account.h"
#include "Customer.h"
#include "Transaction.h"

using namespace std;

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
	void resetMenu();

	void addCustomer();

	void listAccounts(double);
	void listCustomers();
	void printStatement();
	void save();
	void load();
	void getDate();
	void compoundAccounts();
	int monthsPast(Account&);

	bool inMenu;
	bool running;

	int currentState;

	std::string choice;

	std::istream& in;
	std::ostream& out;

	Customer* currentCustomer;
	int currentAccount;
	
	vector<Customer> customers;
	vector<Account> accounts;
	vector<Transaction> transactions;

	Date currentDate;

	string temp;
};