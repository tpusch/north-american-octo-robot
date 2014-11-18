#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>

#include "BankManager.h"

using std::istream;
using std::ostream;

using std::endl;
using std::string;

BankManager::BankManager(istream& inStream, ostream& outStream)
    :in(inStream),
    out(outStream),
    running(true)
    {
	currentState = 0;
	currentCustomer = NULL;
    }

BankManager::~BankManager()
{
}

void BankManager::run(){
    load();
    out << "<<O>><<O>> WELCOME TO ALL POWERFUL BANK, MAKE A SELECTION <<O>><<O>>\n"
        << "   ----                                                      ----   \n" << endl;
    printMenu();
    while (running){
        handleInput();
        update();
    }
}

void BankManager::update(){
    switch (currentState){
    case 0:
        printHeader();
        printMenu();
        break;
    case 1:
        out << "1. Submit a transaction\n";
        break;
    case 2:
        out << "2. List all accounts\n";
        listAccounts();
        break;
    case 3:
        out << "3. Print a Monthly Statement\n";
        printStatement();			
        break;
    case 4:
        out << "4. Print Savings Value\n";
        break;
    case 5:
        out << "5. Print Checking Value\n";
        break;
    case 6:
        out << "6. Print CD Value\n";
        break;
    case 7:
        out << "7. List all Customers\n";
        listCustomers();
        break;
    case 8:
        out << "8. Save\n";
        save();
        break;
    case 9:
        running = false;
        break;
    case 10:
        out << "Enter a valid input\n";
        currentState = 0;
        break;
    default:
        out << "Enter a valid input\n";
        currentState = 0;
        break;
    }
}

void BankManager::printMenu(){
    //out << "\nWELCOME TO ALL POWERFUL BANK, PLEASE MAKE A SELECTION\n" << endl
    out << "Type \"menu\" or \"0\" at any time to return to this menu.\n"
        << "Type \"quit\" or \"exit\" at any time to stop the program\n\n"
        << "1. Submit a Transaction\n"
        << "2. List all Accounts\n"
        << "3. Print a Monthly Statement\n"
        << "4. Print Savings Value\n"
        << "5. Print Checking Value\n"
        << "6. Print CD Value\n"
        << "7. List all Customers\n"
        << "8. Save\n"
        << "9. Exit\n" << endl;
}

void BankManager::printHeader(){
    if (currentCustomer != NULL){
        out << "------------------------------------\n"
            << "Current Customer: " << currentCustomer << "\n"
            << "------------------------------------\n" << endl;
    }
}

void BankManager::handleInput(){
    in >> choice;
    if (!in){
        currentState = 10;
        in.clear();
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
	
    //if (currentState == 0){
        menuInput(choice);		
    //}

    //Always available
    if (choice == "0" || choice == "menu"){
        currentState = 0;
    }
    else if (choice == "quit" || choice == "exit"){
        currentState = 9;
    }
}

void BankManager::menuInput(string choice){
    if (choice == "0" || choice == "menu"){
        currentState = 0;
    }
    else if(choice == "1"){
        currentState = 1;
    }
    else if (choice == "2"){
        currentState = 2;
    }
    else if (choice == "3"){
        currentState = 3;
    }
    else if (choice == "4"){
        currentState = 4;
    }
    else if (choice == "5"){
        currentState = 5;
    }
    else if (choice == "6"){
        currentState = 6;
    }
    else if (choice == "7"){
        currentState = 7;
    }
    else if (choice == "8"){
        currentState = 8;
    }
    else if (choice == "9" || choice == "quit" || choice == "exit"){
        currentState = 9;
    }
    else{
        currentState = 10;
    }
}

void BankManager::addCustomer(){
    Customer customer = Customer();
    customers.push_back(customer);
}

void BankManager::listAccounts(){
    if (!accounts.empty()){
        for (unsigned i = 0; i < accounts.size(); i++){
            //out << accounts.at(i) << "\n";
        }
    }
}

void BankManager::listCustomers(){
    if (!customers.empty()){
        for (unsigned i = 0; i < customers.size(); i++){
            Customer customer = customers.at(i);
            out << customer.getFirstName() << " " << customer.getLastName()
                << "\nID: " << customer.getID()
                << "\nSSN: " << customer.getSSN()
                << "\nAddress: " << customer.getAddress()
                << "\n\n";
        }
    }
}

void BankManager::printStatement(){
    int accountNumber;
    out << "Enter an account number to print: ";
    in >> accountNumber;

    if (!accounts.empty()){
        for (unsigned i = 0; i < accounts.size(); i++){
        //do output
        //if (accounts.at(i).getID() == accountNumber){
        //	accounts.at(i).printStatement();
        //}
        }
    }	
}

template<typename T>
void saveFile(vector<T>& vec, ofstream& outFile){
    if (!vec.empty()){
        for (unsigned i = 0; i < vec.size(); i++){
            outFile << vec.at(i);
            outFile << "\n";
        }
    }
}

void BankManager::save(){
    ofstream accountFile, customerFile, transactionFile;
    accountFile.open("Accounts.txt", ios::out);
    customerFile.open("Customers.txt", ios::out);
    transactionFile.open("Transactions.txt", ios::out);
	
    //saveFile(accounts, accountFile);
    saveFile(customers, customerFile);
    saveFile(transactions, transactionFile);

    accountFile.close();
    customerFile.close();
    transactionFile.close();
}

template<typename T>
void loadFile(vector<T>& vec, ifstream& inFile){
    T temp = T();
    while (!inFile.eof()){
        inFile >> temp;
        vec.push_back(temp);
    }
}

void BankManager::load(){
    ifstream accountFile, customerFile, transactionFile;
    accountFile.open("Accounts.txt", ios::in);
    customerFile.open("Customers.txt", ios::in);
    transactionFile.open("Transactions.txt", ios::in);
    //loadFile(accounts, accountFile);
    loadFile(customers, customerFile);
    loadFile(transactions, transactionFile);

    accountFile.close();
    customerFile.close();
    transactionFile.close();
}