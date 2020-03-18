Ioanna Zapalidi
sdi1400044

1st System Programming Assignment

Used: C++11 (Developed on Linux Ubuntu 18.04), used git for version control and valgrind for debugging purposes.

Contents:
- this readme
- Makefile
- diseaseMonitor.cpp (the main program)
- date.h, date.cpp (class date, with date-month-year fields and all the methods required)
- record.h, record.cpp (records class with the required fields & methods)
- ht.h, ht.cpp (classic hash table class and methods, it's used to store the actual records and acts as the data structure of my choice, as the assignment dictates)
- aht.h, aht.cpp (advance hash table)
- tree.h, tree.cpp (BST class and methods)

Use:
- While in the project folder, run "$make" to create the .o files and the executable
- execute "$make run" to execute (to see the parameters values and alter them, see the Makefile file)
- execute "$make val" to execute using valgrind
- execute "$make clean" to clean the working folder.

Notes:
- In the class "record" we check if the exit date is greater than the entry date, if it is set (if it's just a dash, we do not check this, obviously)
- The insert function of the hash table checks whether the ID's inserted are unique or not.
- On the disease and country hash tables: in the bb.h/bb.cpp files I created the assisting classes "block_node", "block" and "bucket". A block node contains the country or disease name, two counters to assist with the instructions and a pointer to the country's/disease's tree. A block contains an array of these block_nodes, and their amount is based on the "-b" parameter given via command line. Lastly, a bucket contains a pointer to its corresponding block, and a pointer to the next bucket, as it should.


Sources:
- Makefile - Software Dev. for Algorithmic Problems, 2019-20
- date.h, date.cpp - my code from last years 1st assignment, without the time stamp class.
- hash function based on this: http://www.cse.yorku.ca/~oz/hash.html

Future Expansions:
- Turn the BST into a BBST