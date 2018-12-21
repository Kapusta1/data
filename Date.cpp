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
	Date & operator++(){++Day; return *this;}
	Date & operator--(){--Day; return *this;}

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

	void operator +=(int DaysToAdd){Day += DaysToAdd;}
	void operator -=(int DaysToAdd) { Day -= DaysToAdd; }

	bool operator == (const Date & compareTo)
	{
		return ((Day == compareTo.Day) && (Month == compareTo.Month) && (Year == compareTo.Year));
	}
	bool operator != (const Date & compareTo)
	{
		return !(this->operator==(compareTo));
	}

	bool operator < (const Date & compareTo)
	{
		if (Day < compareTo.Day)
			return true;
		else
			if (Month < compareTo.Month)
				return true;
			else
				if (Year < compareTo.Year)
					return true;
				else
					return false;
	}
	bool operator <= (const Date & compareTo)
	{
		if (this->operator==(compareTo))
			return true;
		else
			return this->operator<(compareTo);
	}
	bool operator > (const Date & compareTo)
	{
		return !(this->operator<(compareTo));
	}
	bool operator >= (const Date & compareTo)
	{
		if (this->operator==(compareTo))
			return true;
		else
			return this->operator>(compareTo);
	}
	void DisplayDate()
	{
		cout << Day << " / " << Month << " / " << Year << endl;
	}
};

int main()
{
	Date Holiday1(25, 11, 2011);
	Date Holiday2(31, 11, 2011);

	cout << "Holiday 1 is: ";
	Holiday1.DisplayDate();
	cout << "Holiday 2 is: ";
	Holiday2.DisplayDate();

	if (Holiday1 < Holiday2)
		cout << "operator < : Holliday1 happens first" << endl;
	

	if(Holiday1>Holiday2)
		cout << "operator > : Holliday2 happens later" << endl;

	if(Holiday1<=Holiday2)
		cout << "operator <= : Holliday1 happens on or before Holliday2" << endl;

	if (Holiday2 <= Holiday1)
		cout << "operator >= : Holliday2 happens on or before Holliday1" << endl;

	return 0;
}
