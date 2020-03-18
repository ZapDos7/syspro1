#ifndef _DHT_H_
#define _DHT_H_

#include "bb.h"

class diseaseht
{
private:
    unsigned int size; //size of ht, h1
    bucket* table; //the items
public:
    diseaseht();
    diseaseht(unsigned int sz);
    ~diseaseht();
    unsigned int get_size();
    bucket* get_table();
};

/*
Enallaktika:
// unsigned int ht_hash(const char* s, const int a, const int m) {
    long hash = 0;
    const int len_s = strlen(s);
    for (int i = 0; i < len_s; i++) {
        hash += (long)pow(a, len_s - (i+1)) * s[i];
        hash = hash % m;
    }
    return (unsigned int)hash;
}
apo:
https://github.com/jamesroutley/write-a-hash-table/tree/master/03-hashing
*/

#endif