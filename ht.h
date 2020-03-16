#ifndef _HT_H
#define _HT_H_

#include <iostream>
#include <string>
#include "record.h"

class ht_item //functions like bucket
{
private:
    record* rec; //it's ID is the key!!
    int key; //?
    ht_item* next;//node to next
public:
    ht_item();
    ht_item(record* r, int k);
    ~ht_item();
    void print_ht_item();
};

class ht
{
private:
    unsigned int size; //size of ht
    ht_item** table; //the items
    //size_t bucketSize; //to b apo to command line
public:
    ht(unsigned int sz);
    ~ht();
    //Bucket* initBucket(size_t bktsz);
    //void insert(Bucket* bucket, record* item); //insert //insert to hash table
    void insert(ht_item* h, record* r);

    unsigned int get_size();
    unsigned int hash(std::string recordId, int maxVal); //the hash function, based on a record r(its ID, basically) returns an int.
    //search //epistrefei to se poio index uparxei to record, else error msg
    
    //delete //delete from hash table //delete(a, k): delete the k:v pair associated with k, or do nothing if k does not exist
};

#endif