#include "ht.h"

ht_item::ht_item()
{
    this->next = NULL;
    this->rec = NULL;
}
ht_item::ht_item(record* r)
{
    this->rec = r;
    this->next = NULL;
}
ht_item::~ht_item(){}
void ht_item::print_ht_item()
{
    std::cerr << this->rec->get_id() << " " 
    << this->rec->get_fname() << " " 
    << this->rec->get_lname() << " " 
    << this->rec->get_disease() << " " 
    << this->rec->get_country() << " " 
    << this->rec->get_entryDate().get_date_as_string() << " " 
    << this->rec->get_exitDate().get_date_as_string() << std::endl;
}


//hash table
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
unsigned int ht::get_size()
{
    return this->size;
}
ht_item* ht::get_table()
{
    return this->table;
}
unsigned int ht::hash(record r) //the hash function, based on a record r(its ID, basically) returns an int.
{
    //based on djb2
    unsigned int result = 5381;
    for (unsigned int i = 0; i < r.get_id().size(); i++)
    {
        result = 33 * result + (unsigned char)r.get_id()[i];
    }
    return result % this->size;
}
/*
Enallaktika:
// unsigned int ht_hash(const char* s, const int a, const int m) {
    long hash = 0;
    const int len_s = strlen(s);
    for (int i = 0; i < len_s; i++) {
        hash += (long)pow(a, len_s - (i+1)) * s[i];
        hash = hash % m;
    }
    return (unsigned int)hash;
}
apo:
https://github.com/jamesroutley/write-a-hash-table/tree/master/03-hashing
*/

void ht::insert(record* r) //mporei na epistrefei rec* gia na to parw ws orisma sta alla hash tables of satan
{   //antigrafw ta stoixeia tou r sto dynamic record pou tha mpei sto ht mas
    unsigned int where = hash(*r);
    //paw sto table[where] pou einai ena ht_item, oxi ht_item*
    if(table[where].rec == NULL) //den exw idi record edw
    {
        table[where].rec = new record(*r);
        //std::cerr << table[where].rec->get_id();
    }
    else if (table[where].next == NULL) //exw record alla den exw next
    {
        if (table[where].rec->get_id()==r->get_id())
        {
            std::cerr << "Dublicate record ID. Fix your dataset and try again.\n";
            exit(-1);
        }
        else //grafw ston next moy
        {
            table[where].next = new ht_item;
            table[where].next->rec =  new record(*r);
            //std::cerr << table[where].rec->get_id();
        }
    }
    else //uparxei kai next
    {
        ht_item * temp = table[where].next;
        if (temp->rec->get_id()==r->get_id())
        {
            std::cerr << "Dublicate record ID. Fix your dataset and try again(1).\n";
            exit(-1);
        }
        else
        {
            while(temp->next != NULL)//psaxnw na vrw to next null gia na paw sto telos tis listas autou tou stoixeiou tou ht
            {
                temp = temp->next; //paw ston epomeno mou kai elegxw an uparxei idi to ID ekei
                if (temp->rec->get_id()==r->get_id()) //an edw mesa vrw to ID tou r, exit
                {
                    std::cerr << "Dublicate record ID. Fix your dataset and try again(2).\n";
                    exit(-1);
                }
            }
            //else, exw brei to telos twn buckets kai paw kai grafw
            temp->next = new ht_item;
            temp->next->rec = new record(*r);
            //std::cerr << table[where].rec->get_id();
        }
    }
}

ht_item* ht::search(record *r)
{
    unsigned int where = hash(*r);
    if(table[where].rec == NULL) //den exw kanena record edw
    {
        std::cerr << "This record isn't in my hash table\n";
        return NULL;
    }
    else//den einai null auto to .rec ara exw eggrafi alla isws den einai i diki m => elegxw ID
    {
        ht_item * now = &(table[where]);
        while (now->next != NULL) //iterate through these buckets opou exw collision gia na vrw an uparxei to r
        {
            if (now->rec->get_id() == r->get_id())
            {
                std::cerr << "Found!\n";
                return now;
            }
            else
            {
                now = now->next; //pame sto epomeno
            }            
        }        
    }    
}