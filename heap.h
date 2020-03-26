#ifndef _HEAP_H_
#define _HEAP_H_

#include <string>
#include "date.h"
#include "tree.h"

//domi "max heap" oxi vasei array alla vasei dentrou, opws protathike sto eclass

class pair
{
private:
public:
    long int pair_counter;
    std::string pair_id;

    pair(std::string pid);
    ~pair();
};

class heap_node
{
private:
public:
    long int counter; //enas metritis == value pou sugkrinoume otan elegxoume me thn heapify. edw metrame posa krousmata exoume metrisei
    std::string id;//disease i country tou opoiou ta krousmata metrisame
    heap_node * left;
    heap_node * right;

    heap_node(pair p);
    heap_node(std::string id_to_be, int num);
    ~heap_node();
};


class heap
{
private:
public:
    heap_node* root; //max value, riza dentrou
    long int size; //posa stoixeia exei mesa o swros. if size < k stis topk, print up to size.

    heap(); //arxika empty
    ~heap();
    void heapify();//diatirisi morfis heap
    void insert(pair p); //ws orisma pairnei pair
    heap_node * pop_root(); //pop root, return new root after calling heapify

    //top-k functions, tr = b->my_tree opou block * b = aht->search(bla) //main
    void topkC(tree* tr, int k); //pas sto record kathe kombou, take disease name, kai se zeugaria (diseasename, counter) kane counter ++. Auta ta zeugaria apothikeuontai se ena array apo zeugaria. Ola auta 1-1 -> heap::insert, heap::heapify. Telos, pop k times to head, heapify.
    void topkC(tree* tr, int k, date d1, date d2); //to idio alla elegxw an entrydate tou tree_node anamesa se d1, d2
    void topkD(tree* tr, int k); //pas sto record kathe kombou, take country name, kai se zeugaria (countryname, counter) kane counter ++. Auta ta zeugaria apothikeuontai se ena array apo zeugaria. Ola auta 1-1 -> heap::insert, heap::heapify. Telos, pop k times to head, heapify.
    void topkD(tree* tr, int k, date d1, date d2); //to idio alla elegxw an entrydate tou tree_node anamesa se d1, d2
    //sto telos prepei na diagrafetai o swros
};
//
#endif