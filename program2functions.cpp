//Writen by DJB
#include <iostream>
using std:: cout;
using std:: endl;
using std:: cin;
#include "program2functions.h"
//similar to java, well place our functions her to call in our program
//Check if leap year
bool LeapYear(int year){
    if(year <= 0)
    return false;
    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)){
        return true;
    }
    //otherwise, this isn't a leap year
    return false;
}

//Last day of the month
int LastDayOfMonth(int month, int year){
    //checks for valid input
    if (month < 1 || month > 12) return 0;//invalid month
    //and now, my favorite tool.. Behold the switch
    //we'll use this to determin each month's days
    switch (month){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31; // Jan, Mar, May, ...

        case 4: case 6: case 9: case 11:
        return 30; // Apr, Jun, Sept, ...

        case 2: //feb
        if ( year <= 0) return 0; // invalid year
        return LeapYear(year) ? 29 : 28; 

        default:
            return 0; //invalid month
    }
}

//check dates
bool ValidDate(int month, int day, int year){
    if (year <= 0) return false;//check if year is valid
    int lastDay = LastDayOfMonth(month, year);
    return (day > 0 && day <= lastDay);
    
}

//update the formatt of the current day to the day after
void NextDate(int &month, int &day, int &year){
    //lets check if valid first
    if (!ValidDate(month, day, year)) return;//effectively skips this
    //increment day
    day++;

    //end of the month
    int lastDay = LastDayOfMonth(month, year);
    if (day > lastDay){
        day = 1;
        month++;

        //end of the year
        if (month > 12){
            month = 1;
            year++;
        }
    }
}

//update the date to the day before
void PreviousDate(int &month, int &day, int &year){
    //decrease the day
    day--;
    //beginning of month
    if (day < 1){
        month--;
        
        //beginning of year
        if (month < 1){
            month = 12;
            year--;
        }
        day = LastDayOfMonth(month, year);
    }
}