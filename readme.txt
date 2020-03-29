Ioanna Zapalidi
sdi1400044

1st System Programming Assignment

Used: C++11 (Developed on Linux Ubuntu 16.04), used git for version control and valgrind for debugging purposes.

Validator results:
- Passes all tests minus 5-12 (topk)

Contents:
- this readme
- Makefile
- diseaseMonitor.cpp (the main program)
- date.h, date.cpp (class date, with date-month-year fields and all the methods required)
- record.h, record.cpp (records class with the required fields & methods)
- ht.h, ht.cpp (classic hash table class and methods, it's used to store the actual records and acts as the data structure of my choice, as the assignment dictates)
- aht.h, aht.cpp (advance hash table)
- tree.h, tree.cpp (BST class and methods)
- heap.h, heap.cpp (heap (& heap_node) class and methods)

Use:
- While in the project folder, run "$make" to create the .o files and the executable
- execute "$make run" to execute (to see the parameters values and alter them, see the Makefile file)
- execute "$make val" to execute using valgrind (requires it to be installed: sudo apt-get install valgrind)
- execute "$make clean" to clean the working folder.

Notes:
- In the class "record" we check if the exit date is greater than the entry date, if it is set (if it's just a dash, we do not check this, obviously)
- The insert function of the hash table checks whether the ID's inserted are unique or not.
- On the disease and country hash tables: in the bb.h/bb.cpp files I created the assisting classes "block" and "bucket". A bucket contains an array of blocks.
- Since my implementation of these hash tables is unified, the insertion methods and some constructors (wherever it is needed, basically) take a boolean arguement "isCountry" which is true when it comes to the country hash table and its methods, else it is false.
- The supporting function "isLater(d1,d2)" (date files) returns -1 if date d1 is later than d2, 0 if they are the same and 1 if d2 is later than d1.
- The supporting function "isBetween(d,d1,d2)" returns true if d1<d<d2 (datewise), else false.

Conclusions:
- Trees are optimal for ranged search (between two values) in a dataset.
- Hash tables are optimal for searching based on an ID (equality checking).
- Heaps are optimal for retrieving max or min value(s) of a dataset.

Sources:
- Makefile - Software Dev. for Algorithmic Problems, 2019-20
- date.h, date.cpp - my code from last years 1st assignment, without the time stamp class & with another assisting function.
- The hash function for my hash table based on this: http://www.cse.yorku.ca/~oz/hash.html
- The hash function for the disease and country hash tables is a variation of this, but with a bit more complex math & with a better distribution.