#include "Checking.h"

using namespace std;

istream& operator>>(istream& input, Checking& checking){
    input >> checking.accountID >> checking.dateOpened >> checking.balance;
    return input;
}

void Checking::operator =(Account& account){
    balance = account.getBalance();
    accountID = account.getID();
    dateOpened = account.getDate();
    type = account.getType();
}

//creates a number of Monthly Fee transactions and adds them to transactions vector
void Checking::monthlyChores(int numMonths){
    //cerr << "in mc" << endl;
    int theMonth = dateOpened.getMonth() + 1;
    int theYear = dateOpened.getYear();
    int theDay = dateOpened.getDay();
    //Loop from 0 to numMonths. Creates new transactions for each monthly fee and pushes them back
    for (int i = 0; i < numMonths; i++){
        Transaction* action = new Transaction();
        action->setAccountID(accountID);
        action->setAmount(20);
        action->setLocation("bank");
        action->setType('f');
        
        if (theMonth == 13){
            theMonth = 1;
            theYear++;
        }
        Date date;
        date.setDate(theMonth, theDay, theYear);
        action->setDate(date);
        transactions.push_back(action);
        //cerr << action;
        theMonth++;
    }
    sortTransactions();
}

void Checking::save(ostream& output){
    output << type << " " << accountID << " " << dateOpened <<  " " << balance;
}