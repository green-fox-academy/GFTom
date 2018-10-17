#include <stdio.h>
#include <stdlib.h>
#include "persons.h"

int MAX_TEXT_LINE_LENGTH = 100;

typedef enum read_state{
  FIRST_NAME,
  LAST_NAME,
  YEAR,
  MONTH,
  DAY
} read_state_t;

persons_t* get_persons(const char* filename, int* number_of_persons)
{
  FILE *fp;

  fp = fopen("text.txt", "r");
  if (fp == NULL)
  {
    printf("Opening of text.txt was not successful. Terminating!\n");
    return 1;
  }

  persons_t* persons = (persons_t*)malloc(MAX_TEXT_LINE_LENGTH * sizeof(persons_t));
  int persons_counter = 0;
  int char_counter = 0;
  char year_buffer[5];
  char month_buffer[3];
  char day_buffer[3];
  read_state_t r_state = FIRST_NAME;

  char c;
  while ((c = fgetc(fp)) != EOF)
  {
    if(c == ' ')
    {
      r_state = LAST_NAME;
      persons[persons_counter].first_name[char_counter] = '\0';
      char_counter = 0;
      continue;
    }
    else if(c == ',')
    {
      r_state = YEAR;
      persons[persons_counter].last_name[char_counter] = '\0';
      char_counter = 0;
      continue;
    }
    else if(c == '-')
    {
      if(r_state == YEAR){
        r_state = MONTH;
        year_buffer[char_counter] = '\0';
        char_counter = 0;
        continue;
      }
      else if(r_state == MONTH){
        r_state = DAY;
        month_buffer[char_counter] = '\0';
        char_counter = 0;
        continue;
      }
    }
    else if(c == '\n'){
      r_state = FIRST_NAME;
      day_buffer[char_counter] = '\0';
      char_counter = 0;

      persons[persons_counter].year = atoi(year_buffer);
      persons[persons_counter].month = atoi(month_buffer);
      persons[persons_counter].day = atoi(day_buffer);

      ++persons_counter;
      continue;
    }

    if(r_state == FIRST_NAME){
      persons[persons_counter].first_name[char_counter] = c;
    }
    else if(r_state == LAST_NAME){
      persons[persons_counter].last_name[char_counter] = c;
    }
    else if(r_state == YEAR){
      year_buffer[char_counter] = c;
    }
    else if(r_state == MONTH){
      month_buffer[char_counter] = c;
    }
    else if(r_state == DAY){
      day_buffer[char_counter] = c;
    }

    ++char_counter;
  }

  day_buffer[char_counter] = '\0';
  persons[persons_counter].year = atoi(year_buffer);
  persons[persons_counter].month = atoi(month_buffer);
  persons[persons_counter].day = atoi(day_buffer);
  ++persons_counter;

  *number_of_persons = persons_counter;
  fclose(fp);

  return persons;
}

void list_persons_in_age_group(persons_t* persons, int number_of_persons, age_groups age_group)
{
  for(int i = 0; i < number_of_persons; ++i)
  {
    printf("%s %s %d %d %d\n", persons[i].first_name, persons[i].last_name, persons[i].year, persons[i].month, persons[i].day);
  }

  int current_year = 2018;
  int current_month = 10;
  int current_day = 5;

  int min_year;
  int max_year;

  switch(age_group)
  {
  case BETWEEN_15_AND_20:
    min_year = current_year - 20;
    max_year = current_year - 15;
    break;
  case BETWEEN_20_AND_25:
    min_year = current_year - 25;
    max_year = current_year - 20;
    break;
  case BETWEEN_25_AND_30:
    min_year = current_year - 30;
    max_year = current_year - 25;
    break;
  case BETWEEN_30_AND_35:
    min_year = current_year - 35;
    max_year = current_year - 30;
    break;
  case BETWEEN_35_AND_40:
    min_year = current_year - 40;
    max_year = current_year - 35;
    break;
  }

  for(int i = 0; i < number_of_persons; ++i)
  {
    if(persons[i].year < max_year && persons[i].year > min_year)
    {
      printf("%s %s\n", persons[i].first_name, persons[i].last_name);
    }
    else if(persons[i].year == min_year)
    {
      if(persons[i].month > current_month)
      {
        printf("%s %s\n", persons[i].first_name, persons[i].last_name);
      }
      else if(persons[i].month == current_month && persons[i].day >= current_day)
      {
        printf("%s %s\n", persons[i].first_name, persons[i].last_name);
      }
    }
    else if(persons[i].year == max_year)
    {
      if(persons[i].month < current_month)
      {
        printf("%s %s\n", persons[i].first_name, persons[i].last_name);
      }
      else if(persons[i].month == current_month && persons[i].day <= current_day)
      {
        printf("%s %s\n", persons[i].first_name, persons[i].last_name);
      }
    }
  }
}
