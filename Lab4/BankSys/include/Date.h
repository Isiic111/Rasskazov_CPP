#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <ctime>

class Date {
private:
    int day;
    int month;
    int year;
    
    bool isValidDate(int d, int m, int y) const;
    
public:
    Date();
    Date(int d, int m, int y);
    
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    
    void setDate(int d, int m, int y);
    std::string toString() const;
    
    static Date getCurrentDate();
    
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
};

#endif