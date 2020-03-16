#include "date.h"

using namespace std;

date::date(){}
date::date(string str)
{
    char * cstr = new char[str.length() + 1]; //auto 8a kanw tokenize
    strcpy (cstr, str.c_str()); //copy as string to str sto cstr
    char * pch;
    const char delim[2] = "-";
    pch = strtok(cstr, delim);
    short unsigned int counter = 0;
    char* parts[3];
    while (pch != NULL)
    {
        //printf ("%s ",pch);
        parts[counter] = pch;
        counter++;
        pch = strtok (NULL, delim);
    }

    if (atoi(parts[2])<0)
    {
        cout << "Before Christ.\n";
    }
    else
    {
        this->year = atoi(parts[2]);
        this->set=true;
    }

    if ((atoi(parts[1])<0) || (atoi(parts[1])>12))
    {
        cout << "Wrong month.\n";
        exit(-1);
    }
    else
    {
        this->month = atoi(parts[1]);
        this->set=true;
    }


    if ((atoi(parts[0])<0) || (atoi(parts[0])>31))
    {
        cout << "Wrong day.\n";
        exit(-1);
    }
    else
    {
        this->day = atoi(parts[0]);
        this->set=true;
    }
}
date::date(date &d) { //copy constructor, kaleitai ws: date d1 = d2;
    if ((d.get_month()<0)||(d.get_month()>12)) {
        fprintf(stderr, "Invalid month\n");
        exit(1);
    }
    if ((d.get_day()<0)||(d.get_day()>31)) {
        fprintf(stderr, "Invalid day\n");
        exit(1);
    }
    if ((d.get_month()==2)&&(d.get_year()%4==0)&&(d.get_day()>29)) { //leap yeared feb
        fprintf(stderr, "Invalid date format\n");
        exit(1);
    }
    if (((d.get_month()==4)||(d.get_month()==6)||(d.get_month()==9)||(d.get_month()==11))&&(d.get_day()>30)) { //30 day-d months
        fprintf(stderr, "Invalid date format\n");
        exit(1);
    }
    this->day = d.get_day();
    this->month = d.get_month();
    this->year = d.get_year();
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
void date::make_set()
{
    if (this->is_set()==false) this->set==true;
    else {cout << "Error in make_set"; exit(-1);} //it's already set
}
void date::unset()
{
    if (this->is_set()==true) this->set==false;
    else {cout << "Error in unset"; exit(-1);}
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
bool isLater(date d1, date d2) //is d1 later than d2?
{
    if ((d1.is_set()==false)||d2.is_set()==false)
    {
        fprintf(stderr, "No dates set to compare!\n");
        exit(-1);
    }
    if (d1.get_year()>d2.get_year())
    {
        return true;
    }
    else if (d1.get_year()==d2.get_year())
    {
        if (d1.get_month()>d2.get_month())
        {
            return true;
        }
        else if (d1.get_month()==d2.get_month())
        {
            if (d1.get_day()>d2.get_day())
            {
                return true;
            }
        }
    }
    //else d2 >= d1
    return false;
}
bool isBetween(date d, date d1, date d2) //is d between d1 kai d2
{
    if ((d.is_set()==false)||(d1.is_set()==false)||(d2.is_set()==false))
    {
        fprintf(stderr, "No dates set to compare!\n");
        //epektasi: mono to ena na einai "-" => it's max date => act accordingly
        exit(-1);
    }
    //else
    /*if ((d.get_year()>=d1.get_year())&&(d.get_year()<d2.get_year())||((d.get_year()>d1.get_year())&&(d.get_year()<=d2.get_year())))
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
    return false; //else*/
    if ((isLater(d,d1)==true)&&(isLater(d2,d)==true))
    {
        return true; //pane d1 < d < d2
    }
    else
    {
        return false; //estw kai 1 na pige lathos
    }
    
}
