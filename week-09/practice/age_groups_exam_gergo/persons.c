#include <stdio.h>
#include "persons.h"

persons_t* get_persons(const char* file_name, int* number_of_persons)
{
  FILE *fp;
  fp = fopen(file_name, "r");

  persons_t* persons = malloc(100 * sizeof(persons_t));

  if( fp == NULL)
  {
    printf("Can't read the file\n");
    return NULL;
  }

  char buffer[256];
  char *token;
  int counter = 0;

  while(fgets (buffer, 256, fp))
  {
    token = strtok(buffer, ",-");
    strcpy(persons[counter].name, token);
    token = strtok(NULL, ",-");
    persons[counter].year = atoi(token);
    token = strtok(NULL, ",-");
    persons[counter].month = atoi(token);
    token = strtok(NULL, ",-");
    persons[counter].day = atoi(token);

    ++counter;
  }

  *number_of_persons = counter;

  fclose(fp);
  return persons;
}

void list_persons_in_age_group(persons_t* persons, int number_of_persons, age_groups age_group)
{
  int current_year = 2018;
  int current_month = 10;
  int current_day = 8;

  int max_year;
  int min_year;

  switch(age_group)
  {
  case BETWEEN_15_AND_20:
    max_year = current_year - 15;
    min_year = current_year - 20;
    break;
  case BETWEEN_20_AND_25:
    max_year = current_year - 20;
    min_year = current_year - 25;
    break;
  case BETWEEN_25_AND_30:
    max_year = current_year - 25;
    min_year = current_year - 30;
    break;
  case BETWEEN_30_AND_35:
    max_year = current_year - 30;
    min_year = current_year - 35;
    break;
  case BETWEEN_35_AND_40:
    max_year = current_year - 35;
    min_year = current_year - 40;
    break;
  }

  for(int i = 0; i<number_of_persons; ++i)
  {
    if(persons[i].year < max_year && persons[i].year > min_year)
    {
      printf("Name: %s Age: %d\n", persons[i].name, current_year - persons[i].year);
    }
    else if(persons[i].year == max_year)
    {
      if(persons[i].month < current_month)
      {
        printf("Name: %s Age: %d\n", persons[i].name, current_year - persons[i].year);
      }
      else if(persons[i].month == current_month && persons[i].day <= current_day)
      {
        printf("Name: %s Age: %d\n", persons[i].name, current_year - persons[i].year);
      }
    }
    else if(persons[i].year == min_year)
    {
      if(persons[i].month > current_month)
      {
        printf("Name: %s Age: %d\n", persons[i].name, current_year - persons[i].year);
      }
      else if(persons[i].month == current_month && persons[i].day >= current_day)
      {
        printf("Name: %s Age: %d\n", persons[i].name, current_year - persons[i].year);
      }
    }
  }
}
