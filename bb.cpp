#include "bb.h"

//////////////////////////////BLOCKS///////////////////////////////
block::block()
{
    this->count_in = 0;
    this->count_all = 0;
    //this->id = new std::string;
    //this->id = NULL;
    //this->my_tree = new tree;
    //this->my_tree = NULL;
}
block::~block()
{
    this->id = NULL;
    delete(this->id);
    this->my_tree = NULL;
    delete(this->my_tree);
}
void block::set_id(record * r, bool isCountry)
{
    if (isCountry==true)
    {
        std::string c = r->get_country(); //katastrefetai me to peras ths klisis tis function
        //std::cerr << c << "\n";
        //this->id = r->get_countryPtr();
        //this->id = &c;
        id = new std::string(c);
        //*(this->id) = c;
    }
    else
    {
        this->id = new std::string;
        this->id = r->get_diseasePtr();
    }
    return;
}
std::string* block::get_idPtr()
{
    return this->id;
}
std::string block::get_id()
{
    return *(this->id);
}
unsigned int block::get_count_all()
{
    return this->count_all;
}
unsigned int block::get_count_in()
{
    return this->count_in;
}
tree * block::get_tree()
{
    return this->my_tree;
}
void block::insert_to_tree(record * r)
{
    this->my_tree->insertR(this->my_tree->root, r);
    //this->my_tree->insert(this->my_tree->root, r->get_entryDate());
    return;
}
void block::update_c_all() //++ an insert aplws
{
    this->count_all++;
    return;
}
void block::update_c_in(bool add) //++ an insert, -- an date d2 ginetai set
{
    if (add==true) //valame record
    {
        this->count_in++;
    }
    else //add == false, kapoios bghke apo to nosokomeio
    {
        this->count_in--;
    }
}














/////////////////////////BUCKET//////////////////////

bucket::bucket(int bsize) //-b bsize
{
    this->next = NULL;
    unsigned int posa = 0;
    bsize -= sizeof(bucket*);//prepei na afairesw kai sizeof(bucket*) = next
    bsize -= sizeof(unsigned int); //afairw to megethos tou bucksize
    posa = floor(bsize/sizeof(block)); //posa block nodes xwrane se ena block?
    this->num_of_blocks = posa;
    this->blocks = new block[posa]; //pinakas apo blocks, energopoieitai o constructor tou block
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

unsigned int bucket::get_bucket_size()
{
    return this->num_of_blocks;
}
block * bucket::search(std::string srch) //orisma: ti psaxnoume?
{
    for (unsigned int i = 0; i < this->num_of_blocks; i++)
    {
        if (this->blocks[i].get_id()==srch) //an sto block[i] moy exw auto to srch string (disease or country ID)
        {
            return &(this->blocks[i]); //epistrepse mou auto to block
        }
        //else continue
    }
    //if it's not found from the above for:
    return NULL;    
}
void bucket::insert(record* r, bool isCountry) //herein lies all the zoumi
{
    if (isCountry == true)
    {
        if (this->blocks[0].get_idPtr() == NULL) //den uparxei tpt sta blocks tou bcket
        {
            this->blocks = new block;
            this->blocks[0].set_id(r, isCountry);
            //this->blocks->set_id(r, isCountry);
            this->blocks[0].update_c_all();
            //this->blocks->update_c_all();
            if (r->get_exitDate().is_set()==false) //den exei exit Date ara einai allos enas pou menei mesa, ara to c_in ++;
            {
                this->blocks[0].update_c_in(true);
                //this->blocks->update_c_in(true);
            }
            //this->blocks[0].insert_to_tree(r);
            ////this->blocks->insert_to_tree(r);
        }
        else //not null dld uparxoun blocks ara thelw na dw an uparxei block me to country ID mou
        {   
            unsigned int i = 0;
            std::string c = r->get_country();
            std::string * cPtr = this->blocks[i].get_idPtr();
            while (*cPtr != c)
            {
                i++;
                cPtr = this->blocks[i].get_idPtr();
            }
            if (i+1==this->num_of_blocks) //xwraei 10 blocks kai esu exeis psaksei 10 xwris na brethei to Country ID ara pame sto next bucket
            {
                this->next->insert(r, isCountry);
            }
            else //psaksame ligotero kai to brhkame
            {
                this->blocks[i].update_c_all();
                if (r->get_exitDate().is_set()==false) //den exei exit Date ara einai allos enas pou menei mesa, ara to c_in ++;
                {
                    this->blocks->update_c_in(true);
                }
                //this->blocks->insert_to_tree(r);
            }
        }
    }
    else
    {
        if (this->blocks == NULL) //den uparxei tpt sta blocks tou bcket
        {
            this->blocks = new block;
            this->blocks[0].set_id(r, isCountry);
            this->blocks[0].update_c_all();
            if (r->get_exitDate().is_set()==false)
            {
                this->blocks[0].update_c_in(false);
            }
            //this->blocks[0].insert_to_tree(r);
        }
        else //not null dld uparxoun blocks ara thelw na dw an uparxei block me to country ID mou
        {   
            unsigned int i = 0;
            std::string c = r->get_disease();
            std::string * cPtr = this->blocks[i].get_idPtr();
            while (*cPtr != c)
            {
                i++;
                cPtr = this->blocks[i].get_idPtr();
            }
            if (i+1==this->num_of_blocks) //xwraei 10 blocks kai esu exeis psaksei 10 xwris na brethei to Country ID ara pame sto next bucket
            {
                this->next->insert(r, isCountry);
            }
            else //psaksame ligotero kai to brhkame
            {
                this->blocks[i].update_c_all();
                if (r->get_exitDate().is_set()==false) //den exei exit Date ara einai allos enas pou menei mesa, ara to c_in ++;
                {
                    this->blocks->update_c_in(false);
                }
                //this->blocks->insert_to_tree(r);
            }
        }
    }
}