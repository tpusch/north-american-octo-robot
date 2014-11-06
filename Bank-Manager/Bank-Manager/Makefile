CXX = g++
CC  = g++

all:			    main

main:			    main.cpp BankManager.o Certificate_of_Deposit.o Customer.o Savings.o Checking.o Account.o Transaction.o Date.o
			    $(CXX) main.cpp BankManager.o Certificate_of_Deposit.o Customer.o Savings.o Checking.o Account.o Transaction.o Date.o -o main

BankManager.o:		    BankManager.cpp BankManager.h Account.h Customer.h Transaction.h
			    $(CXX) -c BankManager.cpp
	
Certificate_of_Deposit.o:   Certificate_of_Deposit.cpp Certificate_of_Deposit.h Account.h
			    $(CXX) -c Certificate_of_Deposit.cpp
	
Customer.o:		    Customer.cpp Customer.h Account.h
			    $(CXX) -c Customer.cpp
	
Savings.o:		    Savings.cpp Savings.h Account.h
			    $(CXX) -c Savings.cpp

Checking.o:		    Checking.cpp Checking.h Account.h
			    $(CXX) -c Checking.cpp

Account.o:		    Account.cpp Account.h
			    $(CXX) -c Account.cpp

Transaction.o:		    Transaction.cpp Transaction.h
			    $(CXX) -c Transaction.cpp

Date.o:			    Date.cpp Date.h
			    $(CXX) -c Date.cpp

test:			    all
			    ./main < testCaseMJW.input
			    ./main < testCaseMDW.input

clobber:	
			    rm -f *.o core *.exe cbook