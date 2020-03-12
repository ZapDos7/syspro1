#include "date.h"

date::date(int d, int m, int y) {
    if ((m<0)||(m>12)) {
        fprintf(stderr, "Invalid month\n");
        exit(1);
    }
    if ((d<0)||(d>31)) {
        fprintf(stderr, "Invalid day\n");
        exit(1);
    }
    if ((m==2)&&(y%4==0)&&(d>29)) { //leap yeared feb
        fprintf(stderr, "Invalid date format\n");
        exit(1);
    }
    if (((m==4)||(m==6)||(m==9)||(m==11))&&(d>30)) { //30 day-d months
        fprintf(stderr, "Invalid date format\n");
        exit(1);
    }
    this->day = d;
    this->month = m;
    this->year = y;
    this->set = true;
}
date::~date() {}
int date::get_day() {
    return this->day;
}
int date::get_month() {
    return this->month;
}
int date::get_year() {
    return this->year;
}
std::string date::get_date_as_string()
{
    std::string day = std::to_string(this->get_day());
    std::string month = std::to_string(this->get_month());
    std::string year = std::to_string(this->get_year());
    std::string date = day+"-"+month+"-"+year;
    return date;
}
bool date::is_set() {
    return this->set;
}
void date::set_day(int d) {
    if ((d<0)||(d>31)) {
        fprintf(stderr, "Invalid day\n");
        exit(1);
    }
    else {
        this->day = d;
    }    
    return;
}
void date::set_month(int m) {
    if ((m<0)||(m>12)) {
        fprintf(stderr, "Invalid month\n");
        exit(1);
    }
    else {
        this->month = m;
    } 
    return;
}
void date::set_year(int y) {
    this->year = y;
    return;
}
void date::print_date() {
    fprintf(stdout, "Date is: %d-%d-%d\n",this->get_day(), this->get_month(), this->get_year());
    return;
}

//check if d1 is between d2 & d3 => d2...d1...d3
bool isBetween(date d, date d1, date d2)
{
    //is 10-11-2004 between 9-1-2003 and 4-6-2008?
    if ((d.get_year()>=d1.get_year())&&(d.get_year()<d2.get_year())||((d.get_year()>d1.get_year())&&(d.get_year()<=d2.get_year())))
    {
        return true;
    }
    else if ( (d.get_year()==d1.get_year()) && (d.get_year()==d2.get_year()) ) //idia xronia
    {
        if ((d.get_month()>=d1.get_month())&&(d.get_month()<d2.get_month())||((d.get_month()>d1.get_month())&&(d.get_month()<=d2.get_month())))
        {
            return true;
        }
        else if ((d.get_month()==d1.get_month()) && (d.get_month()==d2.get_month())) //idios mhnas
        {
            if ((d.get_day()>=d1.get_day())&&(d.get_day()<d2.get_day())||((d.get_day()>d1.get_day())&&(d.get_day()<=d2.get_day())))
            {
                return true;
            }            
        }
    }
    return false; //else
}
