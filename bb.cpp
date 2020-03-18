#include "bb.h"

block_node::block_node()
{
    this->count_in = 0;
    this->count_all = 0;
    this->id = "";
}
block_node::block_node(std::string s)
{
    this->id = s;
    this->count_in=0;
    this->count_all=0;
}
block_node::~block_node(){}
std::string block_node::get_id()
{
    return this->id;
}
unsigned int block_node::get_count_all()
{
    return this->count_all;
}
unsigned int block_node::get_count_in()
{
    return this->count_in;
}
tree * block_node::get_tree()
{
    return this->my_tree;
}
////

block::block(unsigned int sz)
{
    this->size = sz;
    unsigned int posa = 0;
    posa = sz/sizeof(block_node); //posa block nodes xwrane se ena block?
    this->bn = new block_node[posa]; //ftianxw to array of nodes mou pou arxika einai adeia (empty contrusctor)
}

block::~block()
{
    this->bn = NULL;
    delete(this->bn);
}
//
bucket::bucket()
{
    this->next = NULL;
    this->blocks = NULL;
}
bucket::~bucket()
{
    this->next = NULL;
    this->blocks = NULL;
    delete(this->next);
    delete(this->blocks);
}
bucket * bucket::get_next()
{
    return this->next;
}
block * bucket::get_block()
{
    return this->blocks;
}
