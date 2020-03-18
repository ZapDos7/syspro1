#include "diseaseht.h"


diseaseht::diseaseht()
{
    this->table = NULL;
}
diseaseht::diseaseht(unsigned int sz)
{
    this->table = NULL;
    this->size = sz;
}
diseaseht::~diseaseht()
{
    this->table = NULL;
    delete(this->table);
}
unsigned int diseaseht::get_size()
{
    return this->size;
}
bucket* diseaseht::get_table()
{
    return this->table;
}