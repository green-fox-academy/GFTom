#ifndef PERSONS_H
#define PERSONS_H

typedef struct persons {
  char first_name[20];
  char last_name[20];
  int year;
  int month;
  int day;
} persons_t;

typedef enum {
    BETWEEN_15_AND_20,
    BETWEEN_20_AND_25,
    BETWEEN_25_AND_30,
    BETWEEN_30_AND_35,
    BETWEEN_35_AND_40
} age_groups;

persons_t* get_persons(const char* filename, int* number_of_persons);
void list_persons_in_age_group(persons_t* persons, int number_of_persons, age_groups age_group);


#endif
