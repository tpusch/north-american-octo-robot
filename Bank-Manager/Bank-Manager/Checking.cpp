#include "Checking.h"

using namespace std;

void Checking::monthlyChores(int numMonths)
{
	int theMonth = dateOpened.getMonth() + 1;
	int theYear = dateOpened.getYear();
	int theDay = dateOpened.getDay();
	for (int i = 0; i < numMonths; i++)
	{
		Transaction action;
		action.setAccountID(accountID);
		action.setAmount(20);
		action.setLocation("bank");
		action.setType('f');
		if (theMonth == 13)
		{
			theMonth = 1;
			theYear++;
		}
		Date date;
		date.setDate(theMonth, theDay, theYear);
		action.setDate(date);
		transactions.push_back(action);
	}
}