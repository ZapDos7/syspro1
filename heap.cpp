#include "heap.h"

////////////////proswrina zeugaria pou kratane info pou tha mpei se heap
pair::pair()
{
    this->pair_counter = 0;
    this->pair_id = "";
}
pair::pair(std::string pid)
{
    this->pair_counter = 0;
    this->pair_id = pid;
}
pair::~pair(){}
/////////////////boithitikes
pair countDis (tree* tr, std::string disName)
{
    pair p;
    p.pair_counter = tr->statsAllDisease(tr->root, disName); //posa krousmata exei auto to dentro gia auto to disease
    p.pair_id = disName;
    return p;
}
pair countCtr (tree* tr, std::string ctrName)
{
    pair p;
    p.pair_counter = tr->statsAllCountry(tr->root, ctrName); //posa krousmata exei auto to dentro gia auto to country
    p.pair_id = ctrName;
    return p;
}

/////////////////heap node
heap_node::heap_node(pair p)
{
    this->counter = p.pair_counter;
    this->id = p.pair_id;
    this->left = NULL;
    this->right = NULL;
    this->parent = NULL;
}
heap_node::heap_node()
{
    this->counter = 0;
    this->id = "";
    this->left = NULL;
    this->right = NULL;
}
heap_node::~heap_node()
{
    //std::cerr << "deleting heap node\n";
    if (this->left!=NULL) delete this->left;
    if (this->right!=NULL) delete this->right;
    //if (this->parent!=NULL) delete this->parent; //etrwge stack overflow
}
bool heap_node::isLeftNode()
{
    if (this->parent==NULL)
    {
        //std::cerr << "You're checking the root.\n";
        return true;
    }
    else if (this->parent->left->id==this->id)//an isxuei i isotita -> true giati eimai tou mpampa moy to left paidi
    {
        return true;
    }
    else// if (this->parent->right==this)
    {
        return false;
    }
}
void heap_node::print_heap_node()
{
    std::cout << this->id << " " << this->counter << "\n";
    return;
}

///////////////////heap
heap::heap()
{
    this->root = NULL;
    this->size = 0;
    this->last = this->root;
}

heap::~heap()
{
    std::cerr << "deleting heap\n";
    //delete this->last;
    if (this->root!=NULL) delete this->root;
}
void heap::print_heap(heap_node* hn)
{
    if (hn==NULL) return;
    if (hn->isLeftNode()==true)
    {
        std::cerr << "eimai left ";
    }
    else if (hn->isLeftNode()==false)
    {
        std::cerr << "eimai right ";
    }
    hn->print_heap_node();
    print_heap(hn->left);
    print_heap(hn->right);
}
void heap::heapify()
{
    return;
}
void heap::insert(pair p)
{
    if (p.pair_id!="") //den mou dwses ws orisma kapoia kotsana
    {
        if (root==NULL) //1o insert
        {
            std::cerr << "vazw riza\n";
            root = new heap_node;
            root->id = p.pair_id;//edw mpainei to p
            root->counter = p.pair_counter;
            root->left = NULL;
            root->right = NULL;
            root->parent = NULL;
            //this->last = root;
            //std::cerr << "evala: ";
            //root->print_heap_node();
            //heapify den xreiazetai edw, exw 1 prama kai eimai idi swros
        }
        else if (last->isLeftNode()==true) //mazi kai i riza
        {
            if (last->parent!=NULL) //den bazw sti riza
            {
                //std::cerr << "to teleutaio pou evala itan left kai oxi i riza\n";
                last->parent->right = new heap_node;
                last->parent->right->id = p.pair_id;//edw mpainei to p
                last->parent->right->counter = p.pair_counter;
                last->parent->right->left = NULL;
                last->parent->right->right = NULL;
                last->parent->right->parent = last->parent;
                this->last = last->parent->right; //to neo last einai to deksi paidi tou mpampa tou proigoumenou last
                //std::cerr << "evala: ";
                //last->print_heap_node();
                //std::cerr << "o right tou mpampa mou leei: ";
                //last->parent->right->print_heap_node();
                //this->parent->left->id==this->id
            }
            else //paw na valw meta ti riza
            {
                //std::cerr << "vazw meta ti riza\n";
                last->left = new heap_node;
                last->left->id = p.pair_id;
                last->left->counter = p.pair_counter;
                last->left->left = NULL;
                last->left->right = NULL;
                last->left->parent = last;
                this->last = last->left;
                //std::cerr << "evala: ";
                //last->print_heap_node();
            }
            //heapify()
        }
        else if (last->isLeftNode()==false)
        {
            //std::cerr << "to teleutaio pou evala itan right\n";
            heap_node * curr;
            curr = last;
            //std::cerr << "paw na kanw backtrack\n";
            while(curr->isLeftNode()==false)
            {
                //std::cerr << "elegxw ton mpampa m\n";
                curr = curr->parent;
            }
            if(curr==this->root) //eftasa se riza ara paw sto deksi upodentro
            {
                while (curr->left!=NULL) //pame sto deksi upodentro oso pio **left** ginetai
                {
                    curr = curr->left;
                }//kai xwnomaste
                curr->left = new heap_node;
                curr->left->id = p.pair_id;
                curr->left->counter = p.pair_counter;
                curr->left->left = NULL;
                curr->left->right = NULL;
                curr->left->parent = curr;
                this->last = curr->left;
                //std::cerr << "\nevala: ";
                //last->print_heap_node();
                //heapify()
            }
            else
            {
                curr = curr->parent; //paw allo 1 curr = curr->parent
                curr->right->left = new heap_node;
                curr->right->left->id = p.pair_id;
                curr->right->left->counter = p.pair_counter;
                curr->right->left->left = NULL;
                curr->right->left->right = NULL;
                curr->right->left->parent = curr->right;
                this->last = curr->right->left;
                //std::cerr << "\nevala: ";
                //last->print_heap_node();
                //heapify()
            }
        }/*
        else
        {
            std::cerr << "You can't be here!\n";
        }*/
        
    }
}

heap_node * heap::pop_root()
{
    return NULL;
    //return root, heapify
}
/*
void heap::topkDiseases(aht * countryht, int k, std::string countryName)
{
    block * b = countryht->search(countryName);
    //array apo pair i
    //insert to heap ta pairs
    //pop k times to root, print.
    //heapify
}
void heap::topkDiseasesDates(aht * countryht, int k, std::string countryName, date d1, date d2)
{

}
void heap::topkCountries(aht * diseaseht, int k, std::string diseaseName)
{

}
void heap::topkCountriesDates(aht * diseaseht, int k, std::string diseaseName, date d1, date d2)
{

}*/