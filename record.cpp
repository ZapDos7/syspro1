#include "record.h"

using namespace std;

record::record() {}
record::record(string line)
{
    //tokenize line by tab delims and fix the rest!
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
        //partsStr[i] = tmp;
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
        else /*i==6*/
        {
            if (tmp!="-") //it's an actual date!
            {
                date tmpD(tmp);
                exitD.set_day(tmpD.get_day());
                exitD.set_month(tmpD.get_month());
                exitD.set_year(tmpD.get_year());
            }
            else //not set date
            {
                exitD.unset(); //date's set == false so it's just a dash!
            }          
        }
    }
    
}
record::record(std::string id0, std::string fn, std::string ln, std::string dis, std::string countr, date enD, date exD)
{
    this->id = id0;
    this->fname = fn;
    this->lname = ln;
    this->disease = dis;
    this->country = countr;
    //this->entryD
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

std::string record::get_country()
{
    return this->country;
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
    return this->exitD.is_set(); //if exit date is set (true) aka it exists and isn't "-", then he has left (true)
}