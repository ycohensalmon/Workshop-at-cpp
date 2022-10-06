/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 3 Question 2
*/
#include "Calendar.h"

Calendar& Calendar::check(Calendar& date)
{
	if (date.day > 30)      // When after the addition it turns out that there are more than 30 days a month
	{
		date.month += date.day / 30;   // add the number of months depending on the days added
		date.day %= 30;                // The real day of this month
	}

	int temp_month = date.month;       // (Save the number of months for continuation in case you need to add years)
	if (date.month > 12)               // When after the addition it turns out that there are more than 12 month a year
	{
		date.year += date.month / 12;  // add the number of years depending on the months added
		date.month %= 12;              // The real month of this year
	}

	if (date.year > 2099)              // When after the addition it turns out that the year is more than 2099
		date.year = 1920 + temp_month % 12 -1; // the real year (-1 because one year has already been added in the first place)

	return date;
}

void Calendar::setDay(int const myDay)     { day = myDay; }

void Calendar::setMonth(int const myMonth) { month = myMonth; }

void Calendar::setYear(int const myYear)   { year = myYear; }

const int Calendar::getDay() const         { return day; }

const int Calendar::getMonth() const       { return month; }

const int Calendar::getYear() const        { return year; }

Calendar& Calendar::setDate(const int myDay, const int myMonth, const int myYear)
{
	bool flag = true;

	if (myDay < 1 || myDay > 30)        // if the day is not correct
	{
		cout << "Error day" << endl;
		flag = false;
	}

	if (myMonth < 1 || myMonth > 12)    // if the month is not correct
	{
		cout << "Error month" << endl;
		flag = false;
	}

	if (myYear < 1920 || myYear > 2099) // if the year is not correct
	{
		cout << "Error year" << endl;
		flag = false;
	}

	if (flag == true)                   // When all is well then you will change
	{
		day = myDay;
		month = myMonth;
		year = myYear;
	}
	return *this;
}

Calendar::Calendar(int myDay = 1, int myMonth = 1, int myYear = 1920) // constructor
{
	if (myDay < 1 || myDay > 30)        // if the day is not correct
	{
		cout << "Error day" << endl;
		day = 1;          // initialize it in 1
	}
	else
		day = myDay;      // initialize it in the real day

	if (myMonth < 1 || myMonth > 12)    // if the month is not correct
	{
		cout << "Error month" << endl;
		month = 1;        // initialize it in 1
	}
	else
		month = myMonth;  // initialize it in the real month

	if (myYear < 1920 || myYear > 2099) // if the year is not correct
	{
		cout << "Error year" << endl;
		year = 1920;      // initialize it in 9020
	}
	else
		year = myYear;    // initialize it in the real year
}

Calendar::Calendar(const Calendar& time) // copy-constructor
{
	day = time.day;
	month = time.month;
	year = time.year;
}

/*Calendar::Calendar(Calendar&& time) // move-constructor
{
	setDay(time.getDay());
	setMonth(time.getMonth());
	setYear(time.getYear());
}*/

void Calendar::print()const
{
	cout << day << "/" << month << "/" << year << endl;
}

Calendar& Calendar::operator++() // add one day prefix
{
	day++;

	*this = check(*this);       // Checks for abnormalities

	return *this;
}

Calendar Calendar::operator++(int const x)// add one day postfix
{
	Calendar temp = *this;
	day++;
	temp = check(temp);                   // Checks for abnormalities
	return temp;
}

Calendar& Calendar::operator+=(int myDay) // add a number of days
{
	while (myDay < 0)     // when the input is uncorrect
	{
		cout << "ERROR\n";
		cin >> myDay;
	}
	day += myDay;         // add the day

	*this = check(*this); // Checks for abnormalities

	return *this;
}

const bool Calendar::operator>(Calendar& time) const
{  // calcul if the original date is greater than the date entered
	if (time.year < year)
		return false;

	if (time.month < month)
		return false;

	if (time.day <= day)
		return false;

	return true;
}

const bool Calendar::operator<(Calendar& time) const
{  // calcul if the original date is smaller than the date entered
	if (operator>(time) == false)  // When the previous function is incorrect then here it is true
		return true;
	else
		return false;
}

const bool Calendar::operator==(Calendar& time) const  // Checks if the dates are equal
{
	if (time.year == year && time.month == month && time.day == day)
		return true;
	else
		return false;
}