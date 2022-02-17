#include "DayAppointment.h"
#include <cstdlib>

DayAppointment::DayAppointment(){} //default constructor

DayAppointment::DayAppointment(int n, string w,appointment app[])
{
    numOfAppointments=n;
    weekDay=w;
    appointments=new appointment[numOfAppointments];
    for (int i=0; i<numOfAppointments; ++i)
    {
        appointments[i] = app[i];
    }
}

DayAppointment::DayAppointment(const DayAppointment &app)  // copy constructor
{
    weekDay=app.weekDay;
    numOfAppointments=app.numOfAppointments;
    appointments=new appointment[app.numOfAppointments];
    for (int i=0; i<app.numOfAppointments; ++i)
    {
        appointments[i] = app.appointments[i];
    }
}

DayAppointment DayAppointment:: operator=(DayAppointment& app)
{
    weekDay=app.weekDay;
    numOfAppointments=app.numOfAppointments;
    appointments = new appointment [numOfAppointments];
    for (int i=0; i< numOfAppointments; ++i)
    {
        appointments[i]=app.appointments[i];
    }

    return *this;
}

bool DayAppointment:: operator== (DayAppointment& app)
{
    if (numOfAppointments == app.numOfAppointments)
    {
        int q=0;
        for (int i=0; i<numOfAppointments; ++i)
        {
            if(appointments[i] != app.appointments[i])
            {
                q++;
            }
        }
        if (q > 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

bool DayAppointment:: operator!= (DayAppointment &app)
{
    if (numOfAppointments == app.numOfAppointments)
    {
        int q=0;
        for (int i=0; i<numOfAppointments; ++i)
        {
            if(appointments[i]!=app.appointments[i])
            {
                q++;
            }
        }
        if (q > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return true;
    }
}

appointment& DayAppointment:: operator [](int index)
{
    return appointments[index];
}

DayAppointment:: ~DayAppointment(){}

istream& operator>> (istream& in, DayAppointment &din)
{
    cout<<"\nEnter the day: ";
    in>>din.weekDay;
    cout<<"\nEnter the number of appointments: ";
    in>>din.numOfAppointments;
    cout<<"\nEnter the Appointments ...";
    cout<<endl;
    din.appointments=new appointment [din.numOfAppointments];
    for (int i=0; i<din.numOfAppointments; ++i)
    {
        in>>din.appointments[i];
    }
    cout<<endl;
    return in;
}

ostream& operator<< (ostream& out, DayAppointment &dout)
{
    out<<"In The "<<dout.weekDay<<" The appointments is \n\n";
    for(int i=0; i<dout.numOfAppointments; ++i)
    {
        out<<"  "<<i+1<<"  "<<dout.appointments[i]<<endl;

    }

    return out;
}

void DayAppointment::delete_appointment()
{
    delete appointments;
}

