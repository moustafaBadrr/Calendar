#include "calendar.h"
#include <cstdlib>

calendar::calendar()
{
    numOfDays =7;
}

calendar::calendar(DayAppointment d[], int n)
{
    numOfDays=n;
    days=new DayAppointment[numOfDays];
    for (int i=0; i<numOfDays; ++i)
    {
        days[i]=d[i];
    }
}
calendar::calendar(calendar &cal1)
{
    numOfDays=cal1.numOfDays;
    days=new DayAppointment[cal1.numOfDays];
    for (int i=0; i<cal1.numOfDays; ++i)
    {
        days[i]=cal1.days[i];
    }
}
calendar calendar:: operator=(calendar cal1)
{
    numOfDays=cal1.numOfDays;
    days=new DayAppointment[cal1.numOfDays];
    for (int i=0; i<cal1.numOfDays; ++i)
    {
        days[i]=cal1.days[i];
    }

    return *this;
}
DayAppointment& calendar:: operator [](int index)
{
    return days[index];
}
istream& operator>> (istream& in, calendar &cal)
{
    cout<<"\nEnter the number of days: ";
    in>>cal.numOfDays;
    cout<<endl;
    cal.days=new DayAppointment[cal.numOfDays];
    for (int i=0; i<cal.numOfDays; ++i)
    {
        in>>cal.days[i];
    }
    cout<<endl;

    return in;
}
ostream& operator<<(ostream& out, calendar &cal)
{
    for (int i=0; i<cal.numOfDays; ++i)
    {
        out<<cal.days[i];
    }
    cout<<endl;

    return out;
}
void calendar::equal_two_days(int day1_index,int day2_index)
{
        days[day1_index]=days[day2_index];
}
void calendar::delete_day(int day_number)
{
    days[day_number].delete_appointment();
}
void calendar :: add_appointment_a_specific_day(DayAppointment& app,int index)
{
    days=new DayAppointment[numOfDays];
    days[index]=app;
}
