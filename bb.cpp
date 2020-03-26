#include "bb.h"

//////////////////////////////BLOCKS///////////////////////////////

block::block()
{
    this->count_in = 0;
    this->count_all = 0;
    this->id = NULL;
    this->my_tree = NULL;
}

block::~block()
{
    if (this->id != NULL)
    {
        delete id;
    }
    delete my_tree;
}

void block::set_id(record * r, bool isCountry)
{
    if (isCountry == true)
    {
        //id = r->get_countryPtr();
        std::string c = r->get_country();
        id = new std::string(c);
    }
    else
    {
        //id = r->get_diseasePtr();
        std::string c = r->get_disease();
        id = new std::string(c);
    }
    return;
}

std::string* block::get_idPtr()
{
    return id;
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

void block::update_c_all() //++ an insert aplws
{
    this->count_all++;
    return;
}

void block::update_c_in(bool add) //++ an insert, -- an date d2 ginetai set
{
    if (add == true) //valame record
    {
        this->count_in++;
        return;
    }
    else //add == false, kapoios bghke apo to nosokomeio
    {
        this->count_in--;
        return;
    }
}

void block::print_blk(bool isCountry)
{
    if (id != NULL)
    {
        if (isCountry == false)
        {
            std::cerr << "Disease " << *id << " has " << count_in << " people still hospitalized.\n";
            /*if (my_tree != NULL)
            {
                my_tree->in_order(my_tree->root);
            }*/
        }
        else
        {
            std::cerr << "Country " << *id << " has " << count_in << " people still hospitalized.\n";
            /*if (my_tree != NULL)
            {
                my_tree->in_order(my_tree->root);
            }*/
        }
    }
    return;
}
//void block::print_blk(bool isCountry, bool all) -> na tupwnei kai tous count_all metrites
//gia globaldiseasestats
void block::insert_to_tree(record * r)
{
    if (my_tree == NULL)
    {
        my_tree = new tree;
    }
    my_tree->root = my_tree->insert(my_tree->root, r);
    return;
}
void block::print_blk_all(bool isCountry)
{
    if (id != NULL)
    {
        if (isCountry == false)
        {
            std::cerr << "Disease " << *id << " has had " << count_all << " records.\n";
            /*if (my_tree != NULL)
            {
                my_tree->in_order(my_tree->root);
            }*/
        }
        else
        {
            std::cerr << "Country " << *id << " has had " << count_all << " records.\n";
            /*if (my_tree != NULL)
            {
                my_tree->in_order(my_tree->root);
            }*/
        }
    }
    return;
}
long int block::stats(date date1, date date2)
{
    return my_tree->stats(my_tree->root, date1, date2);
}
long int block::statsC(date date1, date date2, std::string cntrn)
{
    return my_tree->statsCx(my_tree->root, date1, date2, cntrn);
}










/////////////////////////BUCKET//////////////////////

bucket::bucket(int bsize) //-b bsize
{
    this->next = NULL;
    unsigned int posa = 0;
    bsize -= sizeof (bucket*); //prepei na afairesw kai sizeof(bucket*) = next
    bsize -= sizeof (unsigned int); //afairw to megethos tou bucksize
    posa = floor(bsize / sizeof (block)); //posa block nodes xwrane se ena block?
    this->num_of_blocks = posa;
    this->blocks = new block[posa]; //pinakas apo blocks, energopoieitai o constructor tou block
    /*for (unsigned int i=0;i<num_of_blocks;i++)
    {
        blocks[i].id = NULL;
    }*/
}

bucket::~bucket()
{
    delete[] this->blocks;
    delete this->next;
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
    //std::cerr << "Checking if I got " << srch << " in my bucket.\n";
    if (blocks[0].get_count_all() == 0) //to 1o m stoixeio den exei tipote
    {
        //std::cerr << "i got nothing bro.\n";
        return NULL; //den exw pliroforia mesa moy
    }
    else
    {
        for (unsigned int i = 0; i < num_of_blocks; i++)
        {
            if (blocks[i].id == NULL)
            {
                //std::cerr << "Got nothing bro.\n";
                //psakse to next
            }
            else if (*(blocks[i].id) == srch) //if (blocks[i].id == &srch)
            {
                //std::cerr << "Found " << srch << "!\n";
                return &(blocks[i]); //epistrepse mou auto to block
            }
        }
    }
    //edw ftanei an to for loop elikse kai den egine return ara den einai mesa mou auto p theloume
    //opote elegxw ton next mou, an autos den einai null
    if (next == NULL)
    {
        //std::cerr << "my next is null\n";
        return NULL;
    }
    else
    {
        //std::cerr << "gonna check my next\n";
        return this->next->search(srch);
    }
}

void bucket::insert(record* r, bool isCountry) //herein lies all the zoumi
{
    if (isCountry == true)
    {
        if (this->blocks[0].get_idPtr() == NULL) //den uparxei tpt sta blocks tou bcket
        {
            this->blocks[0].set_id(r, isCountry);
            //this->blocks[0].id = r->get_countryPtr();
            this->blocks[0].update_c_all();
            if (r->get_exitDate().set == false) //den exei exit Date ara einai allos enas pou menei mesa, ara to c_in ++;
            {
                this->blocks[0].update_c_in(true);
            }
            this->blocks[0].insert_to_tree(r);
            return;
        }
        else //not null dld uparxoun blocks ara thelw na dw an uparxei block me to country ID mou
        {
            for (unsigned int i = 0; i<this->num_of_blocks; i++)
            {
                //std::cerr << i << "\n";
                if (this->blocks[i].id == nullptr) //brika keni thesi prin to telos
                {
                    //std::cerr << "Brika xwro gia na mpw\n";
                    this->blocks[i].set_id(r, isCountry);
                    this->blocks[i].update_c_all();
                    if (r->get_exitDate().get_date_as_string() == "-") //den exei exit Date ara einai allos enas pou menei mesa, ara to c_in ++;
                    {
                        this->blocks[i].update_c_in(true);
                    }
                    this->blocks[i].insert_to_tree(r);
                    return;
                }
                else if (this->blocks[i].get_id() != r->get_country())
                {
                    //std::cerr << "Den einai i xwra m!\n";
                }
                else //brika to countryid mou
                {
                    this->blocks[i].update_c_all();
                    if (r->get_exitDate().set == false) //den exei exit Date ara einai allos enas pou menei mesa, ara to c_in ++;
                    {
                        this->blocks[i].update_c_in(true);
                    }
                    this->blocks[i].insert_to_tree(r);
                    return;
                }
            }
            this->next->insert(r, isCountry); //edw 9a paw an i while ftasei i = 0 ara bgainei kai den to exei brei se autou tou bucket ta blocks//ara to bazw sto next bucket
        }
    } else //disease
    {
        if (this->blocks[0].get_idPtr() == NULL) //den uparxei tpt sta blocks tou bcket
        {
            this->blocks[0].set_id(r, isCountry);
            //this->blocks[0].id = r->get_diseasePtr();
            this->blocks[0].update_c_all();
            if (r->get_exitDate().get_date_as_string() == "-") //den exei exit Date ara einai allos enas pou menei mesa, ara to c_in ++;
            {
                this->blocks[0].update_c_in(true);
            }
            this->blocks[0].insert_to_tree(r);
            return;
        }
        else //not null dld uparxoun blocks ara thelw na dw an uparxei block me to disease ID mou
        {
            for (unsigned int i = 0; i<this->num_of_blocks; i++)
            {
                //std::cerr << i << "\n";
                if (this->blocks[i].id == nullptr) //brika keni thesi prin to telos
                {
                    //std::cerr << "Brika xwro gia na mpw\n";
                    this->blocks[i].set_id(r, isCountry);
                    this->blocks[i].update_c_all();
                    if (r->get_exitDate().get_date_as_string() == "-") //den exei exit Date ara einai allos enas pou menei mesa, ara to c_in ++;
                    {
                        this->blocks[i].update_c_in(true);
                    }
                    this->blocks[i].insert_to_tree(r);
                    return;
                }
                else if (this->blocks[i].get_id() != r->get_disease())
                {
                    std::cerr << "Den einai i xwra m!\n";
                }
                else //brika to diseaseID mou
                {
                    this->blocks[i].update_c_all();
                    if (r->get_exitDate().get_date_as_string() == "-") //den exei exit Date ara einai allos enas pou menei mesa, ara to c_in ++;
                    {
                        this->blocks[i].update_c_in(true);
                    }
                    this->blocks[i].insert_to_tree(r);
                    return;
                }
            }
            this->next->insert(r, isCountry); //edw 9a paw an i while ftasei i = 0 ara bgainei kai den to exei brei se autou tou bucket ta blocks//ara to bazw sto next bucket
        }
    }
}

void bucket::print_bkt(bool isCountry)
{
    //tupwse ta dika mou
    for (unsigned int i = 0; i < num_of_blocks; i++)
    {
        blocks[i].print_blk(isCountry);
    }
    //tupwse tou next m
    if (next != NULL)
    {
        next->print_bkt(isCountry);
    }
    return; //asfaleia
}

void bucket::print_bkt_all(bool isCountry)
{
    //tupwse ta dika mou
    for (unsigned int i = 0; i < num_of_blocks; i++)
    {
        blocks[i].print_blk_all(isCountry);
    }
    //tupwse tou next m
    if (next != NULL)
    {
        next->print_bkt_all(isCountry);
    }
    return; //asfaleia
}

long int bucket::buck_stats(date d1, date d2) //edw diatrexw tin alusida
{
    long int posa = 0;
    if (blocks[0].id == NULL)
    {
        return posa; //return 0, an den exoun mpei se mena de 8a exw kan next
    }
    else /*(blocks[0].id != NULL)*/ //exw kati na psaksw (an oute to block 0 den exei id, den exei mpei tpt edw)
    {
        for (unsigned int i = 0; i < num_of_blocks; i++) //trekse ola sou ta block
        {
            if (blocks[i].id!=NULL)
            {
                posa += blocks[i].stats(d1, d2);
            }
        }
    }
    if (next == NULL)
    {
        return posa;
    }
    else
    {
        posa += next->buck_stats(d1, d2);
    }
    return posa;
}