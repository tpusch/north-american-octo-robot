#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>

#include "Account.h"
#include "Checking.h"
#include "Savings.h"
#include "Certificate_of_Deposit.h"
#include "Customer.h"
#include "Transaction.h"

using namespace std;

class BankManager
{
public:
    //constructor/destructor
    BankManager(std::istream&, std::ostream&);
    ~BankManager();

    //run prototype
    void run();
    void load();
	
private:
    //Lots of prototypes
    void menuInput(std::string);
    void update();
    void customerUpdate();

    void printMenu();
    void printCustomerMenu();
    void printHeader();

    void handleInput();
    void resetMenu();

    void addCustomer();
    void addAccount(int);

    void listAccounts(int);
    void listCustomers();
    void printStatement();
    void save();
    void login();
    void logout();
    
    void loadAccounts(vector<Account*>&, ifstream&);
    void loadCustomers(vector<Customer*>&, ifstream&);
    void loadTransactions(vector<Transaction*>&, ifstream&);
        
    void setup();
        
    void getDate();
    void compoundAccounts();
        
    void printAccountValue(string);
        
    void submitTransaction();
    void customerTransaction(char);
        
    int monthsPast(Account*);

    //Member Variables
    bool inMenu;
    bool running;

    int currentState;

    string choice;

    istream& in;
    ostream& out;

    Customer* currentCustomer;
    int currentAccount;

    vector<Customer*> customers;
    vector<Account*> accounts;
    vector<Transaction*> transactions;

    Date currentDate;

    string temp;

    bool manager;
};