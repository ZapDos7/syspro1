#include "aht.h"


aht::aht()
{
    this->table = NULL;
}
aht::aht(int hsize, int bsize)
{
    this->table = new bucket(bsize);
    this->size = hsize;
}
aht::~aht()
{
    this->table = NULL;
    delete(this->table);
}
unsigned int aht::get_size()
{
    return this->size;
}
bucket* aht::get_table()
{
    return this->table;
}
unsigned int aht::ahash(std::string tbhashed)//generic hashing function
{
    const int a = 830; //random
    long hash = 0;
    for (unsigned int i = 0; i < tbhashed.length(); i++)
    {
        hash += (long)pow(a, tbhashed.length() - (i+1)) * tbhashed[i];
        hash = hash % this->size;
    }
    hash = hash % this->size;
    return (unsigned int)hash;
}
void aht::ainsert(record *r, bool isCountry)
{
    if (isCountry==true)//hash to country tou record, balto sto katallilo block tou bucket tou country hash table, update tree, update ht
    {
        unsigned int where = this->ahash(r->get_country());
        this->table[where].insert(r, isCountry);
    }
    else //disease
    {
        unsigned int where = this->ahash(r->get_disease());
        this->table[where].insert(r, isCountry);
    }
    return;
}