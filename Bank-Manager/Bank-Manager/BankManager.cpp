#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>

#include "BankManager.h"

using std::istream;
using std::ostream;

using std::endl;
using std::string;

enum BankManager::state {submit_transaction, list_accounts, print_statement, print_savings, print_checking, print_cd, list_customers, save, exit, menu, default};

BankManager::BankManager(istream& inStream, ostream& outStream)
	:in(inStream),
	out(outStream),
	running(true)
{
	currentState = state::menu;
	currentCustomer = NULL;
}

BankManager::~BankManager()
{

}

void BankManager::run(){
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
	case state::menu:
		printHeader();
		printMenu();
		break;
	case state::submit_transaction:
		out << "1. Submit a transaction\n";
		break;
	case state::list_accounts:
		out << "2. List all accounts\n";
		break;
	case state::print_statement:
		out << "3. Print a Monthly Statement\n";
		break;
	case state::print_savings:
		out << "4. Print Savings Value\n";
		break;
	case state::print_checking:
		out << "5. Print Checking Value\n";
		break;
	case state::print_cd:
		out << "6. Print CD Value\n";
		break;
	case state::list_customers:
		out << "7. List all Customers\n";
		break;
	case state::save:
		out << "8. Save\n";
		break;
	case state::exit:
		running = false;
		break;
	case state::default:
		out << "Enter a valid input\n";
		currentState = state::menu;
		break;
	default:
		out << "Enter a valid input\n";
		currentState = state::menu;
		break;
	}
}

void BankManager::printMenu(){
	//out << "\nWELCOME TO ALL POWERFUL BANK, PLEASE MAKE A SELECTION\n" << endl
	out << "Type \"help\" at any time to return to this menu\n"
		<< "Type \"quit\" at any time to stop the program\n\n"
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
			<< "Current Customer: "; 
		currentCustomer->printName(out);
		out << "\n"
			<< "------------------------------------\n" << endl;
	}
}

void BankManager::handleInput(){
	in >> choice;
	if (!in){
		currentState = state::default;
		in.clear();
		in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	
	//if (currentState == state::menu){
		menuInput(choice);		
	//}

	//Always available
	if (choice == "0" || choice == "help"){
		currentState = state::menu;
	}
	else if (choice == "quit" || choice == "exit"){
		currentState = state::exit;
	}
}

void BankManager::menuInput(string choice){
	if (choice == "0" || choice == "help"){
		currentState = state::menu;
	}
	else if(choice == "1"){
		currentState = state::submit_transaction;
	}
	else if (choice == "2"){
		currentState = state::list_accounts;
	}
	else if (choice == "3"){
		currentState = state::print_statement;
	}
	else if (choice == "4"){
		currentState = state::print_savings;
	}
	else if (choice == "5"){
		currentState = state::print_checking;
	}
	else if (choice == "6"){
		currentState = state::print_cd;
	}
	else if (choice == "7"){
		currentState = state::list_customers;
	}
	else if (choice == "8"){
		currentState = state::save;
	}
	else if (choice == "9" || choice == "quit" || choice == "exit"){
		currentState = state::exit;
	}
	else{
		currentState = state::default;
	}
}
