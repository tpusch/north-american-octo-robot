#include "BankManager.h"
#include <sstream>
#include <iomanip>
#include <limits>
#include <memory>

using namespace std;

//Creates a new bank manager given an input stream and an output stream.
BankManager::BankManager(istream& inStream, ostream& outStream)
    :in(inStream),
    out(outStream),
    running(true){
	currentState = 0;
	out << fixed;
	out << setprecision(2);
	manager = false;
        currentCustomer = NULL;
    }

//Default Destructor
BankManager::~BankManager(){}

//Runs the program until state changes to exit.
void BankManager::run(){
    load();
    setup();
    compoundAccounts();
    //TODO: login
    out << "<<O>><<O>> WELCOME TO DONATELLO BANK, MAKE A SELECTION <<O>><<O>>\n"
        << "   ----                                                   ----   \n" << endl;
    login();
    while (running){
        if (manager){
            update();
        }
        else{
            customerUpdate();
        }
    }
}

void BankManager::login(){
    while (true){
        string uname, pass;
        out << "Enter user name: ";
        in >> uname;       
        if (uname == "admin"){
            out << "Vhat iz zee passverd?! ";
            in >> pass;
            if (pass == "password"){
                manager = true;
                return;
            }
            else{
                out << "WRONG! TRY AGAIN!\n";
            }
        }
        else{
            for (unsigned i = 0; i < customers.size(); i++){
                if (customers.at(i)->getUName() == uname){
                    out << customers.at(i)->getUName() << "'s password: ";
                    in >> pass;
                    if(pass == customers.at(i)->getPass()){
                        currentCustomer = customers.at(i);
                        return;
                    }
                    else{
                        out << "WRONG SUCKA!\n";
                    }
                }
            }
        }
        if (!in.good()){
            running = false;
            break;
        }
    }   
}

void BankManager::logout(){
    manager = false;
    currentCustomer = NULL;
    currentState = 0;
    login();
}

//Updates the screen based on the current program state.
void BankManager::update(){
    switch (currentState){
    case 0: //Menu
        printMenu();
        handleInput();
        break;
    case 1: //Submit a transaction
        out << "1. Submit a transaction\n";
        submitTransaction();
        resetMenu();
        break;
    case 2: //List all accounts for a given customer
        out << "2. List all accounts\n";
        int id;
        out << "Enter a Customer ID: ";
        in >> id;
        listAccounts(id);
        resetMenu();
        break;
    case 3: //Print a Monthly statement for a specific account
        out << "3. Print a Monthly Statement\n";
        printStatement();
        resetMenu();
        break;
    case 4: //Print the total savings value
        out << "4. Print Savings Value\n";
        printAccountValue("s");
        resetMenu();
        break;
    case 5: //Print the total Checking value
        out << "5. Print Checking Value\n";
        printAccountValue("c");
        resetMenu();
        break;
    case 6: //Print the total CD value
        out << "6. Print CD Value\n";
        printAccountValue("cd");
        resetMenu();
        break;
    case 7: //List all customers 
            //and the total value of all their accounts
        out << "7. List all Customers\n";
        listCustomers();
        resetMenu();
        break;
    case 10: //Save accounts, transactions, and customers
        out << "Saved\n";
        save();
        resetMenu();
        break;
    case 11: //Exit the program
        running = false;
        break;
    case 100: //Invalid input
        out << "Sorry, that is an invalid input\n";
        currentState = 0;
        break;
    case 8:
        out << "8. Add a customer\n";
        addCustomer();
        resetMenu();
        break;
    case 9:
        out << "9. Add an Account\n";
        addAccount(0);
        resetMenu();
        break;
    case 12:
        logout();
        break;
    default: //Invalid input
        out << "Sorry, that is an invalid input\n";
        currentState = 0;
        break;
    }
}

