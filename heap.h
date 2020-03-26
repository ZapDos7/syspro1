#ifndef _HEAP_H_
#define _HEAP_H_

#include <string>
#include "date.h"
#include "tree.h"
#include "aht.h"

//domi "max heap" oxi vasei array alla vasei dentrou, opws protathike sto eclass

class pair
{
private:
public:
    long int pair_counter;
    std::string pair_id;

    pair();
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
    heap_node * parent;

    heap_node(pair p);
    heap_node();
    ~heap_node();
    bool isLeftNode();
};

pair countDis (tree* tr, std::string disName);
pair countCtr (tree* tr, std::string ctrName);

class heap
{
private:
public:
    heap_node* root; //max value, riza dentrou
    long int size; //posa stoixeia exei mesa o swros. if size < k stis topk, print up to size.
    heap_node* last; //sto katwtero epipedo o deksioteros komvos pou einai != null

    heap(); //arxika empty
    ~heap();
    void heapify();//diatirisi morfis heap
    void insert(pair p); //ws orisma pairnei pair
    heap_node * pop_root(); //pop root, return new root after calling heapify

    //top-k functions, tr = b->my_tree opou block * b = aht->search(bla) //main
    //void topkDiseases(aht * countryht, int k, std::string countryName); //pas sto record kathe kombou, take disease name, kai se zeugaria (diseasename, counter) kane counter ++. Auta ta zeugaria apothikeuontai se ena array apo zeugaria. Ola auta 1-1 -> heap::insert, heap::heapify. Telos, pop k times to head, heapify.
    //void topkDiseasesDates(aht * countryht, int k, std::string countryName, date d1, date d2); //to idio alla elegxw an entrydate tou tree_node anamesa se d1, d2
    //void topkCountries(aht * diseaseht, int k, std::string diseaseName); //pas sto record kathe kombou, take country name, kai se zeugaria (countryname, counter) kane counter ++. Auta ta zeugaria apothikeuontai se ena array apo zeugaria. Ola auta 1-1 -> heap::insert, heap::heapify. Telos, pop k times to head, heapify.
    //void topkCountriesDates(aht * diseaseht, int k, std::string diseaseName, date d1, date d2); //to idio alla elegxw an entrydate tou tree_node anamesa se d1, d2
    //sto telos prepei na diagrafetai o swros
};
//
#endif