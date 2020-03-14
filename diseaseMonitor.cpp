#include <iostream>

#include "date.h"
#include "record.h"
//./$(EXECUTABLE) -p patientRecordsFile.csv -h1 diseaseHashtableNumOfEntries -h2 countryHashtableNumOfEntries -b bucketSize
int main(int argc, char const *argv[])
{
    //test chamber
    std::string line = "47 David Williams SARS-1 Denmark 30-05-2009 20-02-2020";
    record r1(line);
    std::cout << r1.get_id() << std::endl << r1.get_fname()<< std::endl << r1.get_lname()<< std::endl << r1.get_country()<< std::endl << r1.get_disease() << std::endl << r1.get_entryDate().get_date_as_string()<< std::endl << r1.get_exitDate().get_date_as_string();
    //date d1("30-05-2009");
    //std::cout <<d1.get_day()<<" "<<d1.get_month()<<" "<<d1.get_year()<<"\n";
    /*STEPS:
    1.  Read patient records file
        Check for unique recordIDs & correctly typed info (exitDate > entryDate else problem)
        if problem: exit msg & exit
    2.  Save these in struct
    3.  Await for user input:

    A. /globalDiseaseStats [date1 date2]
        Print for each disease posa krousmata [metaksu twn 2 dates] //an uparxei date1 prepei na uparxei date2, alla mporei na leipoun kai ta 2
    B. /diseaseFrequency virusName [country] date1 date2
        An oxi country orisma, gia kathe country, print posa Virus metaksu twn 2 dates
        An nai, mono gi auto to country print posa Virus metaksu twn 2 dates
    C. /topk-Diseases k country [date1 date2]
        Gia to country, which k viruses are top (most krousmata) [between dates if given] //an uparxei date1 prepei na uparxei date2, alla mporei na leipoun kai ta 2
    D. /topk-Countries k disease [date1 date2]
        Gia to virus, which k countries are top (most krousmata) [between dates if given] //an uparxei date1 prepei na uparxei date2, alla mporei na leipoun kai ta 2
    E. /insertPatientRecord recordID patientFirstName patientLastName diseaseID entryDate [exitDate]
        Eisagoume nea eggrafi (exit date may be missiing)
    F. /recordPatientExit recordID exitDate
        Add exit Date to this record
    G. /numCurrentPatients [disease]
        an dw8ei to [disease] print posoi patients exoun auto to disease AKOMA (exitDate based)
        if not, print posoi patient exoun kathe disease AKOMA
    H. /exit
        Just yeet [SOS FREE MEMORY]
    */
    return 0;
}

/*
Patient Records:
recordID    FName   LName   diseaseID   Country     entryDate   exitDate
889         Mary    Smith   COVID-2019  China       25-1-2019   27-1-2019
776         Larry   Jones   SARS-1      Italy       10-02-2003  –
125         Jon     Dupont  H1N1        USA         12-02-2016  15-02-2016
*/

/*
Domes we will need:
1. 2 hash tables (gia diseased & countries) (dynamically create buckets gia collision)
2. BBST gia apothikeusi olwn twn eggrafwn twn patient kapoiou disease. Taksinomimeno dentro basei entryDate
3. BBST gia apothikeusi olwn twn eggrafwn twn patient kapoias xwras. Taksinomimeno dentro basei entryDate
XRISI POINTERS <=> OXI DIPLOTPA STI MNIMI
4. gia topK: on the fly creation of binary heap me kathe kombo na krataei to sunolo twn krousmatwn ana country/disease
5. whatever we may need
*/