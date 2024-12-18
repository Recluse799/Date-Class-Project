// Implementation file for the Month class

#include "Month.h"



using namespace std;

Month::Month()  // Default constructor
{
    
    initializeNames(); // Initialize the array of month names.

    setMonthName(months[0]); // Set this object to January, the 1st month.
}

Month::Month(string n)  // Overloaded constructor  
{
    initializeNames();  // Initialize the array of month names.

    setMonthName(n);  // Set object to n
}


Month::Month(int num)  // Overloaded constructor  
{
    
    initializeNames();  // Initialize the array of month names.

    setMonthNumber(num);  // Set index to num
}

void Month::initializeNames()
{
    // Initialize the array of month names.  // initializeNames private member function *
    months[0] = "January"; months[1] = "February";  months[2] = "March";
    months[3] = "April";   months[4] = "May";       months[5] = "June";
    months[6] = "July";    months[7] = "August";    months[8] = "September";
    months[9] = "October"; months[10] = "November"; months[11] = "December";
}


void Month::setMonthName(string n)  // setMonthName member function 
{
    monthNumber = 0;

    for (int i = 0; i < 12; i++)
    {
        if (months[i] == n)
        {
            name = months[i];
            monthNumber = i + 1;
        }
    }

    if (monthNumber == 0)
    {
        cout << "ERROR: Invalid month.\n";
        name = "January";
        monthNumber = 1;
    }
}


void Month::setMonthNumber(int num)  // setMonthNumber member function  
{
    if (num < 1 || num > 12)
    {
        cout << "ERROR: Invalid month number.\n";
        name = "January";
        monthNumber = 1;
    }
    else
    {
        name = months[num - 1];
        monthNumber = num;
    }
}

Month Month::operator ++()  // Prefix ++ operator 
{
    if (monthNumber == 12)
    {
        monthNumber = 1;
        name = "January";
    }
    else
    {
        monthNumber++;
        name = months[monthNumber - 1];
    }

    return *this;
}

Month Month::operator ++(int)  // Postfix ++ operator  
{
    Month temp(monthNumber);

    if (monthNumber == 12)
    {
        monthNumber = 1;
        name = "January";
    }
    else
    {
        monthNumber++;
        name = months[monthNumber - 1];
    }

    return temp;
}

Month Month::operator --()  // Prefix -- operator  
{
    if (monthNumber == 1)
    {
        monthNumber = 12;
        name = "December";
    }
    else
    {
        monthNumber--;
        name = months[monthNumber - 1];
    }

    return *this;
}


Month Month::operator --(int) // Postfix -- operator   
{
    Month temp(monthNumber);

    if (monthNumber == 1)
    {
        monthNumber = 12;
        name = "December";
    }
    else
    {
        monthNumber--;

        name = months[monthNumber - 1];
    }

    return temp;
}

ostream& operator<<(ostream& strm, Month& obj) // Overloaded stream insertion operator (<<).     *
{
    strm << obj.name;
    return strm;
}

istream& operator>>(istream& strm, Month& obj) // Overloaded stream extraction operator (>>).    *
{
    // Validate user input
    strm >> obj.name;
    obj.setMonthName(obj.name);
    return strm;
}






