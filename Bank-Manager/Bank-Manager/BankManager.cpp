#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <memory>

#include "BankManager.h"

using std::istream;
using std::ostream;

using std::endl;
using std::string;

using namespace std;

//Creates a new bank manager given an input stream and an output stream.
BankManager::BankManager(istream& inStream, ostream& outStream)
    :in(inStream),
    out(outStream),
    running(true)
    {
	currentState = 0;
	currentCustomer = NULL;
    }

//Default Destructor
BankManager::~BankManager()
{
}




//Runs the program until state changes to exit.
void BankManager::run(){
    load();
    setup();
    out << "<<O>><<O>> WELCOME TO ALL POWERFUL BANK, MAKE A SELECTION <<O>><<O>>\n"
        << "   ----                                                      ----   \n" << endl;
    printMenu();
    while (running){
		//update();
		handleInput();
        update();
    }
}





//Updates the screen based on the current program state.
void BankManager::update(){
    switch (currentState){
    case 0: //Menu
        printHeader();
        printMenu();
        break;
    case 1: //Submit a transaction
        out << "1. Submit a transaction\n";
        submitTransaction();
        break;
    case 2: //List all accounts for a given customer
        out << "2. List all accounts\n";
        listAccounts();
        break;
    case 3: //Print a Monthly statement for a specific account
        out << "3. Print a Monthly Statement\n";
        printStatement();			
        break;
    case 4: //Print the total savings value
        out << "4. Print Savings Value\n";
        printAccountValue("s");
        break;
    case 5: //Print the total Checking value
        out << "5. Print Checking Value\n";
        printAccountValue("c");
        break;
    case 6: //Print the total CD value
        out << "6. Print CD Value\n";
        printAccountValue("cd");
        break;
    case 7: //List all customers 
			//TODO and the total value of all their accounts
        out << "7. List all Customers\n";
        listCustomers();
        break;
    case 8: //Save accounts, transactions, and customers
        out << "8. Save\n";
        save();
        break;
    case 9: //Exit the program
        running = false;
        break;
    case 10: //Invalid input
        out << "Enter a valid input\n";
        currentState = 0;
        break;
    default: //Invalid input
        out << "Enter a valid input\n";
        currentState = 0;
        break;
    }
}

