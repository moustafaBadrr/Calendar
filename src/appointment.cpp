#include <iostream>
#include "appointment.h"

using namespace std;

appointment::appointment() {} // default constructor

appointment::appointment(time s,time e)   // parameter constructor take the start time and end time
{
    start_time=s;
    end_time=e;

}
bool appointment::operator <= (appointment tsmallerequal)
{
    if (start_time < tsmallerequal.end_time && end_time < tsmallerequal.end_time)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool appointment::operator >= (appointment tgreaterequal)
{
    if (start_time > tgreaterequal.start_time && end_time > tgreaterequal.end_time)
    {
       return true;
    }
    else
    {
        return false;
    }
}
bool appointment::operator <  (appointment tsmaller)
{
  if (end_time < tsmaller.start_time)
  {
      return true;
  }
  else
  {
      return false;
  }
}
bool appointment::operator >  (appointment tgreater)
{
    if (start_time > tgreater.end_time)
  {
      return true;
  }
  else
  {
      return false;
  }
}
bool appointment::operator == (appointment tequal)
{
    if (start_time == tequal.start_time && end_time == tequal.end_time)
  {
      return true;
  }
  else
  {
      return false;
  }
}
bool appointment::operator != (appointment tnotequal)
{
      if (start_time != tnotequal.start_time || end_time != tnotequal.end_time)
  {
      return true;
  }
  else
  {
      return false;
  }
}
istream& operator>>(istream &in, appointment & appin)
{
start:
    cout<<"\nEnter the Start time of Appointment: ";
    in>>appin.start_time;
    cout<<"\n\n Enter the End time of Appointment: ";
    in>>appin.end_time;
    cout<<endl;
    while(true)
    {
        if(appin.start_time > appin.end_time)
        {
            cout<<"Error the start time must be before the end ...."<<endl;
            cout<<"Enter the appointment correctly please...."<<endl;
            goto start;
        }
        else
            break;
    }

    return in;
}
ostream& operator<<(ostream& out, appointment &appout)
{
    out<<"The Appointment is from  "<<appout.start_time<<"  to  ";
    out<<appout.end_time<<endl;

    return out;
}
