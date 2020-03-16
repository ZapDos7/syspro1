#include "ht.h"

ht_item::ht_item(){}
ht_item::ht_item(record* r, int k)
{
    this->rec->set_id(r->get_id());
    this->rec->set_fname(r->get_fname());
    this->rec->set_lname(r->get_lname());
    this->rec->set_disease(r->get_disease());
    this->rec->set_country(r->get_country());
    this->rec->set_entryD(r->get_entryDate().get_date_as_string());
    this->rec->set_exitD(r->get_exitDate().get_date_as_string());
    this->key = k;
    this->next = NULL;
}
ht_item::~ht_item(){}
void ht_item::print_ht_item()
{
    /*std::cerr << this->(&rec).get_id() << " " 
    << this->rec.get_fname() << " " 
    << this->rec.get_lname() << " " 
    << this->rec.get_disease() << " " 
    << this->rec.get_country() << " " 
    << this->rec.get_entryDate().get_date_as_string() << " " 
    << this->rec.get_exitDate().get_date_as_string() << std::endl;*/
}







/*Bucket* ht::initBucket(size_t bktsz)
{
    unsigned int numOfRecs = this->bucketSize / sizeof(record); //se auto to hash table bazw olokliro to record
}*/

ht::ht(unsigned int sz)
{
    this->size = sz;
    for (unsigned int i = 0; i < sz; i++)
    {
        this->table[i] = NULL;
    }
    
}

ht::~ht()
{
    //free(this->table);
}

/*
void ht::insert(Bucket* bucket, record* item)
{
    unsigned int numOfRecs = this->bucketSize / sizeof(record); //se auto to hash table bazw olokliro to record
    //unsigned int counter = (unsigned int)bucket[numOfRecs - 2];
}*/

unsigned int ht::get_size()
{
    return this->size;
}
/*
unsigned int ht::hash(std::string recordId, int maxVal)
{
    unsigned int hash_value = 0;
    for(unsigned int i = 0; i < recordId.length(); i++)
    {
        hash_value += recordId[i];
    }
    return hash_value % maxVal;
}

//search //epistrefei to se poio index uparxei to record, else error msg
    
//delete //delete from hash table

*/