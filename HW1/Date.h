#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class Date
{
  public:
    Date(int day, int month, int year);
    ~Date();

    /*Get function for accessing private member*/
    int getDay();
    int getMonth();
    int getYear();

    /*Set function for updating private member*/
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    /*A Function that returns the date after a given date
        For e.g-
        
        today is 8/3/2018 (Day/Month/Year)
        DateAfter(3) should return a date of 11/3/2018 */
    Date DateAfter(int days);

    /*A Function that returns the date after a given date
        For e.g-
        
        today is 8/3/2018 (Day/Month/Year)
        DateBefore(3) should return a date of 5/3/2018 */
    Date DateBefore(int days);

    /*A Function that returns the day of a date
        For e.g-
        
        if the date is 8/3/2018, then the day() function
        should return "Thursday"
    */
    string dayOfWeek();

    /* A Function to return the number of days in
        Current Month.
        
        Month Number     Name        Number of Days
        0                January     31
        1                February    28 (non-leap) / 29 (leap)
        2                March       31
        3                April       30
        4                May         31
        5                June        30
        6                July        31
        7                August      31
        8                September   30
        9                October     31
        10               November    30
        11               December    31*/
    int numberOfDays();

    /* Function to print a calendar of the current month.
    Just like what you see on a calendar. An example is like
   --------------March--------------
   Sun  Mon  Tue  Wed  Thu  Fri  Sat
                        1    2    3
    4    5    6    7    8    9   10
   11   12   13   14   15   16   17
   18   19   20   21   22   23   24
   25   26   27   28   29   30   31
    
   */
    void printMonthCalendar();
    int weekofthefirstday();
    static const char* const mon[13];
    int mond[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    
  private:
    /*Current Date*/
    int day;
    int month;
    int year;
    bool leap;
	int week;
};

Date::Date(int day,int month,int year)
{
	leap=false;
	setYear(year);
	setMonth(month);
	setDay(day);
	week=0;
 } 
 
Date::~Date()
{	
}

const char* const Date::mon[13]={"error","January","February","March","April","May",
								"June","July","August","September","October","November","December"};
					
int Date::getDay()
{
	return day;
}

int Date::getMonth()
{
	return month;
}

int Date::getYear()
{
	return year;
}

void Date::setDay(int d)
{
	if(month==2 && leap)
		day=(d>=1 && d<=29)? d:1;
	else
		day=(d>=1 && d<=mond[month])? d:1;
}

void Date::setMonth(int m)
{
	month=(m>=1 && m<=12)? m:1;
}

void Date::setYear(int y)
{
	year=(y>0)? y:2018;
	leap=(year%400==0 || (year&4==0 && year%100!=0))? true:false;
}

int Date::numberOfDays()
{
	static const int dayspermonth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	
	if(month==2 && (year%400==0 || (year%4==0 && year%100!=0)))
		return dayspermonth[month]+1;
	else
		return dayspermonth[month];
}

Date Date::DateAfter(int days)
{
	int y=year;
	int m=month;
	int d=day;
	int daysofthemonth=numberOfDays();
	
	d+=days;
	while(d>daysofthemonth)
	{
		days=d-daysofthemonth-1;
		d=1;
		if(m+1>12)
		{
			y++;
			m=1;	
		}	
		else
			m++;
			
		daysofthemonth=mond[m];
		d+=days;
	}
	return Date(d,m,y);
}

Date Date::DateBefore(int days)
{
	int y=year;
	int m=month;
	int d=day;
	int daysofthemonth=numberOfDays();
	
	d-=days;
	while(d<=0)
	{
		days=abs(d);
		
		if(m<=1)
		{
			y--;
			m=12;
		}
		else
			m--;
		
		d=mond[m];
		d-=days;
	}
	return Date(d,m,y);
}

string Date::dayOfWeek()
{
	int y=0,t=0,m=0,d=0;
	
	if(month==1 || month==2)
	{
		t=(year-1)/100;
		y=(year-1)%100;
		m=month+12;
		d=day;
	}
	else
	{
		t=year/100;
		y=year%100;
		m=month;
		d=day;
	}
	
	week=y+y/4+t/4-t*2+26*(m+1)/10+d-1;
	week= (week>=0)? week%7:week%7+7;
	
	switch(week)
	{
		case 0:
			return "Sunday";
		case 1:
			return "Monday";
		case 2:
			return "Tuesday";
		case 3:
			return "Wednesday";
		case 4:
			return "Thursday";
		case 5:
			return "Friday";
		case 6:
			return "Saturday";
	}
}

int Date::weekofthefirstday()
{
	int y=0,t=0,m=0,d=1;
	
	if(month==1 || month==2)
	{
		t=(year-1)/100;
		y=(year-1)%100;
		m=month+12;
	}
	else
	{
		t=year/100;
		y=year%100;
		m=month;
	}

	week=y+y/4+t/4-t*2+26*(m+1)/10+d-1;
	week= (week>=0)? week%7:week%7+7;
	
	switch(week)
	{
		case 0:
			return 0;
		case 1:
			return 1;
		case 2:
			return 2;
		case 3:
			return 3;
		case 4:
			return 4;
		case 5:
			return 5;
		case 6:
			return 6;
	}
}

void Date::printMonthCalendar()
{    
	cout << endl << "--------------" << mon[month] << "--------------" << endl
		 << "Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;
	
	int first=weekofthefirstday();
	const int daysofthemonth=numberOfDays();
	
	for(int i=0;i<first;i++)
	{
		cout << "     ";
	}
	
	for(int i=1;i<=daysofthemonth;i++)
	{
		cout << setw(2) << i << "   ";
		if((first+i)%7==0) cout << endl;
	}
	cout << endl;
}
