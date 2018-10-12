#ifndef PERSONS_H
#define PERSONS_H

typedef enum {
    BETWEEN_15_AND_20,
    BETWEEN_20_AND_25,
    BETWEEN_25_AND_30,
    BETWEEN_30_AND_35,
    BETWEEN_35_AND_40
} age_groups;

typedef struct persons{
  char name[100];
  int year;
  int month;
  int day;
} persons_t;

persons_t* get_persons(const char* file_name, int* number_of_persons);
void list_persons_in_age_group(persons_t* persons, int number_of_persons, age_groups age_group);

#endif // PERSONS_H
