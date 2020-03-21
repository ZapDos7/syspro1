#include "tree.h"

tree_node::tree_node(record *r)
{
    this->d = new date;
    //this->d = new date(*(r->get_entryDate());
    this->d = r->get_entryDatePtr();
    this->left = NULL;
    this->right = NULL;
}
tree_node::tree_node()
{
    this->d = NULL;
    this->left = NULL;
    this->right = NULL;
    //this->kati = NULL;
    //this->parent = NULL;
}
tree_node::~tree_node()
{
    this->d = NULL;
    delete(this->d);
    this->left = NULL;
    delete(this->left);
    this->right = NULL;
    delete(this->right);
}




tree::tree()
{
    this->root = NULL;
}

tree::~tree()
{
    this->root = NULL;
    delete(this->root);
}
tree_node* tree::insertR(tree_node* tr, record* r)
{
    date d;
    d.set_day(r->get_entryDate().get_day());
    d.set_month(r->get_entryDate().get_month());
    d.set_year(r->get_entryDate().get_year());
    if (tr==NULL)
    {
        tree_node * tn = new tree_node(r);
        tn->left = NULL;
        tn->right = NULL;
        return tn;
    }
    else if (isLater(*(tr->d), d)==1) //node's date is later compared to d1 so it should be to d1's right (greater)
    {
        tr->right = insertR(tr->right, r);
    }
    else if (isLater(*(tr->d), d)!=1) //-1 or 0
    {
        tr->left = insertR(tr->left, r);
    }
    else
    {
        std::cerr << "Wtf?\n";
        return NULL;
    }
    return NULL;
}
/*void*/tree_node*  tree::insert(tree_node* tr, date *d1) //tin 1i fora prepei na kli8ei me 1o orisma to root tou tree
{
/*    if (tr==NULL)
    {
        tree_node * tn = new tree_node(d1);
        tn->left = NULL;
        tn->right = NULL;
        return tn;
    }
    else if (isLater(*(tr->d), *d1)==1) //node's date is later compared to d1 so it should be to d1's right (greater)
    {
        tr->right = insert(tr->right, d1);
    }
    else if (isLater(*(tr->d), *d1)!=1) //-1 or 0
    {
        tr->left = insert(tr->left, d1);
    }
    else
    {
        std::cerr << "Wtf?\n";
        return NULL;
    }
    return NULL;*/
}

void tree::in_order(tree_node* rt) //https://www.programiz.com/dsa/tree-traversal
{
    if (rt == NULL)
    {
        return;
    }
    in_order(rt->left);
    rt->d->get_date_as_string();
    std::cerr << std::endl;
    in_order(rt->right);
}

tree_node* tree::search(tree_node* tr, date d1) //tin 1i fora prepei na kli8ei me 1o orisma to root tou tree
{
    if (tr->d->get_date_as_string() == d1.get_date_as_string())
    {
        std::cerr << tr->d->get_date_as_string() << "found\n";
        return tr;
    }
    else if (isLater(*(tr->d), d1)==1) //node's date is later compared to d1 so it should be to d1's right (greater)
    {
        std::cerr << "searching right\n";
        return search(tr->right, d1);
    }
    else if (isLater(*(tr->d), d1)==1) //d1 > d
    {
        std::cerr << "searching left\n";
        return search(tr->left, d1);
    }
    else
    {
        std::cerr << "No such date exists here: " << d1.get_date_as_string() << std::endl;
        return NULL; //it's not there
    }
}