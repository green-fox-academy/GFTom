#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

 typedef enum strength {
  WEAK,
  MODERATE,
  STRONG,
  ERROR
 } strength_t;

strength_t get_pwd_strength(char *password);
int main()
{
   printf("What is the password? ");
  char password[256];
  scanf("%s", password);

  strength_t strength = get_pwd_strength(password);

  switch(strength){
  case ERROR:
    printf("The password is Error!\n");
    break;
  case WEAK:
    printf("The password is Weak!\n");
    break;
  case MODERATE:
    printf("The password is Moderate!\n");
    break;
  case STRONG:
    printf("The password is Strong!\n");
    break;
  default:
    printf("The password is Unknown!\n");
    break;
  }

  return 0;
}

strength_t get_pwd_strength(char *password)
{
  int size = strlen(password);
  int num_of_punct = 0;
  int num_of_digit = 0;

  for(int i = 0; i < size; ++i){
    if(ispunct(password[i]))
      ++num_of_punct;
    else if(isdigit(password[i]))
      ++num_of_digit;
  }

  if(size > 30 || size < 4)
    return ERROR;

  if(size >= 10 && num_of_digit >= 4 && num_of_punct >= 2)
    return STRONG;
  else if(size >= 6 && num_of_digit >= 1)
    return MODERATE;
  else
    return WEAK;
}
