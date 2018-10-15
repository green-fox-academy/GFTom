#include <stdio.h>
#include <stdlib.h>
#include "smartphone.h"

int main()
{
FILE* fp;

  fp = fopen("smartphones.txt" , "r");
  if(fp == NULL) {
    printf("Can't open file\n");
    return -1;
  }

  smartphone_t smartphones[50];

  char name[256];
  int release_year;
  int screen_size;
  int counter = 0;

  while(fscanf(fp, "%s %d %d", name, &release_year, &screen_size) != EOF) {
    strcpy(smartphones[counter].name, name);
    smartphones[counter].release_year = release_year;

    screen_size_t size;
    if(screen_size >= 15)
      size = BIG;
    else if(screen_size >= 12)
      size = MEDIUM;
    else
      size = SMALL;

    smartphones[counter].screen_size = size;
    ++counter;
  }

  fclose(fp);

  printf("The %s is the oldest device in the database\n", get_oldest_phone(smartphones, counter));
  printf("There are %d phones with BIG (>= 15 cm) screen size\n", get_screen_size_count(smartphones, counter, BIG));
  printf("There are %d phones with SMALL (< 12 cm) screen size\n", get_screen_size_count(smartphones, counter, SMALL));

  fp = fopen("prices.txt" , "w");
  if(fp == NULL) {
    printf("Can't open file to write\n");
    return -2;
  }

  for(int i = 0; i < counter; ++i){
    int price = 300;

    switch(smartphones[i].screen_size){
    case SMALL:
      break;
    case MEDIUM:
      price += 100;
      break;
    case BIG:
      price *= 2;
      break;
    }

    int price_loss = (2018 - smartphones[i].release_year) * 50;
    price -= price_loss > 250 ? 250 : price_loss;

    fprintf (fp, "%s %d\n", smartphones[i].name, price);
  }

  fclose(fp);

  return 0;
}
