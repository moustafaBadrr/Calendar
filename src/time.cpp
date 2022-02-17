#include <iostream>
#include "time.h"
#include <cstdlib>
using namespace std;


time::time(){} /// default constructor

time ::time(int h, int m,string ap){  /// parameterize constructor to setter the inputs
    hours=h;
    minutes=m;
    NightOrDay=ap;
}

                         /// comparing overloaded Functions
bool time::operator <  (time tsmaller){
    if ((NightOrDay=="AM" && tsmaller.NightOrDay=="AM") || (NightOrDay=="PM" && tsmaller.NightOrDay=="PM"))
    {
            if(hours < tsmaller.hours){
                return true;
            }
            else if (hours == tsmaller.hours && minutes < tsmaller.minutes){
                return true;
            }
            else {
                return false;
            }
    }
    else if (NightOrDay=="AM" && tsmaller.NightOrDay=="PM"){
            return true;
    }
    else if (NightOrDay=="PM" && tsmaller.NightOrDay=="AM"){
            return false;
    }
}
bool time::operator >  (time tgreater){
    if ((NightOrDay=="AM" && tgreater.NightOrDay=="AM") || (NightOrDay=="PM" && tgreater.NightOrDay=="PM"))
    {
            if(hours > tgreater.hours){
                return true;
            }
            else if (hours == tgreater.hours && minutes > tgreater.minutes){
                return true;
            }
            else {
                return false;
            }
    }
    else if (NightOrDay=="AM" && tgreater.NightOrDay=="PM"){
            return false;
    }
    else if (NightOrDay=="PM" && tgreater.NightOrDay=="AM"){
            return true;
    }
}
bool time::operator == (time tequal){

    if ((NightOrDay=="AM"&& tequal.NightOrDay=="AM") || (NightOrDay=="PM"&& tequal.NightOrDay=="PM"))
    {
        if ((hours == tequal.hours) && (minutes ==tequal.minutes))
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
            return false;
    }
}
bool time::operator != (time tnotequal){

    if ((NightOrDay=="AM"&& tnotequal.NightOrDay=="AM") || (NightOrDay=="PM"&& tnotequal.NightOrDay=="PM"))
    {
        if ((hours != tnotequal.hours) || (minutes !=tnotequal.minutes))
        {
                return true;
        }
        else
        {
                return false;
        }
    }
    if ((NightOrDay=="AM" && tnotequal.NightOrDay=="PM") || (NightOrDay=="PM" && tnotequal.NightOrDay=="AM"))
    {
        return true;
    }
    else
    {
        return false;
    }
}



istream& operator>>(istream &in, time & timein)
{
start:
    cout<<endl;
    cout<<"\nEnter the hours: ";
    in>>timein.hours;
    if (!(timein.hours < 13 && timein.hours > 0 ))
    {
        cout<<endl<<"Valid... Hours is from 1:12 "<<endl;
        cout<< "Please insert Correctly..."<<endl;
        goto start;

    }
    cout<<endl;
    cout<<"\nEnter the minutes: ";
    in>>timein.minutes;
    if (!(timein.hours < 61 && timein.hours > 0 ))
    {
        cout<<endl<<"Valid... Minutes is from 1:60  "<<endl;
        cout<< "Please insert Correctly..."<<endl;
        goto start;

    }
    cout<<endl;
    cout<<"\nEnter AM or PM: ";
    in>>timein.NightOrDay;
    if ((timein.NightOrDay!="AM") && (timein.NightOrDay!="PM"))
    {
        cout<<endl<<"Valid... You Should put AM for day Or PM for night...."<<endl;
        cout<< "Please insert Correctly..."<<endl;
        goto start;

    }
    cout<<endl;

    return in;
}
ostream& operator<<(ostream& out, time &timeout)
{
    out<<" "<<timeout.hours<<" : ";
    out<<timeout.minutes<<" ";
    out<<timeout.NightOrDay;
    return out;
}
