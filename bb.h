#ifndef _BB_H_
#define _BB_H_

#include <string>
#include "tree.h"
#include <cmath>
#include "record.h"

//blocks and buckets
class block
{
private:
    std::string* id;//either country or disease name
    unsigned int count_all; //ola ta krousmata
    unsigned int count_in; //ola ta krousmata pou einai akoma mesa
    tree * my_tree; //dentro me oles tis eggrafes
public:
    block();
    ~block();
    std::string* get_idPtr();
    std::string get_id();
    unsigned int get_count_all();
    unsigned int get_count_in();
    tree * get_tree();
    void set_id(record * r, bool isCountry);
    void insert_to_tree(record * r);
    void update_c_all();
    void update_c_in(bool add); //pairnei ws orisma to false otan BGAINEI kapoios dld stin recordExit blabla
};

class bucket
{
private:
    bucket * next; //next bucket
    unsigned int num_of_blocks; //size of bucket
    block * blocks; //my block, dld array of blocks
public:
    bucket(int bsize);
    ~bucket();
    bucket * get_next();
    block * get_block();
    void insert(record* r, bool isCountry); //herein lies all the zoumi
    unsigned int get_bucket_size();
    block * search(std::string srch);
};

#endif