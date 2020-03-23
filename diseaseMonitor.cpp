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

int main(int argc, char const *argv[])
{
    //test chamber/////////////////////////////////////////////
    
    /*
    record rec("47 David Williams SARS-1 Denmark 30-05-2009 20-02-2020");
    record rec2("39 Mary Sanders FLU-2018 France 12-06-2012 04-01-2017");
    
    
    bucket bkt(1024);
    bkt.insert(&rec, true);
    std::cerr << "bucket insert is ok!\n";
    
    bkt.insert(&rec2, true);
    std::cerr << "2ok\n\n";
    block *blockaki =  bkt.search("France");
    if (blockaki==NULL)
    {
        std::cerr << "this shouldnt happen\n";
    }
    else
    {
        blockaki->print_blk();
    }
    */
    //why is sizeof(block)==sizeof(bucket)? block should be +4 bytes due to one more unsigned int











    
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

    aht diseaseHT(h1, b);
    aht countryHT(h2, b);
    //reread file and actually keep info
    dataset.clear();
    dataset.seekg(0);
    
    while (std::getline(dataset, line))
    {
        record r(line); //temp r
        /*if (r.get_exitDate().set==true)
        {
            std::cerr << r.get_exitDate().get_date_as_string() << "\n";
        }*/
        
        int elegxos = my_ht.insert(&r); //edw ginetai kai elegxos gia unique IDs
        if (elegxos == -1)
        {
            break;//sto piazza eipw8ike oti an brethei kapoio ID duplicate, na proxwrame stis entoles & na mhn sunexizoun ta insertions.
        }
        else
        {
            diseaseHT.ainsert(&r, false);
            countryHT.ainsert(&r, true);
        }
        
    }
    //std::cerr << "\n\n";
    //my_ht.print_ht();
    //std::cerr << "\n\n";
    //diseaseHT.print_aht();
    //std::cerr << "\n\n";
    //countryHT.print_aht();
    
    
    
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
        std::string comms[8];//i entoli me ta perissotera orismata einai h insertPatientRecord me d2
        int counter = 0;
        comms[0] = pch;
        //check first word to match with command, check entire command if correct
        if (comms[0]=="insertPatientRecord") //1. /insertPatientRecord recordID patientFirstName patientLastName diseaseID entryDate [exitDate]
        //Eisagoume nea eggrafi (exit date may be missiing)
        {
            while (pch != NULL)
            {
                //std::cerr << pch;
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
            if (counter==8) //uparxei date 2
            {
                r1.set_exitD(comms[counter-1]);
            }
            else
            {
                r1.set_exitD("-");
            }            
            int elegxos2 = my_ht.insert(&r1); //edw ginetai kai elegxos gia unique IDs
            if (elegxos2 == -1)
            {
                std::cerr << "Record error. Exiting.\n";
            }
            else
            {
                std::cerr << "OK!\n";
                diseaseHT.ainsert(&r1, false);
                countryHT.ainsert(&r1, true);
            }
            //working example: insertPatientRecord 1010 Mitsos Mitsou SARS-1 France 16-02-1995
        }
        else if (comms[0]=="recordPatientExit") //3. /recordPatientExit recordID exitDate
        //Add exit Date to this record
        {
            //e.g.: recordPatientExit 47 06-04-2021 //epistrefei already has exit date
            //e.g.: recordPatientExit 89 06-04-2021 //epistrefei ok
            //e.g.: recordPatientExit 89 06-04-1500 //epistrefei oti den eisai o Doctor
            while (pch != NULL)
            {
                comms[counter] = pch;
                counter++;
                pch = strtok(NULL, delim);
            }
            ht_item * h = my_ht.search(comms[1]);
            if (h==NULL)
            {
                std::cerr << "Can't update this record as it doesn't exist.\n";
            }
            else
            {
                date d2(comms[2]);
                //std::cerr << "Paw na balw: "  <<d2.get_date_as_string() << "\n";
                date *d1 = h->rec->get_exitDatePtr();
                std::cerr << "My exit date is " << h->rec->get_exitDate().get_date_as_string() << "\n";
                date *din = h->rec->get_entryDatePtr();
                if (d1->get_date_as_string()=="-") //eixe paulitsa
                {
                    if ( isLater(d2, *din)==1)
                    {
                        std::cerr << "Entry date later than desired exit date. You're not The Doctor.\n";
                    }
                    else
                    {
                        h->rec->set_exitD(d2.get_date_as_string()); //twra den exei!
                        std::cerr << "Updated record: " << comms[1] << " with exit date: " << h->rec->get_exitDate().get_date_as_string() << "\n";
                    }
                }
                else
                {
                    std::cerr << "This record alread has an exit date.\n";
                }
                
            }
        }
        else if (comms[0]=="exit")
        {
            //exoun akoma leaks oi: tree::insert kai ht::insert
            delete[] cstr;
            return 0;
        }
        else if (comms[0]=="numCurrentPatients") //4. /numCurrentPatients [disease]
        {
            //eg: numCurrentPatients SARS-1
            //an dw8ei to [disease] print posoi patients exoun auto to disease AKOMA (exitDate based)
            while (pch != NULL)
            {
                comms[counter] = pch;
                counter++;
                pch = strtok(NULL, delim);
            }
            if (counter > 1) //exoume 2o orisma
            {
                std::string dis(comms[1]);
                block * blockPtr = diseaseHT.search(dis);
                if (blockPtr==NULL)
                {
                    std::cout << "0\n"; //den eixame kanena krousma
                }
                else
                {
                    blockPtr->print_blk();
                }
            }
            else //den exoume 2o orisma
            {   //if not, print posoi patient exoun kathe disease AKOMA - gia KATHE disease ara peridiavenw to diseaseHT
                for (unsigned int i = 0; i < h2; i++) //gia kathe bucket* sto hash table
                {
                    diseaseHT.get_table()[i].print_bkt();
                }
                
            }
        }
        else if (comms[0]=="globalDiseaseStats") //6. /globalDiseaseStats [date1 date2]
        //Print for each disease posa krousmata [metaksu twn 2 dates] //an uparxei date1 prepei na uparxei date2, alla mporei na leipoun kai ta 2
        {
            
        }
        else if (comms[0]=="diseaseFrequency") //8. /diseaseFrequency virusName date1 date2 [country]
        //An oxi country orisma, gia kathe country, print posa Virus metaksu twn 2 dates
        //An nai, mono gi auto to country print posa Virus metaksu twn 2 dates
        {
            //if not exists, return 0
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
        delete[] cstr; //just in case
    //} //end while(1)
    return 0;
}