/*#ifndef MONTH_H
#define MONTH_H

#include <iostream>
#include <string>
using namespace std;

const int NUM_MONTHS = 12;

class Month
{
public:
    // Default constructor (accepts integer as month number)
    Month(int monthNum = 1);

    // Overloaded constructor
    Month(string);

    // Mutators
    void setMonthName(string);
    void setMonthNumber(int);

    // Accessors
    string getMonthName() const { return name; }
    int getMonthNumber() const { return monthNumber; }

    // Overloaded operators
    Month operator++();     // Prefix ++
    Month operator++(int);  // Postfix ++
    Month operator--();     // Prefix --
    Month operator--(int);  // Postfix --

    // Stream insertion/extraction
    friend ostream& operator<<(ostream&, Month&);
    friend istream& operator>>(istream&, Month&);

private:
    string name;                // Holds the name of the month
    int monthNumber;            // Holds the number of the month (1-12)
    string months[NUM_MONTHS];  // Holds all the month names

    void initializeNames();  // Initializes the array of month names
};

#endif

// Implementation file for the Month class
#include "Month.h"

// Default constructor: Accept integer as the month number
Month::Month(int monthNum)
{
    initializeNames();  // Initialize month names array
    setMonthNumber(monthNum);  // Validate and set month number
}

// Overloaded constructor: Accept string month name
Month::Month(string n)
{
    initializeNames();
    setMonthName(n);
}

// Initialize the array of month names
void Month::initializeNames()
{
    months[0] = "January";   months[1] = "February"; months[2] = "March";
    months[3] = "April";     months[4] = "May";      months[5] = "June";
    months[6] = "July";      months[7] = "August";   months[8] = "September";
    months[9] = "October";   months[10] = "November"; months[11] = "December";
}

// Set the month by its name
void Month::setMonthName(string n)
{
    bool valid = false;
    for (int i = 0; i < NUM_MONTHS; i++)
    {
        if (months[i] == n)
        {
            name = months[i];
            monthNumber = i + 1;
            valid = true;
            break;
        }
    }

    if (!valid) // Invalid month name
    {
        cout << "ERROR: Invalid month name. Defaulting to January.\n";
        name = "January";
        monthNumber = 1;
    }
}

// Set the month by its number
void Month::setMonthNumber(int num)
{
    if (num >= 1 && num <= NUM_MONTHS)
    {
        monthNumber = num;
        name = months[num - 1];
    }
    else
    {
        cout << "ERROR: Invalid month number. Defaulting to January.\n";
        monthNumber = 1;
        name = "January";
    }
}

// Overloaded prefix ++ operator
Month Month::operator++()
{
    if (monthNumber == 12)
    {
        monthNumber = 1;
    }
    else
    {
        monthNumber++;
    }
    name = months[monthNumber - 1];
    return *this;
}

// Overloaded postfix ++ operator
Month Month::operator++(int)
{
    Month temp = *this;
    ++(*this);
    return temp;
}

// Overloaded prefix -- operator
Month Month::operator--()
{
    if (monthNumber == 1)
    {
        monthNumber = 12;
    }
    else
    {
        monthNumber--;
    }
    name = months[monthNumber - 1];
    return *this;
}

// Overloaded postfix -- operator
Month Month::operator--(int)
{
    Month temp = *this;
    --(*this);
    return temp;
}

// Overloaded << operator (stream insertion)
ostream& operator<<(ostream& strm, Month& obj)
{
    strm << obj.name;
    return strm;
}

// Overloaded >> operator (stream extraction)
istream& operator>>(istream& strm, Month& obj)
{
    string inputName;
    strm >> inputName;
    obj.setMonthName(inputName);
    return strm;
}
Key Fixes and Changes:
Default Constructor:

The default constructor now accepts an integer as the monthNumber with a default value of 1 (January).
cpp
Copy code
Month(int monthNum = 1);
Validation in setMonthNumber:

Added validation for the integer month input (1-12).
If invalid, defaults to January and provides an error message.
Validation in setMonthName:

Ensures that invalid month names default to January.
Stream Extraction (>>):

When inputting a month name, it validates it using setMonthName.
Example Usage
Here’s how you can use the Month class to accept an integer as the starting value:

cpp
Copy code
#include "Month.h"

int main()
{
    // Default Constructor
    Month m1;
    cout << "Default Month: " << m1 << endl;

    // Constructor with int
    Month m2(4);
    cout << "Month initialized to 4: " << m2 << endl;

    // Constructor with invalid int
    Month m3(15);
    cout << "Invalid Month (15): " << m3 << endl;

    // Increment and decrement
    cout << "Incremented Month: " << ++m2 << endl;
    cout << "Decremented Month: " << --m2 << endl;

    // Input month name
    Month m4;
    cout << "Enter a month name: ";
    cin >> m4;
    cout << "You entered: " << m4 << endl;

    return 0;
}*/
