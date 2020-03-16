#ifndef _TREE_H_
#define _TREE_H_

#include "date.h"

class tree_node
{
private:
public:
    date* d; //my key
    tree_node* left;
    tree_node* right;
    //tree_node* parent;
    //methods
    tree_node(date d1);
    ~tree_node();
};

class tree
{
private:
    tree_node* root;
public:
    tree(/* args */);
    ~tree();
    tree_node* get_root();
    //void in_order(tree_node* rt);
    tree_node* insert(tree_node* tr, date d1);
    //tree_node* search(tree_node* tr, date d1);
    //remove
};

#endif