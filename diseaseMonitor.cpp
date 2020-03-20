/*
Ioanna Zapalidi, sdi1400044
System Programming Project #1, Spring 2020
*/

#include <iostream>
#include <fstream>

#include "date.h" //my date class
#include "ht.h" //hash table - diki mas domi
#include "aht.h" //"advanced" hash table
#include "tree.h" //bst
#include "record.h" //record class
#include "bb.h" //blocks and buckets

//./$(EXECUTABLE) -p patientRecordsFile.csv -h1 diseaseHashtableNumOfEntries -h2 countryHashtableNumOfEntries -b bucketSize
int main(int argc, char const *argv[])
{
    //test chamber/////////////////////////////////////////////
    /*
    tree t;
    date dd("20-01-2020");
    date dd2("21-01-2021");
    date dd3("19-01-2019");
    t.root = t.insert(t.root, &dd);
    std::cerr << "\nena mpika\n";
    t.insert(t.root, &dd2);
    std::cerr << "\n2 mpika\n";
    t.insert(t.root, &dd3);

    std::cerr << t.root->left->d->get_year() << std::endl;
    std::cerr << t.root->d->get_year() << std::endl;
    std::cerr << t.root->right->d->get_year() << std::endl;*/
    record rec("47 David Williams SARS-1 Denmark 30-05-2009 20-02-2020");
    
    std::string dis1 = rec.get_disease(); //SARS1
    //std::cerr << dis1 << std::endl;
    std::string *dis = &dis1;
    std::cerr << *dis << std::endl; //SARS1
    //block blk(dis);
    //block blk();
    //blk.set_id(dis1);
    //std::cerr << blk.get_id() << std::endl;
    //std::cerr << blk.id << std::endl;
    

    //////////////////////////////////////////////////////////
    char records_file[256];
    int h1=-1; //diseaseHashtableNumOfEntries
    int h2=-1; //countryHashtableNumOfEntries
    int b=-1; //bucketSize
    for (int i = 0; i < argc; i++)
    {
        if (strcmp("-p", argv[i]) == 0)
        {
            strcpy(records_file, argv[i + 1]);
        }

        if (strcmp("-h1", argv[i]) == 0)
        {
            h1 = atoi(argv[i + 1]);
        }

        if (strcmp("-h2", argv[i]) == 0)
        {
            h2 = atoi(argv[i + 1]);
        }

        if (strcmp("-b", argv[i]) == 0)
        {
            b = atoi(argv[i + 1]);
        }
    }
    if((h1<0)||(h2<0)||(b<0))
    {
        std::cerr << "No values for the parameters, please execute again properly." << std::endl;
        exit(-1);
    }
    std::ifstream dataset(records_file); //dataset: recordID FName LName diseaseID Country entryDate exitDate
    std::string line;
    unsigned int records_num=0;
    
    while (std::getline(dataset, line))
    {
        records_num++;
    }
    ht my_ht(records_num*3/4); //ht size = 0.75 * (plithos records from file) => not the worst seek time?
    //reread file and actually keep info
    dataset.clear();
    dataset.seekg(0);
    
    while (std::getline(dataset, line))
    {
        record r(line); //temp r
        my_ht.insert(&r); //edw ginetai kai elegxos gia unique IDs
    }
    
    //check all are saved in HT
    /*for (unsigned int j = 0; j < my_ht.get_size(); j++)
    {
        my_ht.get_table()[j].print_ht_item();//1o stoixeio 
        ht_item * temp = my_ht.get_table()[j].next;
        while (temp != NULL)
        {
            temp->print_ht_item();
            temp = temp->next;
        }
        std::cerr << j <<std::endl;
    }*/


    
    //while(1)
    //{
        std::string com; //command
		std::cout << "Enter desired function:\n";
		std::getline(std::cin, com); //std::cin >> com; doesn't work due to spaces
        char * cstr = new char[com.length() + 1]; //auto 8a kanw tokenize
        strcpy (cstr, com.c_str()); //copy as string to line sto cstr
        char * pch;
        const char delim[2] = " ";
        pch = strtok(cstr, delim);
        std::string comms[7];//i entoli me ta perissotera orismata einai h insertPatientRecord me d2
        int counter = 1;
        comms[0] = pch;
        //check first word to match with command, check entire command if correct
        if (comms[0]=="insertPatientRecord") //1. /insertPatientRecord recordID patientFirstName patientLastName diseaseID entryDate [exitDate]
        //Eisagoume nea eggrafi (exit date may be missiing)
        {
            while (pch != NULL)
            {
                comms[counter] = pch;
                counter++;
                pch = strtok(NULL, delim);
            }
            record r1;
            r1.set_id(comms[1]);
            r1.set_fname(comms[2]);
            r1.set_lname(comms[3]);
            r1.set_disease(comms[4]);
            r1.set_country(comms[5]);
            r1.set_entryD(comms[6]);
            if (counter==6) //den uparxei date 2
            {
                r1.set_exitD("-");
            }
            else
            {
                r1.set_exitD(comms[7]);
            }
            /*if (my_ht.insert(&r1)==-1) //an exoume diplotupo record ID to xeirizetai h insert epistrefontas -1
            {
                std::cerr << "moving on!"; //skip this record
            }
            else
            {
                insert sta disease & country hash table    
            }*/
        }
        else if (comms[0]=="recordPatientExit") //3. /recordPatientExit recordID exitDate
        //Add exit Date to this record
        {
            //my_ht.search();
            //if exitDate > autou tou record.entryD
            //my_ht[ekei] -> set_exitD(exitDate)
            //else
        }
        else if (comms[0]=="exit")
        {
            //make sure stuff is free
            return 0;
        }
        else if (comms[0]=="numCurrentPatients") //4. /numCurrentPatients [disease]
        //an dw8ei to [disease] print posoi patients exoun auto to disease AKOMA (exitDate based)
        //if not, print posoi patient exoun kathe disease AKOMA
        {

        }
        else if (comms[0]=="globalDiseaseStats") //6. /globalDiseaseStats [date1 date2]
        //Print for each disease posa krousmata [metaksu twn 2 dates] //an uparxei date1 prepei na uparxei date2, alla mporei na leipoun kai ta 2
        {
            
        }
        else if (comms[0]=="diseaseFrequency") //8. /diseaseFrequency virusName date1 date2 [country]
        //An oxi country orisma, gia kathe country, print posa Virus metaksu twn 2 dates
        //An nai, mono gi auto to country print posa Virus metaksu twn 2 dates
        {

        }
        else if (comms[0]=="topk-Diseases") //10. /topk-Diseases k country [date1 date2]
        //Gia to country, which k viruses are top (most krousmata) [between dates if given] //an uparxei date1 prepei na uparxei date2, alla mporei na leipoun kai ta 2
        {

        }
        else if (comms[0]=="topk-Countries") //11. /topk-Countries k disease [date1 date2]
        //Gia to virus, which k countries are top (most krousmata) [between dates if given] //an uparxei date1 prepei na uparxei date2, alla mporei na leipoun kai ta 2
        {

        }
        else
        {
            std::cerr << "Unknown Command!\n"; //doesn't exit the program, gives the user another chance to type properly this time.
        }
    //} //end while(1)
    return 0;
}