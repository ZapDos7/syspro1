#include "tree.h"

tree_node::tree_node(date d1)
{
    this->d = new date(d1);
    this->left = NULL;
    this->right = NULL;
    //this->parent = NULL;
}
tree_node::~tree_node()
{
    this->d = NULL;
    delete(this->d);
    this->left = NULL;
    //delete(this->left);
    this->right = NULL;
    //delete(this->right);
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
tree_node* tree::get_root()
{
    return this->root;
}
tree_node* tree::insert(tree_node* tr, date d1) //tin 1i fora prepei na kli8ei me 1o orisma to root tou tree
{
    if (this->root==NULL) //i arxi tou dentrou - den eixame tpt before - first node to be added
    {
        this->root = new tree_node(d1);
        this->root->left = NULL;
        this->root->right = NULL;
        //this->root->parent = NULL;
        return this->root;
    }
    //else, exoume root opote blepoume an einai to value mas ligotero apo to d1:
    else if (isLater(*(this->root->d), d1)==false) //node's date is later compared to d1 so it should be to d1's right (greater)
    {
        this->root->right = insert(this->root->right, d1);
    }
    else //it's to my left
    {
        this->root->left = insert(this->root->left, d1);
    }
}
/*
void tree::in_order(tree_node* rt) //https://www.programiz.com/dsa/tree-traversal
{
    if (rt == NULL)
    {
        return;
    }
    in_order(rt->left);
    this->root->d->get_date_as_string();
    std::cerr << std::endl;
    in_order(rt->right);
}
*/
/*
tree_node* tree::search(tree_node* tr, date d1) //tin 1i fora prepei na kli8ei me 1o orisma to root tou tree
{
    if (tr==NULL) //i arxi tou dentrou - den eixame tpt before - first node to be added
    {
        return NULL;
    }
    //else, exoume root opote blepoume an einai to value mas ligotero apo to d1:
    else if (isLater(*(this->root->d), d1)==true) //node's date is later compared to d1 so it should be to d1's right (greater)
    {
        return search(this->root->right, d1);
    }
    else //it's to my left
    {
        return search(this->root->left, d1);
    }
}
*/