//Handles keyboard input based on state
void BankManager::handleInput(){
	in >> choice;
        //allows ctrl+d quit
        if (!in.good())
        {
            choice = "quit";
        }
	if (!in){
		currentState = 10;
		in.clear();
		in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	//Always available
	if (choice == "menu"){
		currentState = 0;
		return;
	}
	else if (choice == "quit" || choice == "exit"){
		currentState = 9;
		return;
	}

	if (currentState == 0){
		menuInput(choice);
	}

	

	
}

//Changes the state based on the users choice.
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

//Prints the main menu.
void BankManager::printMenu(){
    //out << "\nWELCOME TO ALL POWERFUL BANK, PLEASE MAKE A SELECTION\n" << endl
    out << "Type \"menu\" at any time to return to this menu.\n"
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

//Prints the header showing current customer.
void BankManager::printHeader(){
    if (currentCustomer != NULL){
        out << "------------------------------------\n"
            << "Current Customer: " << currentCustomer << "\n"
            << "------------------------------------\n" << endl;
    }
}

//TODO add a new customer.
void BankManager::addCustomer(){
    Customer customer = Customer();
    customers.push_back(customer);
}

//TODO list all accounts for the current customer.
void BankManager::listAccounts(){
    int id;
        out << "Enter a Customer ID: ";
        in >> id;
    for (unsigned i = 0; i < customers.size(); i++)
    {
        if(customers.at(i).getID() == id){
            customers.at(i).printAccount(out);
        }
//        for (unsigned j = 0; j < customers.at(i).; j++)
//        {
//            if (accounts.at(i).getCustomers().at(j)->getID() == id)
//            {
//                out << accounts.at(i);
//                break;
//            }
//        }
    }
}

//Lists all saved customers.
//TODO and the value of their accounts.
void BankManager::listCustomers(){
	if (!customers.empty()){
		for (unsigned i = 0; i < customers.size(); i++){
			Customer customer = customers.at(i);
			out << customer.getFirstName() << " " << customer.getLastName()
				<< "\nID: " << customer.getID()
				<< "\nSSN: " << customer.getSSN()
				<< "\nAddress: " << customer.getAddress();			
			customer.printAccount(out);		
            out << "\n\n";
        }
    }
}

//TODO print a statement for an account to be selected.
void BankManager::printStatement(){
    int id;
    out << "Enter an account number to print: ";
    in >> id;
    if (!accounts.empty()){
			for (unsigned i = 0; i < accounts.size(); i++){
				//do output
				if (accounts.at(i).getID() == id){
                                    out << "\nEnter a month and a year: ";
                                    int m, y;
                                    in >> m >> y;
					accounts.at(i).generateMonthlyReport(out,m,y);
					return;
				}
			}
		}
	
}

//Template saves to a file.
template<typename T>
void saveFile(vector<T> vec, ofstream& outFile){
    if (!vec.empty()){
        for (unsigned i = 0; i < vec.size(); i++){
			vec.at(i).save(outFile);
			if(i < (vec.size()-1)){
                            outFile << "\n";
                        }
        }
    }
}

//Opens all files and overwrites contents based on current accounts, transactions, and customers.
void BankManager::save(){
    ofstream accountFile, customerFile, transactionFile;
    
    accountFile.open("Accountsout.txt", ios::out);
    customerFile.open("Customersout.txt", ios::out);
    transactionFile.open("Transactionsout.txt", ios::out);
	
    saveFile(accounts, accountFile);
    saveFile(customers, customerFile);
    saveFile(transactions, transactionFile);

    accountFile.close();
    customerFile.close();
    transactionFile.close();
}

//Template loads from a file.
template<typename T>
void loadFile(vector<T>& vec, ifstream& inFile){
    T temp = T();
    while (!inFile.eof()){
        inFile >> temp;
        vec.push_back(temp);
    }
}

void loadAccounts(vector<Account>& vec, ifstream& inFile){
    Account temp = Account();
    while (!inFile.eof()){
        inFile >> temp;
        if(temp.getType() == "c"){
            Checking cTemp = Checking();
            cTemp = temp;
            vec.push_back(cTemp);
        }
        else{
            vec.push_back(temp);
        }
    }
    
    
}


//Opens all files and fills accounts, transactions, and customers based on contents.
void BankManager::load(){
    ifstream accountFile, customerFile, transactionFile;
    accountFile.open("Accounts.txt", ios::in);
    customerFile.open("Customers.txt", ios::in);
    transactionFile.open("Transactions.txt", ios::in);
    
    loadAccounts(accounts, accountFile);
    loadFile(customers, customerFile);
    loadFile(transactions, transactionFile);

    accountFile.close();
    customerFile.close();
    transactionFile.close();
}

void BankManager::getDate(){
	time_t t = time(0);
	struct tm * now = localtime(&t);
	currentDate.setDate((now->tm_mon + 1), (now->tm_mday), (now->tm_year + 1900));
}

void BankManager::compoundAccounts(){
	int count;
	for (unsigned i = 0; i < accounts.size(); i++)
	{
		count = monthsPast(accounts.at(i));
                
                accounts.at(i).monthlyChores(count);
	}
}

int BankManager::monthsPast(Account& account){
	if (currentDate < account.getDate())
	{
		return 0;
	}
	int years = currentDate.getYear() - account.getDate().getYear();
	int months = currentDate.getMonth() - account.getDate().getMonth();
	int days = currentDate.getDay() - account.getDate().getDay();
	int totalMonths = years * 12;
	totalMonths += months;
	if (days <= 0)
	{
		totalMonths--;
	}
	return totalMonths;
}

void BankManager::setup(){
    getDate();
    for (unsigned i = 0; i < transactions.size(); i++){
        for (unsigned j = 0; j < accounts.size(); j++){
            if (transactions.at(i).getAccountID() == accounts.at(j).getID()){
                accounts.at(j).addTransaction(transactions.at(i));
            }
        }
    }
    //compoundAccounts();
}

void BankManager::printAccountValue(string type){
    double totalBalance;
    for(unsigned i = 0; i < accounts.size(); i++ ){
        if(accounts.at(i).getType() == type){
            totalBalance += accounts.at(i).getValue();
        }
    }
    out << "Total balance of " << type << " accounts is: " << totalBalance << endl;
    
}

void BankManager::submitTransaction(){
    int i; double a; char type; string location; Date d;   
    out << "Account number: ";
    in >> i;
    out << "Type: ";
    in >> type;
    out << "Amount: ";
    in >> a;
    out << "Location: ";
    in >> location;
    out << "Date: ";
    in >> d;
    Transaction trans = Transaction(i,type,a,location,d);
    transactions.push_back(trans);
    setup();
    currentState = 0;
}