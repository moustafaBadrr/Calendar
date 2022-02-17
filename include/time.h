#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;

class time
{
    // data member for time class to make the form of time which is ==>> hours:minutes:NightOrDay
private:
    int hours, minutes;
    string NightOrDay;
public:
    time();  // default constructor
    time(int h,int m,string ap);    //parameterized constructor take the data member
    bool operator<(time tsmaller);  // overloaded operator compare between two time which of them is smaller
    bool operator>(time tgreater);  // overloaded operator compare between two time which of them is greater
    bool operator==(time tequal);   // overloaded operator compare between two time if are equal
    bool operator!=(time tnotequal);// overloaded operator compare between two time if are not equal
    friend istream& operator>>(istream &in, time & timein); // overloaded istream to take the data member from user
    friend ostream& operator<<(ostream& out, time &timeout);// overloaded ostream to display the data member to user
};

#endif
