Ioanna Zapalidi
sdi1400044

1st SysPro Assignment

Contents:
- this readme
- Makefile
- diseaseMonitor.cpp (the main program)
- date.h, date.cpp (class date, with date-month-year fields and all the methods required)
- record.h, record.cpp (records class with the required fields & methods)
- ht.h, ht.cpp (classic hash table class and methods, it's used to store the actual records and acts as the data structure of my choice, as the assignment dictates)
- bht.h bht.cpp (a hash table specifically used for this assignment, an alteration of the classic hash table - this one has blocks and all else needed)
- tree.h, tree.cpp (BST class and methods)

Use:
- While in the project folder, run "$make" to create the .o files and the executable
- run "$make run" to execute (to see the parameters values and alter them, see the Makefile file)
- run "$make clean" to clean the working folder.

Supporting Functions:
- isBetween: returns if a date is between two others

Future Expansions:
- More accurate date struct (check month-day combo)

Sources:
- Makefile - Software Dev. for Algorithmic Problems, 2019-20
- date.h, date.cpp - my code from last years 1st assignment, without the time stamp class.