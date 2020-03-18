#ifndef _BB_H_
#define _BB_H_

#include <string>
#include "tree.h"

//blocks and buckets
class block_node
{
private:
    std::string id;//either country or disease name
    unsigned int count_all; //ola ta krousmata
    unsigned int count_in; //ola ta krousmata pou einai akoma mesa
    tree * my_tree;
public:
    block_node();
    block_node(std::string s);
    ~block_node();
    std::string get_id();
    unsigned int get_count_all();
    unsigned int get_count_in();
    tree * get_tree();
};

class block
{
private:
    unsigned int size;
    block_node* bn; //array of blocknodes
public:
    block(unsigned int sz);
    ~block();
};

class bucket
{
private:
    bucket * next; //next bucket
    block * blocks; //my block
public:
    bucket();
    ~bucket();
    bucket * get_next();
    block * get_block();
};

#endif