/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 4 Question 1
*/
#include <iostream>
#include "Clock.h"
using std::cout;
using std::cin;
using std::endl;

void Clock::setHour(int const myHour)       { hour = myHour; }

void Clock::setMinute(int const myMinute)   { minute = myMinute; }

void Clock::setSeconde(int const mySeconde) { seconde = mySeconde; }

const int Clock::getHour() const    { return hour; }

const int Clock::getMinute() const  { return minute; }

const int Clock::getSeconde() const { return seconde; }

Clock::Clock(int myHour = 0, int myMinute = 0, int mySeconde = 0) // constructor
{
	try
	{
		if (mySeconde > 59)                              // if the seconde is not correct
			throw "Invalid time - more than 60 seconds.";
		else if (mySeconde < 0)
			throw "Invalid time - negative number of seconds.";
		else
			seconde = mySeconde;                         // initialize it in the real seconde

		if (myMinute > 59)                               // if the minute is not correct
			throw "Invalid time - more than 60 minutes.";
		else if (myMinute < 0)
			throw "Invalid time - negative number of minutes.";
		else
			minute = myMinute;                           // initialize it in the real minute

		if (myHour > 23)                                 // if the hour is not correct
			throw "Invalid time - more than 24 hours.";
		else if (myHour < 0)
			throw "Invalid time - negative number of hours.";
		else
			hour = myHour;                               // initialize it in the real hour
	}
	catch (const char* msg)
	{
		cout << "Wrong time format. " << msg;            // Throws an exception
		hour = 0;                                        // Initializes the time to 0
		minute = 0;
		seconde = 0;

	}
}

Clock::Clock(const Clock& time) // copy-constructor
{
	seconde = time.seconde;
	minute = time.minute;
	hour = time.hour;
}

Clock& Clock::operator+=(int mySeconde) // add a number of secondes
{
	if (mySeconde < 0)          // If the seconds are negative 
		Clock(0, 0, mySeconde); // send to the builder and there he will get an error
	else
	{
		seconde += mySeconde;   // We will add in seconds
		minute += seconde / 60; // Put the extra seconds in minutes
		seconde %= 60;                  // The number of seconds in this minute
		hour += minute / 60;    // Put the extra minutes in hous
		minute %= 60;                   // The number of minute in this hour
		hour %= 24;                     // The number of hour in this day
	}
	return *this;
}

ostream& operator<<(ostream& os, Clock p)
{
	os  << setw(2) << setfill('0') << p.hour << ":"    // If there is only one digit the second digit will be 0 by default
		<< setw(2) << setfill('0') << p.minute << ":"
		<< setw(2) << setfill('0') << p.seconde;
	return os;
}

istream& operator>>(istream& is, Clock& p)
{
	is >> p.hour >> p.minute >> p.seconde;

	Clock(p.hour, p.minute, p.seconde); // Sends the values for testing in a constructor
	
	return is;
}