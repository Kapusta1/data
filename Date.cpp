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
		Day(InputDay), Month(InputMonth), Year(InputYear) {};
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

	Date operator +(int daysToAdd)
	{
		Date newDate(Day + daysToAdd, Month, Year);
		return newDate;
	}

	Date operator -(int daysToSub)
	{
		return Date(Day - daysToSub, Month, Year);
	}

	void DisplayDate()
	{
		cout << Day << " / " << Month << " / " << Year << endl;
	}
};

int main()
{
	Date Holiday(25, 11, 2011);

	cout << "Holliday on: ";
	Holiday.DisplayDate();

	Date PreviousHoliday(Holiday - 19);
	cout << "Previous holiday on: ";
	PreviousHoliday.DisplayDate();

	Date NextHoliday(Holiday + 6);
	cout << "Next holiday on: ";
	NextHoliday.DisplayDate();

	return 0;
}
