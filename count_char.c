#include <stdio.h>

int main(void){
  char text[] = "hello world";
  int counter = 0;
  while(text[counter] != '\0'){
    counter++;
  }
  printf("Le mot %s contient %d caractere\n", text, counter);
  return 0;
}
