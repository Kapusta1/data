#include <iostream>
#include <sstream>
#include <string>
#include "smart_pointer.h"
#include <memory>

using namespace std;

class Date
{
private:
	int Day;
	int Month;
	int Year;

	string DateInString;
public:
	Date(int InputDay, int InputMonth, int InputYear) :
		Day(InputDay), Month(InputMonth), Year(InputDay) {};
	Date & operator++()
	{
		++Day;
		return *this;
	}
	Date& operator--()
	{
		--Day;
		return *this;
	}

	Date operator++(int)
	{
		Date Copy(Day, Month, Year);
		++Day;
		return Copy;
	}
	Date operator--(int)
	{
		Date Copy(Day, Month, Year);
		--Day;
		return Copy;
	}
	operator const char* ()
	{
		ostringstream formattedDate;
		formattedDate << Day << " / " << Month << " / " << Year;

		DateInString = formattedDate.str();
		return DateInString.c_str();
	}

	void DisplayDate()
	{
		cout << Day << " / " << Month << " / " << Year << endl;
	}
};

int main()
{
	smart_point<int> pDynamic(new int);
	*pDynamic = 42;

	cout << "Integer value is: " << *pDynamic << endl;

	smart_point<Date> pHoliday(new Date(25, 11, 2011));
	cout << "The new instace of date contrains: ";

	pHoliday->DisplayDate();
	return 0;
}
