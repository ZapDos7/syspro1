#include "ht.h"

ht_node::ht_node(record * record)
{
    this->rec.set_id(record->get_id());
    this->rec.set_fname(record->get_fname());
    this->rec.set_lname(record->get_lname());
    this->rec.set_disease(record->get_disease());
    this->rec.set_country(record->get_country());
    //this->rec.set_entryD(record->get_entryDate());
    //this->rec.set_exitD(record->get_exitDate());
}
ht_node::~ht_node()
{

}

ht::ht(unsigned int sz)
{
}

ht::~ht()
{
}
