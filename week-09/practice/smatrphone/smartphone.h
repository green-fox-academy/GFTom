#ifndef SMARTPHONE_H_INCLUDED
#define SMARTPHONE_H_INCLUDED
typedef enum screen_size{
  SMALL,
  MEDIUM,
  BIG
} screen_size_t;

typedef struct smartphone{
  char name[256];
  int release_year;
  screen_size_t screen_size;
} smartphone_t;

char* get_oldest_phone(const smartphone_t* smartphones, int size);
int get_screen_size_count(const smartphone_t* smartphones, int size, screen_size_t screen_size);


#endif // SMARTPHONE_H_INCLUDED
