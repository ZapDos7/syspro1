#ifndef _HT_H
#define _HT_H_

#include <iostream>
#include <string>
#include "record.h"

class ht_item //functions like bucket
{
private:
    record* rec; //it's ID is the key!!
    ht_item* next;//node to next
public:
    ht_item();
    ht_item(record* r);
    ~ht_item();
    void print_ht_item();
};

class ht
{
private:
    unsigned int size; //size of ht
    ht_item* table; //the items
public:
    ht(unsigned int sz);
    ~ht();
    void insert(record* r); //mporei na epistrefei rec* gia na to parw ws orisma sta alla hash tables of satan
    unsigned int get_size();
    unsigned int hash(record r); //the hash function, based on a record r(its ID, basically) returns an int.
    //search //epistrefei to se poio index uparxei to record, else error msg
    //prolly useles?//delete //delete from hash table //delete(a, k): delete the k:v pair associated with k, or do nothing if k does not exist
};

#endif