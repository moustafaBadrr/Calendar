#ifndef DAYAPPOINTMENT_H
#define DAYAPPOINTMENT_H

#include "appointment.h"

class DayAppointment
{
private:
        // pointer array of appointments objects take from appointment class to make a day contain many appointments
    appointment * appointments;
    int numOfAppointments;
    string weekDay;
public:
    DayAppointment(); // default constructor
    DayAppointment(int n, string w,appointment app[]); // parameterized constructor take the data
    DayAppointment(const DayAppointment &app); //copy constructor to equal two objects
    virtual ~DayAppointment(); // destructor
    DayAppointment operator=(DayAppointment& app); // overloaded operator to equal two objects
    bool operator== (DayAppointment &app);  // overloaded operator to compare two days for equal or not
    bool operator!= (DayAppointment &app);  // overloaded operator to compare two days for equal or not
    appointment& operator [](int index);    // overloaded operator to take an index from array to do anything like displaying
    void delete_appointment();  //delete an appointment
    friend istream& operator>> (istream& in, DayAppointment &din); // overloaded istream to take the data from user
    friend ostream& operator<< (ostream& out, DayAppointment &dout);// overloaded ostream to display the data to user
};

#endif // DAYAPPOINTMENT_H
