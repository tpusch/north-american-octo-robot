#include <iostream>

#include "BankManager.h"


int main(){

	BankManager bankManager = BankManager(std::cin, std::cout);
	bankManager.run();

	cin.get();
	return 0;
}