#include "tree.h"

tree_node::tree_node(record *r)
{
    this->d = r->get_entryDatePtr();
    this->left = NULL;
    this->right = NULL;
}
tree_node::tree_node()
{
    this->d = NULL;
    this->left = NULL;
    this->right = NULL;
}
tree_node::~tree_node()
{
    delete this->left;
    delete this->right;
    //delete this->d;
}


/////////////////////////////////////////

tree::tree()
{
    this->root = NULL;
}
tree::~tree()
{
    delete root;
}
tree_node* tree::insert(tree_node* tr, record* r) //arxiki klisi tis: t.root = t.insert(t.root, record * r)
{
    date d; //to date pou paw na balw
    d.set_day(r->get_entryDate().get_day());
    d.set_month(r->get_entryDate().get_month());
    d.set_year(r->get_entryDate().get_year());
    //std::cerr << "Molis mpika stin insert kai paw na valw auto: " << d.get_date_as_string() << "\n";

    if (tr==NULL)
    {
        tree_node * tn = new tree_node(r);
        tn->left = NULL;
        tn->right = NULL;
        //std::cerr << "Molis ekana insert auto: " << tn->d->get_date_as_string() << "\n";
        return tn;
    }
    else if (isLater(*(tr->d), d)==1) //node's date is later compared to d1 so it should be to d1's right (greater)
    {
        tr->right = insert(tr->right, r);
    }
    else if (isLater(*(tr->d), d)<1) //nwritera (-1) i idio date (0)
    {
        tr->left = insert(tr->left, r);
    }
    else
    {
        std::cerr << "How?\n";
        return NULL;
    }
    //return NULL;
}

void tree::in_order(tree_node* rt) //https://www.programiz.com/dsa/tree-traversal
{
    if (rt == NULL)
    {
        return;
    }
    in_order(rt->left);
    std::cerr << rt->d->get_date_as_string() << std::endl;
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
    else if (isLater(*(tr->d), d1)<1) //0 or -1 ara less or equal
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