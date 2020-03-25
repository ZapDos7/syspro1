#ifndef _BB_H_
#define _BB_H_

#include <string>
#include "tree.h"
#include <cmath>
#include "record.h"

//blocks and buckets

class block {
private:

    unsigned int count_all; //ola ta krousmata
    unsigned int count_in; //ola ta krousmata pou einai akoma mesa

public:
    tree * my_tree; //dentro me oles tis eggrafes
    std::string* id; //either country or disease name

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
    void print_blk(bool isCountry);
    void print_blk_all(bool isCountry);
};

class bucket {
private:
public:
    bucket * next; //next bucket
    unsigned int num_of_blocks; //size of bucket
    block * blocks; //my block, dld array of blocks

    bucket() {};
    bucket(int bsize);
    ~bucket();
    bucket * get_next();
    block * get_block();
    void insert(record* r, bool isCountry); //herein lies all the zoumi
    unsigned int get_bucket_size();
    block * search(std::string srch);
    void print_bkt(bool isCountry);
    void print_bkt_all(bool isCountry);
};

#endif