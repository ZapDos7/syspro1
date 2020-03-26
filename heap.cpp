#include "heap.h"

////////////////proswrina zeugaria pou kratane info pou tha mpei se heap
pair::pair(std::string pid)
{
    this->pair_counter = 0;
    this->pair_id = pid;
}
pair::~pair(){}


/////////////////heap node
heap_node::heap_node(pair p)
{
    this->counter = p.pair_counter;
    this->id = p.pair_id;
    this->left = NULL;
    this->right = NULL;

}
heap_node::heap_node(std::string id_to_be, int num) //ta stoixeia ta pairnei apo pair ^
{
    this->counter = num;
    this->id = id_to_be;
    this->left = NULL;
    this->right = NULL;
}
heap_node::~heap_node()
{
    if (this->left!=NULL) delete this->left;
    if (this->right!=NULL) delete this->right;
}

///////////////////heap
heap::heap()
{
    this->root = NULL;
    this->size = 0;
}

heap::~heap()
{
    delete this->root;
}
void heap::heapify()
{
    return;
}
void heap::insert(pair p) //https://en.wikipedia.org/wiki/Heapsort#Floyd's_heap_construction
{

}

heap_node * heap::pop_root()
{

}

void heap::topkC(tree* tr, int k)
{
    //tr->
}
void heap::topkC(tree* tr, int k, date d1, date d2)
{

}
void heap::topkD(tree* tr, int k)
{

}
void heap::topkD(tree* tr, int k, date d1, date d2)
{

}