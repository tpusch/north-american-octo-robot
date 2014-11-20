#include "Date.h"

//overload extraction operator
istream& operator>>(istream& input, Date& date)
{
    input >> date.month >> date.separator1 >> date.day >> date.separator2 >> date.year;
    return input;
}

//overload insertion operator
ostream& operator<<(ostream& output, const Date& date)
{
    output << date.month << date.separator1 << date.day << date.separator2 << date.year;
    return output;
}

//overload less than operator
bool Date::operator<(const Date& date) const
{
    if (year == date.year)
    {
        if (month == date.month)
        {
            return (day < date.day);
        }
        else
        {
            return (month < date.month);
        }
    }
    else
    {
        return (year < date.year);
    }
}

//overload equality operator
bool Date::operator==(const Date& date) const
{
    if (month == date.month && day == date.day && year == date.year)
    {
        return true;
    }
    return false;
}
void Date::setDate(int m, int d, int y)
{
	month = m;
	day = d;
	year = y;
	separator1 = '/';
	separator2 = '/';
}