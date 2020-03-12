#include "date.h"

using namespace std;

date::date(){}
date::date(string str)
{
    //c_str()
    
    //tokenize string --> AA-BB-CCCC
}
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
    if (this->is_set()==true)
        return this->day;
    else
        return -1;    
}
int date::get_month() {
    if (this->is_set()==true)
        return this->month;
    else
        return -1;    
}
int date::get_year() {
    if (this->is_set()==true)
        return this->year;
    else
        return -1;    
}
std::string date::get_date_as_string()
{
    if (this->is_set()==true)
    {
        std::string day = std::to_string(this->get_day());
        std::string month = std::to_string(this->get_month());
        std::string year = std::to_string(this->get_year());
        std::string date = day+"-"+month+"-"+year;
        return date;
    }
    else
        return "-1";    
    
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
        this->set = true;
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
        this->set = true;
    } 
    return;
}
void date::set_year(int y) {
    this->year = y;
    this->set = true;
    return;
}
void date::print_date() {
    if (this->is_set()==true)
    {
        fprintf(stdout, " %d-%d-%d ",this->get_day(), this->get_month(), this->get_year());
    }
    else
    {
        fprintf(stdout," - ");
    }
    
    return;
}

//check if d1 is between d2 & d3 => d2...d1...d3
bool isBetween(date d, date d1, date d2)
{
    if ((d.is_set()==false)||(d1.is_set()==false)||(d2.is_set()==false))
    {
        fprintf(stderr, "No dates set to compare!\n");
        exit(-1);
    }
    //else
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
