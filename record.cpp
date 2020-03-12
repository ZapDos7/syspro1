#include "record.h"

using namespace std;

record::record() {}
record::record(string line)
{
    //tokenize line by tab delims and fix the rest!
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

}

std::string record::get_fname()
{

}

std::string record::get_lname()
{

}

std::string record::get_disease()
{

}

std::string record::get_country()
{

}

date record::get_entryDate()
{

}

date record::get_exitDate()
{

}

bool record::hasLeft()
{

}