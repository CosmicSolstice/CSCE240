//Written by DJB
#include <iostream>
using std:: cout;
using std:: cin;
using std:: endl;
#include "program2functions.h"

//count days between two dated

int DaysBetweenDates(int startMonth, int startDay, int startYear,
int endMonth, int endDay, int endYear){
    int days = 0;

    //Iterate from the first day to second, counting days
    while (!(startMonth == endMonth && startDay == endDay && startYear == endYear)){
        NextDate(startMonth, startDay, startYear);
        days++;
    }
    return days;
}

int main(){
    int month1, day1,year1;
    int month2, day2, year2;
    char separator; // getting fancy with special characters

    //ask for user input 
    cout << "Enter the first date in the following formatt (MM/DD/YYYY)";
    cin >> month1 >> separator >> day1 >> separator >> year1;

    cout << "Enter the second date (MM/DD/YYYYY)";
    cin >> month2 >> separator >> day2 >> separator >> year2;

    // Check dates
    if (!ValidDate(month1, day1, year1)){
        cout << "First date is invalid" << endl;
        return 0;
    }

    if (!ValidDate(month2, day2, year2)){
        cout << "Second date invalid" << endl;
        return 0; 
    }

    // math between dates
    int days; //declare our variable
    //check if equal
    if(month1 == month2 && day1 == day2 && year1 == year2){
        cout << "The dates are the same :D" << endl;
        return 0;
    }
    //I don't like this logic but I'm too short on time to go back now
    //There's probably a better...
    else if (year1 < year2 || (year1 == year2 && (month1 < month2 || (month1 == month2 && day1 < day2)))){
        days = DaysBetweenDates(month1, day1, year1, month2, day2, year2);
        cout << "First date is " << days << " days before second date." << endl;
    }
    else{
        days = DaysBetweenDates(month2, day2, year2, month1, day1, year1);
        cout << "First date is " << days << " days after second date." << endl;
    }

    return 0;
}