
// Specification file for the Month class
#ifndef MONTH_H
#define MONTH_H


#include <iostream>
//#include "Date.h"



// Constant for the number of months
const int NUM_MONTHS = 12;

//class Month;   // Forward declaration.

ostream& operator<<(ostream&, Month&);
istream& operator>>(istream&, Month&);

using namespace std;

class Month
{
public:
    // Default constructor
    Month();

    // Overloaded constructor 
    Month(string);

    // Overloaded constructor
    Month(int);



    // Mutators
    void setMonthName(string);
    void setMonthNumber(int);

    // Accessors
    string getMonthName()
    {
        return name;
    }

    int getMonthNumber() const
    {
        return monthNumber;
    }

    // Overloaded operators

    Month operator++();     // Prefix ++
    Month operator++(int);  // Postfix ++
    Month operator--();     // Prefix --
    Month operator--(int);  // Postfix --

    friend ostream& operator<<(ostream&, Month&);
    friend istream& operator>>(istream&, Month&);
      
private:

    string name;            // To hold the name of the month
    int monthNumber;          // To hold the number of the month
    string months[NUM_MONTHS]; // To hold all the month names
    

    void initializeNames(); // Initializes the MyString array of names

};

#endif 