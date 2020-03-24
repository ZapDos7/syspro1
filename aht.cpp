#include "aht.h"

aht::aht()
{
    this->table = NULL;
}

aht::aht(int hsize, int bsize)
{
    this->table = new bucket[hsize];
    unsigned int posa = 0;
    bsize -= sizeof (bucket*); //prepei na afairesw kai sizeof(bucket*) = next
    bsize -= sizeof (unsigned int); //afairw to megethos tou bucksize
    posa = floor(bsize / sizeof (block)); //posa block nodes xwrane se ena block?
    for (int i = 0; i < hsize; i++)
    {
        table[i].next = NULL;
        table[i].num_of_blocks = posa;
        table[i].blocks = new block[posa]; //pinakas apo blocks, energopoieitai o constructor tou block
    }
    this->size = hsize;
}

aht::~aht()
{
    delete[] table;
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
        hash += (long) pow(a, tbhashed.length() - (i + 1)) * tbhashed[i];
        hash = hash % this->size;
    }
    hash = hash % this->size;
    return (unsigned int) hash;
}

void aht::ainsert(record *r, bool isCountry)
{
    if (isCountry == true)//hash to country tou record, balto sto katallilo block tou bucket tou country hash table, update tree, update ht
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

void aht::print_aht(bool isCountry)
{
    for (unsigned int i = 0; i < size; i++)
    {
        table[i].print_bkt(isCountry);
    }
}

block * aht::search(std::string s)
{
    unsigned int where = this->ahash(s);
    return table[where].search(s); //to zoumi einai stin search tou bucket
}