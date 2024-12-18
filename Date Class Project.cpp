// Date Class Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "Date.h"


using namespace std;

int main()
{
	cout << "Create a date object from the default constructor\n";
	Date dateDefault;
	cout << dateDefault.getMonthNumber() << " /  " << dateDefault.getDay() << " /  " << dateDefault.getYear() << endl;
	dateDefault.printNumeric();

	cout << "Create a date object from the default constructor\n";
	Date dateDefault;
	dateDefault.printNumeric();  // Print default date in numeric format

	cout << "\nCreate a date object with specific values\n";
	Date customDate(12, 25, 2021);  // Example: Christmas
	customDate.printLongFormat();  // Print in long format
	customDate.printDayFirstFormat();  // Print in day-first format

	cout << "\nTesting invalid date\n";
	Date invalidDate(13, 32, 2022);  // Invalid date
	invalidDate.printNumeric();

	
	return 0;
}

	/* << "Create a Month object from the name constructor ((March)\n";
	Month mName("March");
	cout << mName.getMonthName() << "    " << mName.getMonthNumber() << endl << endl;
	cout << endl;

	cout << "Create a Month object from the number constructor (10)\n";
	Month mNum(10);
	cout << mNum.getMonthName() << "    " << mNum.getMonthNumber() << endl << endl;

	cout << "Test set name with bad input (OCT)\n";
	Month m;
	m.setMonthName("OCT");
	cout << m.getMonthName() << "    " << m.getMonthNumber() << endl << endl;

	cout << "Test set number with bad input (0)\n";
	m.setMonthNumber(0);
	cout << m.getMonthName() << "    " << m.getMonthNumber() << endl << endl;

	cout << "Test setters and getters with good inputs\n";
	m.setMonthName("July");
	cout << m.getMonthName() << endl;
	cout << m.getMonthNumber() << endl << endl;

	m.setMonthNumber(2);
	cout << m.getMonthName() << endl;
	cout << m.getMonthNumber() << endl << endl;

	cout << "Test the prefix++ operator.\n";
	m.setMonthName("December");
	cout << "Before pre-increment: " << m.getMonthName() << endl;
	++m;
	cout << "After pre-increment: " << m << endl << endl;

	cout << "Test the postfix++ operator\n";
	cout << "Before post-increment: " << m << endl;
	m++;
	cout << "After post-increment: " << m << endl << endl;

	cout << "Test the prefix-- operator\n";
	m.setMonthName("January");
	cout << "Before pre-decrement: " << m << endl;
	--m;
	cout << "After pre-decrement:  " << m << endl;

	cout << "Test the postfix-- operator.\n";
	cout << "Before post-decrement: " << m << endl;
	m--;
	cout << "After post-decrement: " << m << endl << endl;

	cout << "Test stream extraction operator.\n";
	cout << "Enter a bad month name: ";
	cin >> mDefault;
	cout << "New month name is: " << mDefault << endl << endl;

	cout << "Enter a good month name: ";
	cin >> mDefault;
	cout << "New month name is: " << mDefault << endl << endl;*/


	






/* #ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <array>

class Date {
private:
    int day;
    int month;
    int year;

    // Helper functions
    bool isValidDate(int month, int day, int year) const;
    bool isLeapYear(int year) const;
    int daysInMonth(int month, int year) const; 

public:
    // Constructors
    Date(); // Default constructor: sets date to 1/1/1930
    Date(int month, int day, int year); // Parameterized constructor with validation

    // Setters
    void setDate(int month, int day, int year);

    // Getters
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Print functions
    void printFormat1() const; // 12/25/2021
    void printFormat2() const; // December 25, 2021
    void printFormat3() const; // 25 December 2021

    // Overloaded operators
    Date& operator++();       // Prefix increment
    Date operator++(int);     // Postfix increment
    Date& operator--();       // Prefix decrement
    Date operator--(int);     // Postfix decrement
    int operator-(const Date& other) const; // Difference in days
    friend std::ostream& operator<<(std::ostream& out, const Date& date); // Output stream
    friend std::istream& operator>>(std::istream& in, Date& date);       // Input stream
};

#endif
Key Member Function Behavior
Constructors:

Default constructor initializes the date to 1/1/1930.
Parameterized constructor validates the input using isValidDate().
Validation:

isValidDate() ensures the date is valid based on the month, day, and leap year rules.
Leap Year Check:

isLeapYear() checks if a year is divisible by 4 and not divisible by 100 unless also divisible by 400.
Increment/Decrement Operators:

Handle transitions between months and years correctly, such as:
Incrementing 12/31/2024 results in 1/1/2025.
Decrementing 1/1/2025 results in 12/31/2024.
Subtraction Operator:

Calculates the number of days between two dates using a date difference algorithm.
Input/Output Operators:

Overloads >> to prompt for date input, validating user input.
Overloads << to output the date in Month Day, Year format (e.g., April 18, 2018).
Test Plan
Default Constructor Test:

Create a Date object using the default constructor.
Display the date in format 12/25/2021.
Parameterized Constructor Test:

Create a Date object with 12, 25, 2021.
Display the date in format December 25, 2021.
Set Date and Display:

Use setDate(25, 12, 2021) and display using 25 December 2021.
Invalid Date Tests:

Call setDate(13, 45, 2018), setDate(4, 31, 2000), and setDate(2, 29, 2009).
Confirm that none of these dates are accepted.
Date Difference Calculation:

Set Date1 to 4/10/2014 and Date2 to 4/18/2014.
Verify Date2 - Date1 returns 8.
Repeat with 2/2/2006 and 11/10/2003 to verify 815 days.
Pre/Post Increment and Decrement:

Set Date to 2/29/2008. Use pre-decrement (--Date) to ensure the date becomes 1/31/2008.
Use pre-increment (++Date) to confirm it returns to 2/29/2008.
Repeat with post-decrement (Date--) and post-increment (Date++).
Year Transition:

Set Date to 12/31/2024. Use post-increment to verify the transition to 1/1/2025.
Use post-decrement to confirm the transition back to 12/31/2024.
Repeat with pre-increment and pre-decrement.
Input and Output:

Use >> to input a date from the user (e.g., 4/15/2023).
Use << to output the same date in April 15, 2023 format.
*/