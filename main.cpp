#include <iostream>
#include <cstdlib>
#include "time.h"
#include "appointment.h"
#include "DayAppointment.h"
#include "calendar.h"

using namespace std;

int main()
{
    time time1,time2;
    appointment app1,app2;
    DayAppointment day1,day2;
    calendar cal1,cal2;
    bool status = true;
    while(status == true)
    {
        int choice;
        cout<<"\n";
        cout<<" 1- Insert an appointment for a specific day \n 2- Display an appointments for a day";
        cout<<"\n 3- Delete an appointment\n 4- The appointments of a day equal to another day";
        cout<<"\n 5- Enter the days we need to number 6 ";
        cout<<"\n 6- Check if two days have equal appointments\n 7- If you want to close the program\n\n";
        cout<<" Your Choice: ";
        cin>>choice;
        int NumberOfDays,day;
        if(choice == 1)
        {
            int index;
            cout<<"Enter the number of day: ";
            cin>>index;
            cout<<endl;
            cin>>day1;
            cal1.add_appointment_a_specific_day(day1,index);
        }
        else if(choice == 2)
        {
            cout<<"Enter the number of day: ";
            int index;
            cin>>index;
            cout<<cal1[index];
        }
        else if(choice == 3)
        {
            int day_index;
            cout<<"Enter the number of day : ";
            cin>>day_index;
            cal1.delete_day(day_index);
        }
        else if(choice == 4)
        {
            cout<<"Enter the two days :"<<endl;
            int index_day1,index_day2;
            cin>>index_day1>>index_day2;
            cal1.equal_two_days(index_day1,index_day2);
        }
        else if(choice == 5)
        {
            cin>>cal1>>cal2;
        }
        else if(choice == 6)
        {
            int day1_index,day2_index;
            cout<<"Enter the two days :"<<endl;
            cin>>day1_index>>day2_index;
            if(cal1[day1_index] == cal1[day2_index])
                cout<<"True..\nthe two days have the same appointments " <<endl;
            else
                cout<<"False..\nthe two days haven't the same appointments"<<endl;
        }
        else if (choice == 7)
        {
            status = false;
            exit(1);
        }
        else
        {
            cout<<"\nValid.....Enter your choice again.....\n\n";
            continue;
        }
    }
    return 0;
}
