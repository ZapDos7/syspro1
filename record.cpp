#include "record.h"

using namespace std;

record::record() {}
record::record(string line)
{
    char * cstr = new char[line.length() + 1]; //auto 8a kanw tokenize
    strcpy (cstr, line.c_str()); //copy as string to line sto cstr
    char * pch;
    const char delim[2] = " ";
    pch = strtok(cstr, delim);
    short unsigned int counter = 0;
    char* parts[7];
    //string partsStr[7];
    while (pch != NULL)
    {
        //printf ("%s ",pch);
        parts[counter] = pch;
        counter++;
        pch = strtok (NULL, delim);
    }
    for (unsigned int i = 0; i < 7; i++)
    {
        string tmp(parts[i]);
        if (i==0) id=tmp;
        else if (i==1) fname=tmp;
        else if (i==2) lname=tmp;
        else if (i==3) disease=tmp;
        else if (i==4) country=tmp;
        else if (i==5)
        {
            date tmpD(tmp);
            entryD.set_day(tmpD.get_day());
            entryD.set_month(tmpD.get_month());
            entryD.set_year(tmpD.get_year());
        }
        else if (i==6)
        {
            //std::cerr << tmp << "\n";
            if (tmp=="-")
            {
                date tmpD(tmp);
                exitD.set = false; //date's set == false so it's just a dash!
                //std::cerr << "I'm a dash!: " << exitD.get_date_as_string() << "\n";
            }
            else
            {
                date tmpD(tmp);
                exitD.set_day(tmpD.get_day());
                exitD.set_month(tmpD.get_month());
                exitD.set_year(tmpD.get_year());
                /*if (isLater(entryD,exitD)==true) //mpike meta poy bgike
                {
                    std::cerr << "Error in record dates.\n";
                    exit(-1);
                }*/
            }
        }
    }
    delete[] cstr;
}
record::record(record &r) //copy constructor //kaleitai ws record r1 = r2;
{
    this->id = r.get_id();
    this->fname = r.get_fname();
    this->lname = r.get_lname();
    this->disease = r.get_disease();
    this->country = r.get_country();
    this->entryD = r.get_entryDate();
    this->exitD = r.get_exitDate();
}

record::~record()
{
}

std::string record::get_id()
{
    return this->id;
}

std::string record::get_fname()
{
    return this->fname;
}

std::string record::get_lname()
{
    return this->lname;
}

std::string record::get_disease()
{
    return this->disease;
}
std::string * record::get_diseasePtr()
{
    return &disease;
}
std::string record::get_country()
{
    return this->country;
}
std::string * record::get_countryPtr()
{
    return &country;
}
date record::get_entryDate()
{
    return this->entryD;
}

date record::get_exitDate()
{
    return this->exitD;
}

bool record::hasLeft()
{
    return this->exitD.set; //if exit date is set (true) aka it exists and isn't "-", then he has left (true)
}
date * record::get_entryDatePtr()
{
    return &entryD;
}
void record::set_id(std::string id_to_be)
{
    this->id = id_to_be;
    return;
}

void record::set_fname(std::string fn)
{
    this->fname = fn;
    return;
}
void record::set_lname(std::string ln)
{
    this->lname = ln;
    return;
}
void record::set_disease(std::string dis)
{
    this->disease = dis;
    return;
}
void record::set_country(std::string cntr)
{
    this->country = cntr;
    return;
}
void record::set_entryD(std::string enD)
{
    this->entryD = enD; //this wont work
    return;
}
void record::set_exitD(std::string exD)
{
    this->exitD = exD;
    return;
}