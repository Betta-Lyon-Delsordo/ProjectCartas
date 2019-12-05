#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "inout.h"

int confirm() {
  char ans;

  do {
      printf("Are you sure you want to exit? (y/n): ");
  
      scanf(" %c", &ans);

      ans = tolower(ans);
      
       } while ((ans != 'n') && (ans != 'y'));
  
  return (ans == 'y');
 
}


void flat(char param, int line_size){
  int k;
  for (k = 0; k<line_size; k++){
     printf("%c", param);
    }
  printf("\n");
  return;
}


void headline (char *msg, char param, int line_size) {
  int k;
  int n;

  n = ((line_size -2) - strlen(msg))/2;
  
  printf("%c", param);
  for (k = 0; k<n; k++){
     printf(" ");
    }
  printf("%s", msg);
  for (k = 0; k<n; k++){
     printf(" ");
    }
  printf("%c", param);
  printf("\n");
  
  return;     // exits thefunction
}


