 #include <stdio.h>
 #include <stdbool.h>
 #include <math.h>
 
 bool est_premier(int n){
  if(n < 2){
    return false;
  }
  if(n == 2){
    return true;
  }
  if(n % 2 == 0){
    return false;
  }
  double limite = sqrt(n);
  for(int i = 3; i <= limite; i+=2){
    if(n % i == 0){
      return false;
    }
  }
  return true;
 }
 
 int main(void){
  printf("Les 25 nombres premiers sont: \n");
  int counter = 0;
  int i = 0;
  while(counter < 25){
    if(est_premier(i)){
      printf("%d: %d\n", counter, i);
      counter++;
    }
    i++;
  }
  return 0;
 }
