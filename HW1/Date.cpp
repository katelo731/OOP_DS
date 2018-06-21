#include <iostream>
#include "Date.h"

// Driver Program to check your implementation
int main()
{
	cout << endl;
	
    Date date1(8, 5, 2018);
    cout << "========================Date1========================" << endl;
    cout << "the day of week : " << date1.dayOfWeek() << endl;
    cout << "number of days in the current month : " << date1.numberOfDays() << endl;
    cout << "calender : ";
	date1.printMonthCalendar();
	cout << "=====================================================" << endl;
    
    cout << endl;
    
    Date date2 = date1.DateAfter(30);
    cout << "========================Date2========================" << endl;
    cout << "the day of week : " << date2.dayOfWeek() << endl;
    cout << "number of days in the current month : " << date2.numberOfDays() << endl;
    cout << "calender : ";
	date2.printMonthCalendar();
	cout << "=====================================================" << endl;
    
    cout << endl;
    
    Date date3 = date1.DateBefore(65);

	cout << "========================Date3========================" << endl;
    cout << "the day of week : " << date3.dayOfWeek() << endl;
    cout << "number of days in the current month : " << date3.numberOfDays() << endl;
    cout << "calender : ";
	date3.printMonthCalendar();
	cout << "=====================================================" << endl;
    
    cout << endl;
    return 0;
}
