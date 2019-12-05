#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "inout.h"

int confirm() {
  char ans, buffer[256], rubbish[256];

  int ret, a, b = 1;

  do {
      printf("Are you sure you want to exit? (y/n): ");

      fgets (buffer, 256, stdin);
  
      a = sscanf(buffer, "%c %s", &ans, rubbish);

      ans = tolower(ans);

      if (a!=1)
	b = 0;


      else{
	switch (ans){

	case 'y':
	  ret=1;
	  b = 1;
	  break;
	case 'n':
	  ret=0;
	  b=1;
	  break;
	default:
	  b=0;
	  break;
      }}
       } while (b==0);

  return ret;
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