//TODO: customer menu
void BankManager::customerUpdate(){
    switch (currentState){
    case 0:
        printCustomerMenu();
        handleInput();
        break;
    case 1:
        out << "1. Make a Deposit\n";
        customerTransaction('d');
        resetMenu();
        break;
    case 2:
        out << "2. Make a Withdrawal\n";
        customerTransaction('w');
        resetMenu();
        break;
    case 3:
        out << "3. List Accounts\n";
        listAccounts(currentCustomer->getID());
        resetMenu();
        break;
    case 4:
        out << "4. Print a Monthly Statement\n";
        printStatement();
        resetMenu();
        break;
    case 5:
        out << "5. Save\n";
        save();
        resetMenu();
        break;
    case 8:
        logout();
        break;
    case 11:
        running = false;
    default:
        out << "Invalid input";
        currentState = 0;
        break;
    }
}

//Handles keyboard input based on state
void BankManager::handleInput(){
    in >> choice;
    //allows ctrl+d quit
    if (!in.good()){
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

void BankManager::resetMenu(){
    string response;
    out << "\n\nWould you like to return to the menu? (y/n) ";
    in >> response;
    if (response == "y"){
        currentState = 0;
    }
    else if (response == "n"){
    }
    else{
        currentState = 100;
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
    else if (choice == "9"){
        if (manager){
            currentState = 9;
        }
        else{
            currentState = 11;
        }
    }
    else if (choice == "10"){
        currentState = 10;
    }
    else if(choice == "11" || choice == "quit" || choice == "exit"){
        currentState = 11;
    }
    else if(choice == "12"){
        currentState = 12;
    }
    else{
        currentState = 100;
    }
}

//Prints the main menu.
void BankManager::printMenu(){
    // out << "\nType \"menu\" at any time to return to this menu.\n"
    //<< "Type \"quit\" or \"exit\" at any time to stop the program\n\n"
    out << "\n\tMain Menu\n"
        << "1. Submit a Transaction\n"
        << "2. List all Accounts for a Customer\n"
        << "3. Print a Monthly Statement\n"
        << "4. Print Savings Value\n"
        << "5. Print Checking Value\n"
        << "6. Print CD Value\n"
        << "7. List all Customers\n"
        << "8. Add New Customer\n"
        << "9. Add New Account\n"
        << "10. Save\n" 
        << "11. Exit\n" 
        << "12. Logout\n" << endl;
}

void BankManager::printCustomerMenu(){
    out << "\n\tMain Menu\n"
        << "1. Make a deposit\n"
        << "2. Make a Withdrawal\n"
        << "3. List Accounts\n"
        << "4. Print Monthly Statement\n" 
        << "5. Save\n"
        << "8. Logout\n"
        << "9. Quit\n" << endl;
}



//TODO list all accounts for the current customer.
void BankManager::listAccounts(int idIN){
    
    int id = idIN;
    bool found = false;
    //loop from 0 to size of customer vector. Compares ids to determine accounts to print.
    for (unsigned i = 0; i < customers.size(); i++)
    {
        if(customers.at(i)->getID() == id){
            customers.at(i)->printAccount(out);
            found = true;
        }
    }
    if (!found){
        out << "Customer ID not found.";
    }
}

//Lists all saved customers.
//TODO and the value of their accounts.
void BankManager::listCustomers(){
    if (!customers.empty()){
        //loop from 0 to size of customer vector. Will print all customers.
        for (unsigned i = 0; i < customers.size(); i++){
            //out << customers.at(i)->getFirstName() << " " << customers.at(i)->getLastName()
            out	<< "\nCustomer ID: " << customers.at(i)->getID()
                << "\nSSN: " << customers.at(i)->getSSN()
                << "\nAddress: " << customers.at(i)->getAddress();			
            customers.at(i)->printAccount(out);		
            customers.at(i)->printAccountValues(out);
            out << "\n\n";
        }
    }
}

//Prints a statement for an account to be selected.
void BankManager::printStatement(){
    int id;
    bool toprint = false;
    out << "Enter an account number to print: ";
    in >> id;
    if (!accounts.empty()){
        //Loop from 0 to size of accounts vector to find correct account.
        for (unsigned i = 0; i < accounts.size(); i++){           
            //do output
            //if accountID equals input id, generate statement
            if (accounts.at(i)->getID() == id){
                if(currentCustomer != NULL){
                    for(int j = 0; j < currentCustomer->getAccounts().size(); j++){
                        if(id == currentCustomer->getAccounts().at(j)->getID()){
                            toprint = true;
                        }
                    }
                }
                if(toprint || manager){ 
                    out << "Enter a month and a year MM YYYY: ";
                    int m, y;
                    in >> m >> y;
                    //use for testing all transactions
                    //accounts.at(i)->generateReport(out);
                    accounts.at(i)->generateMonthlyReport(out,m,y);
                    return;
                }
                else{
                    out << "That is not your account";
                    return;
                }
            }
            
        }
    }
	
}

//Template saves to a file.
template<typename T>
void saveFile(vector<T> vec , ofstream& outFile){
    if (!vec.empty()){
        //Loop from 0 to given vector size.
        for (unsigned i = 0; i < vec.size(); i++){
            vec.at(i)->save(outFile);
            if(i < (vec.size()-1)){
                outFile << "\n";
            }
        }
    }
}

//Opens all files and overwrites contents based on current accounts, transactions, and customers.
void BankManager::save(){
    ofstream accountFile, customerFile, transactionFile;
    
    accountFile.open("Accounts.txt", ios::out);
    customerFile.open("Customers.txt", ios::out);
    transactionFile.open("Transactions.txt", ios::out);
	
    saveFile(accounts, accountFile);
    saveFile(customers, customerFile);
    saveFile(transactions, transactionFile);

    accountFile.close();
    customerFile.close();
    transactionFile.close();
}

//Template loads from a file.
template<typename T>
void loadFile(vector<T*>& vec, ifstream& inFile){
    //while items remain in the file
    while (!inFile.eof()){
        T* temp = new T();
        inFile >> temp;
        vec.push_back(temp);
    }
}

//Load customers and link with accounts
void BankManager::loadCustomers(vector<Customer*>& vec, ifstream& inFile){
    while (!inFile.eof()){
        Customer* customer = new Customer();
        inFile >> customer;
        vec.push_back(customer);
    }
}

//load transactions, note: they are linked to accounts via setup()
void BankManager::loadTransactions(vector<Transaction*>& vec, ifstream& inFile){
    //while items remain in the file
    while (!inFile.eof()){
        Transaction* action = new Transaction();
        inFile >> action;
        vec.push_back(action);
    }
}

//Loads accounts controlling for child type
void BankManager::loadAccounts(vector<Account*>& vec, ifstream& inFile){
    string type;
    //while items remain in the file
    while (!inFile.eof()){
        inFile >> type;
        //make checking account
        if(type == "c" || type == "C"){
            Checking* cTemp = new Checking();
            inFile >> *cTemp;
            vec.push_back(cTemp);
        }
        //make savings account
        else if(type == "s" || type == "S"){
            Savings* sTemp = new Savings();
            inFile >> *sTemp;
            vec.push_back(sTemp);
        }
        //make certificate of deposit account
        else if(type == "cd" || type == "CD"){
            Certificate_of_Deposit* cdTemp = new Certificate_of_Deposit();
            inFile >> *cdTemp;
            vec.push_back(cdTemp);
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
    loadCustomers(customers, customerFile);
    loadTransactions(transactions, transactionFile);

    accountFile.close();
    customerFile.close();
    transactionFile.close();
}

//Gets the current date from the system
//used for determining correct compound/monthly fee date
void BankManager::getDate(){
    time_t t = time(0);
    struct tm * now = localtime(&t);
    currentDate.setDate((now->tm_mon + 1), (now->tm_mday), (now->tm_year + 1900));
}

//Does all monthly chores for accounts
void BankManager::compoundAccounts(){
    int count;
    //Loop from 0 to size of accounts vector. Will count the months past and 
    //compound or charge fee depending on account type
    for (unsigned i = 0; i < accounts.size(); i++){
        count = monthsPast(accounts.at(i));
        accounts.at(i)->monthlyChores(count);
    }
}

//Calculates months passed since the opening of a given account
int BankManager::monthsPast(Account* account){
    //check if account opening date is from the future
    if (currentDate < account->getDate()){
        return 0;
    }
    //set differences from current date to account opening date; calculate total months
    int years = currentDate.getYear() - account->getDate().getYear();
    int months = currentDate.getMonth() - account->getDate().getMonth();
    int days = currentDate.getDay() - account->getDate().getDay();
    int totalMonths = years * 12;
    totalMonths += months;
    if (days <= 0){
        totalMonths--;
    }
    return totalMonths;
}

//Sets up interconnections between accounts and transactions
void BankManager::setup(){
    getDate();
    //Loop from 0 to size of transactions vector.
    for (unsigned i = 0; i < transactions.size(); i++){
        //Loop from 0 to size of accounts vector
        for (unsigned j = 0; j < accounts.size(); j++){
            //link transactions with their corresponding account
            if (transactions.at(i)->getAccountID() == accounts.at(j)->getID()){
                accounts.at(j)->addTransaction(transactions.at(i));
            }
        }
    }
    for (unsigned i = 0; i < customers.size(); i++){
        for (unsigned j = 0; j < customers.at(i)->accountNums.size(); j++){
            int acctNum = customers.at(i)->accountNums.at(j);
            for(unsigned k = 0; k < accounts.size(); k++){
                if(acctNum == accounts.at(k)->getID()){
                    customers.at(i)->addAccount(accounts.at(k));
                }
            }
        }
    }   
}

//Prints the total value of all given accounts.
void BankManager::printAccountValue(string type){
    double totalBalance = 0;
    //Loop from 0 to size of accounts vector. Calculates total balance of accounts of type input
    for(unsigned i = 0; i < accounts.size(); i++ ){
        if(accounts.at(i)->getType() == type){
            totalBalance += accounts.at(i)->getValue();
        }
    }
    if (type == "s"){
        out << "Total balance of all Savings accounts is: $" << totalBalance << endl;
    }
    else if (type == "c"){
        out << "Total balance of all Checking accounts is: $" << totalBalance << endl;
    }
    else if (type == "cd"){
        out << "Total balance of all Certificates of Deposit is: $" << totalBalance << endl;
    }
}

//TODO add a new customer.
void BankManager::addCustomer(){
    Customer* customer = new Customer();
    string fname, lname, ssn, address, uname, pass;
    int id;
    string choice;
    
    out << "First Name: ";
    in >> fname;
    customer->setFirstName(fname);
    
    out << "Last Name: ";
    in >> lname;
    customer->setLastName(lname);
    
    out << "SSN: ";
    in >> ssn;
    customer->setSSN(ssn);
    
    out << "User Name: ";
    in >> uname;
    customer->setUName(uname);
    
    out << "Password: ";
    in >> pass;
    customer->setPass(pass);

    customer->setID(customers.size()+1);
    out << "Address: ";
    //in >> address;
    //in.ignore();
    getline(in, address);
    
    getline(in, address);   
    customer->setAddress(address); 
    
    customers.push_back(customer);
    
    
    out << "Add new account or connect old (new/old)? ";
    in >> choice;
    if(choice == "new"){
        addAccount(customers.size());
    }
    else if(choice == "old"){
        out << "Account ID: ";
        in >> id;
        customer->accountNums.push_back(id); 
        for(unsigned i = 0; i < accounts.size(); i++){
            if(id == accounts.at(i)->getID()){
                customer->addAccount(accounts.at(i));
            }
        }
    }
    
}

void BankManager::addAccount(int custID){
    string type;
    double balance;
    int id = custID;
    out << "Opening Balance: ";
    in >> balance;
    
    if(custID == 0){
        out << "Customer ID: "; 
        in >> id;
    }
    out << "Account Type(c/s/cd): ";
    
    in >> type;
    if(type == "c" || type == "C"){
        Checking* cTemp = new Checking();
        cTemp->setBalance(balance);
        cTemp->setDate(currentDate);
        cTemp->setID(accounts.size()+1);
        for(unsigned i = 0; i < customers.size(); i++){
            if(customers.at(i)->getID() == id){
                customers.at(i)->accountNums.push_back(accounts.size()+1);
                customers.at(i)->addAccount(cTemp);
            }
        }
        accounts.push_back(cTemp);
    }
    //make savings account
    else if(type == "s" || type == "S"){
        Savings* sTemp = new Savings();
        sTemp->setBalance(balance);
        sTemp->setDate(currentDate);
        sTemp->setID(accounts.size()+1);
        for(unsigned i = 0; i < customers.size(); i++){
            if(customers.at(i)->getID() == id){
                customers.at(i)->accountNums.push_back(accounts.size()+1);
                customers.at(i)->addAccount(sTemp);
            }
        }
        accounts.push_back(sTemp);
    }
    //make certificate of deposit account
    else if(type == "cd" || type == "CD"){
        Certificate_of_Deposit* cdTemp = new Certificate_of_Deposit();
        cdTemp->setBalance(balance);
        cdTemp->setDate(currentDate);
        cdTemp->setID(accounts.size()+1);
        Date d;
        out << "Maturity Date: ";
        in >> d;
        cdTemp->setMaturityDate(d);
        for(unsigned i = 0; i < customers.size(); i++){
            if(customers.at(i)->getID() == id){
                customers.at(i)->accountNums.push_back(accounts.size()+1);
                customers.at(i)->addAccount(cdTemp);
            }
        }
        accounts.push_back(cdTemp);
    }
}

//Takes in transaction information and creates a new transaction.
//TODO: Safe input handling
void BankManager::submitTransaction(){
    string input;
    int id; double a; char type; string location; Date d;   
    Transaction* trans = new Transaction();
    out << "Account number: ";
    in >> id;
    trans->setAccountID(id);
    out << "Type (w)ithdrawl or (d)eposit: ";
    in >> type;
    trans->setType(type);
    out << "Amount: ";
    in >> a;
    trans->setAmount(a);
    out << "Location: ";
    //in >> location;
    getline(in, location);
    getline(in, location);
    trans->setLocation(location);
    out << "Date MM/DD/YYYY: ";
    in >> d;
    trans->setDate(d);
    transactions.push_back(trans);
	for (unsigned i = 0; i < accounts.size(); i++){
            if (accounts.at(i)->getID() == id){
                accounts.at(i)->addTransaction(trans);
            }
	}
    out << "Transaction added.";
}

void BankManager::customerTransaction(char type){
    bool submit;
    int id; double a; 
    Transaction* trans = new Transaction();
    out << "Account number: ";
    in >> id;   
    for (unsigned i = 0; i < accounts.size(); i++){
        if(id == accounts.at(i)->getID()){
            for(unsigned j = 0; j < currentCustomer->accountNums.size(); j++){
                if(id == currentCustomer->accountNums.at(j)){
                    submit = true;
                }
            }
        }
    }
    if(!submit){
        out << "Not your account sucka";
        return;
    }
    trans->setAccountID(id);
    out << "Amount: ";
    in >> a;
    trans->setType(type);
    trans->setAmount(a);
    trans->setLocation(" bank");
    trans->setDate(currentDate);
    transactions.push_back(trans);
	for (unsigned i = 0; i < accounts.size(); i++){
            if (accounts.at(i)->getID() == id){
                accounts.at(i)->addTransaction(trans);
            }
	}
    out << "Transaction added.";
}