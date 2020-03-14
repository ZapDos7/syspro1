#include <iostream>
#include "record.h"
/*This class will hold all the actual records, which shall be accessed by the respectable BST's of each "bht" hash table (h1, h2)*/

class ht_node
{
private:
    record rec;
    ht_node* next; //edw pane lista me ta 
public:
    ht_node(record * record);
    ~ht_node();
    //ht_node* get_next();
};

class ht
{
private:
    unsigned int size;
    ht_node** table;
public:
    ht(unsigned int sz);
    ~ht();
    unsigned int get_size();
    int hash(ht_node* nd); //the hash function, based on a record r(its ID, basically) returns an int.
    //search //epistrefei to se poio index uparxei to record, else error msg
    //insert //insert ht_node to hash table
    //delete //delete ht_node from hash table
};