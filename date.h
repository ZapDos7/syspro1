#ifndef _DATE_H_
#define _DATE_H_

#include <string>
#include <cstring>
#include <iostream>
#include <stdlib.h>
//DD-MM-YYYY

class date
{
private:
    short unsigned int day;
    short unsigned int month;
    short unsigned int year;
    bool set; //if true, date exists, if not, no matter the int fields, this is a "-" date aka doesn't exist.
    
public:
    date();
    date(std::string str);
    date(int d, int m, int y);
    ~date();
    int get_day();
    int get_month();
    int get_year();
    std::string get_date_as_string();
    bool is_set();
    void make_set();
    void unset();
    void set_day(int d);
    void set_month(int m);
    void set_year(int y);
    void print_date();
};
bool isBetween(date d, date d1, date d2);
#endif