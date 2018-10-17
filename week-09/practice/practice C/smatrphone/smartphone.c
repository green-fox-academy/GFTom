#include "smartphone.h"

char* get_oldest_phone(const smartphone_t* smartphones, int size)
{
  int min_index = 0;
  int min_year = smartphones[0].release_year;

  for(int i = 0; i < size; ++i){
    if(smartphones[i].release_year < min_year){
      min_index = i;
      min_year = smartphones[i].release_year;
    }
  }

  return smartphones[min_index].name;
}

int get_screen_size_count(const smartphone_t* smartphones, int size, screen_size_t screen_size)
{
  int counter = 0;
  for(int i = 0; i < size; ++i){
    if(screen_size == smartphones[i].screen_size)
      ++counter;
  }

  return counter;
}
