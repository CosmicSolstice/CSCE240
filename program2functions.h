//Written by DJB
//Starting to see how similar this is to java and it's nice :)
#ifndef PROGRAM2FUNCTIONS_H
#define PROGRAM2FUNCTIONS_H

//declare the functions
//leap year
bool LeapYear(int year);

//last day of the month
int LastDayOfMonth(int month, int year = 0);

//Valid date
bool ValidDate(int month, int day, int year);

//Next date
void NextDate(int &month, int &day, int &year);

//Previous date
void PreviousDate(int &month, int &day, int &year);
#endif