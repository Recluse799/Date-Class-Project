// Date - Class Implementation file
// Date.cpp

               // remember, can use #ifndef PARKEDCAR_H , #define PARKEDCAR_H, #endif // PARKEDCAR_H

#include <string>  //
#include "Date.h"
#include <iostream>
#include "Month.h"


const int daysPerMonth = 12;  //constant for the nummber of months with days


using namespace std;

Date::Date() 
{
    month = 1;  // Default to January
    day = 1;
    year = 1930;
} // Default constructor: sets date to 1/1/1930

//Overloaded constructor w/ parameter   
Date::Date(int Mon, int Day, int Year) : month(Mon) //: month(Mon), day(Day), year(Year)
{
    
    {
        setDate(Mon, Day, Year);
    }
    

}

// set Day
void Date::setDate(int Mon, int Day, int Year)
{
    if (ValidDate(Mon, Day, Year))
    {
        month.setMonthNumber(Mon);
        day = Day;
        year = Year;
    }
    else
    {
        cout << "Invalid date entered. Defaulting to 1/1/1930." << endl;
        month.setMonthNumber(1);
        day = 1;
        year = 1930;
    }
}



int Date::daysInMon(int Mon, int Year) const // helper function to determine the numb of days in a specific month
{
    if (Mon < 1 || Mon > 12) return 0; // Invalid month, array to store the number of days in ea. mon for a non-leap year

    static const int daysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (Mon == 2 && LeapYear(Year))
    {
        return 29; // February in a leap year
    }

    return daysPerMonth[Mon - 1];
}

// Check if Leap Year
bool Date::LeapYear(int y) const
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}




// Getters , Pre condition: get month check to see if digit
//string Employee::getname() const { return name.empty() ? "No Name Provided" : name; } //validation


int Month::getMonthNumber()const  // validation Std library function to check if a character is a digit
{
    return monthNumber;
    
} 

string Month::getMonthName() const {
    return name();
}
   

int Date::getDay()const  // validation Std library function to check if a character is a digit
{
    
    return day; // If valid, return the original employee number
    
} 

//Pre condition : get month check to see if digit 
int Date::getYear()const  // validation Std library function to check if a character is a digit
{
    
     return year; // If valid, return the original employee number
    
}  
bool Date::ValidDate(int Mon, int Day, int Year) const
{
    if (Mon < 1 || Mon> 12) return false; // Invalid month
    if (Day < 1 || Day > daysInMon(Mon, Year)) return false; // Invalid day
    if (Year < 1) return false; // Invalid year
    return true;
}

// Begins inline member functions, 

/// Postcondition: r
 //Postcondition: r

// Print date in format: 12/25/2021
void Date::printNumeric() const
{
    cout << month.getMonthNumber() << "/" << day << "/" << year << endl;
}

// Print date in format: December 25, 2021
void Date::printLongFormat() const
{
    cout << getMonthName () << " " << day << ", " << year << endl;
}

// Print date in format: 25 December 2021
void Date::printDayFirstFormat() const
{
    cout << day << " " << getMonthName << " " << year << endl;
}



/*##include "Date.h"

// Default Constructor
Date::Date()
{
    day = 1;
    month = Month("January");  // Default to January
    year = 2000;
}

// Overloaded Constructor: Day, Month (string), Year
Date::Date(int d, string m, int y)
{
    month = Month(m);  // Use Month class to validate month name
    setDay(d);         // Validate day
    setYear(y);
}

// Overloaded Constructor: Day, Month (int), Year
Date::Date(int d, int m, int y)
{
    month = Month(m);  // Use Month class to validate month number
    setDay(d);
    setYear(y);
}

// Set Day
void Date::setDay(int d)
{
    if (d >= 1 && d <= daysInMonth(month.getMonthNumber(), year))
        day = d;
    else
    {
        cout << "ERROR: Invalid day for " << month.getMonthName() << ". Defaulting to 1.\n";
        day = 1;
    }
}

// Set Month by Number
void Date::setMonth(int m)
{
    month = Month(m);
}

// Set Month by Name
void Date::setMonth(string m)
{
    month = Month(m);
}

// Set Year
void Date::setYear(int y)
{
    year = y;
}

// Get Day
int Date::getDay() const
{
    return day;
}

// Get Month Name
string Date::getMonthName() const
{
    return month.getMonthName();
}

// Get Month Number
int Date::getMonthNumber() const
{
    return month.getMonthNumber();
}

// Get Year
int Date::getYear() const
{
    return year;
}

// Print the Date
void Date::printDate() const
{
    cout << getMonthName() << " " << day << ", " << year << endl;
}

// Check if Leap Year
bool Date::isLeapYear(int y) const
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

// Days in a Month
int Date::daysInMonth(int m, int y) const
{
    if (m == 4 || m == 6 || m == 9 || m == 11)
        return 30;
    else if (m == 2)
        return isLeapYear(y) ? 29 : 28;
    else
        return 31;
}
#include "Date.h"

int main()
{
    Date date1;  // Default date
    cout << "Default date: ";
    date1.printDate();

    // Set date using month name
    Date date2(29, "February", 2024);
    cout << "Leap Year Date: ";
    date2.printDate();

    // Set date using month number
    Date date3(31, 4, 2024);  // Invalid day for April
    cout << "Invalid day for April: ";
    date3.printDate();

    // Increment the month
    Month m("December");
    cout << "Month before increment: " << m << endl;
    ++m;
    cout << "Month after increment: " << m << endl;

    return 0;
}


}*/