#ifndef _TREE_H_
#define _TREE_H_

#include "date.h"
#include "record.h"

class tree_node {
private:
public:
    date* d; //my key alla stin periptwsi pou einai diplotupa, exw list of these here
    tree_node* left;
    tree_node* right;

    tree_node();
    tree_node(record * r);
    ~tree_node();
};

class tree {
private:
public:
    tree_node* root;

    tree();
    ~tree();
    void in_order(tree_node* rt); //print in order ta elements tou tree
    tree_node* insert(tree_node* tr, record* r);
    tree_node* search(tree_node* tr, date d1);
};


#endif