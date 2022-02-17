#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "time.h"

class appointment
{
    // two objects from the time class to make an appointment
private:
    time start_time,end_time;
public:
    appointment(); // default constructor
    appointment(time s, time e); //parameterized constructor to take the data
    bool operator <= (appointment tsmallerequal);  // overloaded operators to compare between two appointments smaller & equal
    bool operator >= (appointment tgreaterequal);// overloaded operators to compare between two appointments greater & equal
    bool operator <  (appointment tsmaller);// overloaded operators to compare between two appointments smaller
    bool operator >  (appointment tgreater);// overloaded operators to compare between two appointments greater
    bool operator == (appointment tequal);// overloaded operators to compare between two appointments equal
    bool operator != (appointment tnotequal);// overloaded operators to compare between two appointments not equal
    friend istream& operator>>(istream &in, appointment & appin);// overloaded istream to take the data from user
    friend ostream& operator<<(ostream& out, appointment &appout);// overloaded ostream to display the data to user
};

#endif
