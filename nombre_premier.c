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
  for(int i = 0; i <= 25; i++){
    if(est_premier(i)){
      printf("%d\n", i);
    }
  }
  return 0;
 }
