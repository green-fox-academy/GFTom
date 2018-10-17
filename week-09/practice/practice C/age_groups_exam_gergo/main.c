#include <stdio.h>
#include <stdlib.h>
#include "persons.h"

/*
Implement the functions used below, and make the program work.
*/

int main()
{
    int nmbr_of_persons;

    persons_t* persons = get_persons("persons.txt", &nmbr_of_persons);
    /*
    This function should read persons data from a text file
    and return the datas into a structure-array.
    As you can see, you have to use dynamic memory allocation.
    */


    list_persons_in_age_group(persons, nmbr_of_persons, BETWEEN_30_AND_35);
    /*
    This function should print out the filtered informations based on the given age group
    to the console in the following way:
    Persons in the given age group:
    Pop Simon, aged 28
    Major Anna, aged 26
    */

    return 0;
}
