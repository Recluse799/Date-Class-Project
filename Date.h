// Date Class definition - header file

#ifndef DATE_H   /// only in header file, not implelmentation,
#define DATE_H  

//  remember, can use #ifndef DATE_H,#define DATE_H, #endif // DATE_H for guaranteed commpatibility, no ambiguity no file dependency

#include <iostream>
#include <string>
#include <array>
#include "Month.h"

using namespace std;

class Date
     
{
public:

    Date();          // Default constructor: sets date to 1/1/1930

    Date(const int Mon, const int Day, const int Year);    
    
    
    //int month, int day, int year parameters and validate
    /* constructor declared with initialization list, constructor definition cannot be
    included in the headerfile.*/

   

    // Accessors , Pre-condition: gets Date variables
    //Post condition: hold Date month, day, and year  
    int getMonthNumber() const;
    string getMonthName () const;
    int getDay() const;
    int getYear()const;

    // Mutatior, Pre-condition: mutators gets variables
    //Post condition: hold  name, number and hire date
    void setDate(int month, int day, int year);
    

    // Overloaded constructor // Helper function to validate, Overloaded constructor
    bool ValidDate(int month, int day, int year) const;

    // leap year function
    bool LeapYear(int year) const;// Helper function to check leap year

    // determine days in a month
    int daysInMon(int month, int year) const; // Function to get days in a month
     
    // Print functions

    void printNumeric() const; // 12/25/2021
    void printLongFormat() const; // December 25, 2021
    void printDayFirstFormat() const; // 25 December 2021 
    
    ~Date() {} // Destructor (currently empty)

    //Pre-condition: acccepts employee test variables
    //Post condition: print employee name,number, and hire date

protected:    // allows inherited to see, but not public
    Month month;
    int day;
    int year;

   
};

#endif
