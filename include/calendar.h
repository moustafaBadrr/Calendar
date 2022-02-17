#ifndef CALENDAR_H
#define CALENDAR_H

#include "DayAppointment.h"

class calendar
{
private:
    // pointer array of days objects take from DayAppointment class to make a week contain many days that contain appointments
    DayAppointment * days;
    int numOfDays;
public:
    calendar(); // default constructor
    calendar(DayAppointment d[], int n); //parameterized constructor take the data
    calendar(calendar &cal);    //copy constructor
    calendar operator=(calendar cal1);
    DayAppointment& operator[](int index);// overloaded operator to take a day
    void delete_day(int day_number);//to delete day from week
    void equal_two_days(int day1,int day2); // to equal two days
    void add_appointment_a_specific_day(DayAppointment& app, int index); //to add appointment to a specific day
    friend istream& operator>> (istream& in, calendar &cal);// overloaded istream to take the data from user
    friend ostream& operator<<(ostream& out, calendar &cal);// overloaded ostream to display the data to user
};

#endif // CALENDAR_H
