#include <iostream>
#include <sstream>
#include <string>
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
	Date Holiday(25, 12, 2011);

	cout << "The date object is initialised to: ";
	Holiday.DisplayDate();

	++Holiday;

	cout << "Date after prefix-increment is: ";

	Holiday.DisplayDate();
	--Holiday;
	--Holiday;

	cout << "Date after two prefix-decrements is: ";
	Holiday.DisplayDate();
	return 0;
}
