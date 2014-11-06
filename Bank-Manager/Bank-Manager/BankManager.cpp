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
		break;
	case 3:
		out << "3. Print a Monthly Statement\n";
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
		break;
	case 8:
		out << "8. Save\n";
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
		currentState = 10;
		in.clear();
		in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	
	//if (currentState == state::menu){
		menuInput(choice);		
	//}

	//Always available
	if (choice == "0" || choice == "help"){
		currentState = 0;
	}
	else if (choice == "quit" || choice == "exit"){
		currentState = 9;
	}
}

void BankManager::menuInput(string choice){
	if (choice == "0" || choice == "help"){
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
