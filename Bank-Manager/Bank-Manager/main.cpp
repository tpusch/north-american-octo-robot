#include <iostream>

#include "BankManager.h"


int main(){

	BankManager bm = BankManager(std::cin, std::cout);
	bm.run();

	return 0;
}