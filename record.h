#ifndef _RECORD_H_
#define _RECORD_H_

#include <string>
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
    record(/* args */);
    ~record();
    date get_exitD();
    bool hasLeft();
};

#endif