#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Date {
public:


  // TODO: Define one argument constructor here
  Date(int year){
    this->year = year;
    month = 1;
    day = 1;
  }

  // TODO: Define two argument constructor here
    Date(int year, int month){
    this->year = year;
    this->month = month;
    day = 1;
  }

  Date(int y, int m, int d): year(y), month(m), day(d){}

  Date& addMonths(int n){
    year  += (month + n) / 12;
    month = (month + n) % 12;
    return *this;
  }

  Date& addDays(int n) {
    int d = daysToDate() + n;
    int y = year, m = 1;
    while(d > daysInMonth(y, m)){
      d -= daysInMonth(y, m);
      m++;
      if(m > 12){
        m = 1;
        y++;
      }
    }
    day = d;
    month = m;
    year = y;

    return *this;
  }

  static bool isLeapYear(int y) {
    return (y % 4 || (y % 100 == 0 && y % 400)) ? false : true;
  }

  string toString()const {
    // TODO: complete this function implementation here.
  string monthNames[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                      "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

    return monthNames[month-1] + " " +to_string(day) + ", "+ to_string(year);
 

    }

  int daysToDate(){
    int days_in_month[]{31, isLeapYear(year) ? 29 : 28, 31,
                        30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = 0;
    for(int m = 0; m < month - 1; m++){
      days += days_in_month[m];
    }
    days += day;
    return days;
  }

  // TODO: Overload operator+ here
    Date operator+(int n){
    // Date nDate(year + y.year, month + d.month, day + d.day);
        return addDays(n);
    }
  // TODO: overload operator<< here
    friend ostream &operator<<(ostream &output, const Date &d ){
      output << d.toString();
      return output;
      }


private:
  int year, month, day;

  static int daysInMonth(int y, int m){
    int days_in_month[]{31, isLeapYear(y) ? 29 : 28, 31,
                        30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days_in_month[m - 1];
  }
};




