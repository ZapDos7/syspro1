#include "ht.h"

ht_item::ht_item()
{
    this->next = NULL;
    this->rec = NULL;
}
ht_item::ht_item(record* r)
{
    this->rec->set_id(r->get_id());
    this->rec->set_fname(r->get_fname());
    this->rec->set_lname(r->get_lname());
    this->rec->set_disease(r->get_disease());
    this->rec->set_country(r->get_country());
    this->rec->set_entryD(r->get_entryDate().get_date_as_string());
    this->rec->set_exitD(r->get_exitDate().get_date_as_string());
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


//
ht::ht(unsigned int sz)
{
    this->size = sz;
    this->table = new ht_item[size]; //size antikeimena ht_item poy den exoun tpt mesa tous basei tou empty consturctor tou ht_item dld ta pedia tous einai null automata
}
ht::~ht()
{
    this->table = NULL;
    delete this->table;
}
void ht::insert(record* r) //mporei na epistrefei rec* gia na to parw ws orisma sta alla hash tables of satan
{
    //hash epistrefei hashReturnedValue
    //paw sto table[hashReturnedValue] pou einai ena ht_item, oxi ht_item*
    /*
    if(table[hashReturnedValue].rec == NULL) //den exw idi record edw
    {
        table[hashReturnedValue].red = new record(recordaki_mou);
    }
    else if (table[hashReturnedValue].next == NULL) //exw record alla den exw next
    {
        //grafw ston next moy
        table[hashReturnedValue].next = new ht_item;
        table[hashReturnedValue].next->rec =  new record(recordaki_mou);
    }
    else //uparxei kai next
    {
        //psaxnw na vrw to next null gia na paw sto telos tis listas autou tou stoixeiou tou ht
        ht_item * now = table[hval].next;
        while(now->next != NULL)
        {
            now = now->next;
        }
        now->next = new ht_item;;
        now->next->record_pointer = record(my_rec);
    }
    */
}
unsigned int ht::get_size()
{
    return this->size;
}
unsigned int ht::hash(record r) //the hash function, based on a record r(its ID, basically) returns an int.
{
    //antigrafw ta stoixeia tou r sto dynamic record pou tha mpei sto ht mas
    //mod this->size
}

//search //epistrefei to se poio index uparxei to record, else error msg
//prolly useles?//delete //delete from hash table //delete(a, k): delete the k:v pair associated with k, or do nothing if k does not exist