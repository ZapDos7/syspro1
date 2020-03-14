#ifndef _RECORD_H_
#define _RECORD_H_

#include <string>
#include <cstring>
#include <iostream>
#include "date.h"

class record
{
private:
    std::string id; //unique
    std::string fname; //oxi kena, mono grammata
    std::string lname; //oxi kena, mono grammata
    std::string disease; //string w/ letters, numbers kai "-"
    std::string country; //oxi kena, mono grammata
    date entryD; /*entryDate:  DD-MM-YYYY */
    date exitD; /*exitDate:   DD-MM-YYYY or "-" (den exei eksitirio akoma o asthenis)*/

public:
    record();
    record(std::string line);
    record(std::string id0, std::string fn, std::string ln, std::string dis, std::string countr, date enD, date exD);
    ~record();
    std::string get_id();
    std::string get_fname();
    std::string get_lname();
    std::string get_disease();
    std::string get_country();
    date get_entryDate();
    date get_exitDate();
    bool hasLeft();
};

#endif