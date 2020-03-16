Ioanna Zapalidi
sdi1400044

1st SysPro Assignment

Used: C++11

Contents:
- this readme
- Makefile
- diseaseMonitor.cpp (the main program)
- date.h, date.cpp (class date, with date-month-year fields and all the methods required)
- record.h, record.cpp (records class with the required fields & methods)
- ht.h, ht.cpp (classic hash table class and methods, it's used to store the actual records and acts as the data structure of my choice, as the assignment dictates)
- countryht.h, countryht.cpp (country hash table)
- disease.h, disease.cpp (disease hash table)
- tree.h, tree.cpp (BST class and methods)

Use:
- While in the project folder, run "$make" to create the .o files and the executable
- run "$make run" to execute (to see the parameters values and alter them, see the Makefile file)
- run "$make clean" to clean the working folder.

Notes:
- In the class "record" we check if the exit date is greater than the entry date, if it is set (if it's just a dash, we do not check this, obviously)
- The insert function of the hash table checks whether the ID's inserted are unique or not.

Sources:
- Makefile - Software Dev. for Algorithmic Problems, 2019-20
- date.h, date.cpp - my code from last years 1st assignment, without the time stamp class.
- hash function based on this: http://www.cse.yorku.ca/~oz/hash.html