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
    std::cerr << "deleting heap node\n";
    if (this->left!=NULL) delete this->left;
    if (this->right!=NULL) delete this->right;
    if (this->parent!=NULL) delete this->parent;
}
bool heap_node::isLeftNode()
{
    if (this->parent==NULL)
    {
        std::cerr << "You're checking the root.\n";
        return true;
    }
    else return (this->parent->left->id==this->id); //an isxuei i isotita -> true giati eimai tou mpampa moy to left paidi, else eimai to right
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

void heap::heapify()
{
    return;
}
void heap::insert(pair p)
{
    if (p.pair_id!="") //den mou dwses ws orisma kapoia kotsana
    {
        if (last==root) //1o insert
        {
            root = new heap_node;
            root->id = p.pair_id;//edw mpainei to p
            root->counter = p.pair_counter;
            root->left = NULL;
            root->right = NULL;
            this->last = root;
            //heapify den xreiazetai edw, exw 1 prama kai eimai idi swros
        }
        else if (last->isLeftNode()==true)
        {
            last->parent->right = new heap_node;
            last->parent->right->id = p.pair_id;//edw mpainei to p
            last->parent->right->counter = p.pair_counter;
            last->parent->right->left = NULL;
            last->parent->right->right = NULL;
            this->last = last->parent->right; //to neo last einai to deksi paidi tou mpampa tou proigoumenou last
            //heapify()
        }
        else //if (last->isLeftNode()==false)
        {
            heap_node * curr;
            curr = last;
            while(curr->isLeftNode()==false)
            {
                curr = curr->parent;
            }
            if(curr==this->root)
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
                this->last = curr->left;
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
                this->last = curr->right->left;
            }
        }
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