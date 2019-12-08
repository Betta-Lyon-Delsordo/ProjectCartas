#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "inout.h"

int confirm(char *msg) {
  char ans, buffer[256], rubbish[256];

  int ret, a, b = 1;

  do {
    fprintf(stdout, "%s", msg);

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
  
  return;    
}

void get_string(char *str, int max, char *msg) {
  int incorrect = 1;
  char input[256];

  do {
    fprintf(stdout, "%s (1-%d char): ", msg, max); 
    fgets(input, 255, stdin);
    
    if (strlen(input) == 1) {
      fprintf(stdout, "Null length\n");
    }

    else if (strlen(input) > max) {
      fprintf(stdout, "Excessive length\n");
    }

    else {
      strcpy(str, input);
      incorrect = 0;
    }

  }
  while (incorrect);

  return;

}

int get_integer(int max, char *msg) {
  int n;
  char buffer[256], *ptr, *errors;
  int incorrect = 1;
 
  do {
    fprintf(stdout, "%s [1-%d]: ", msg, max);
     errors = fgets(buffer, 256, stdin);
     if (errors != NULL) {
       //convert string to integer
       n = strtol(buffer, &ptr, 10); //returns 0 if non-integer input
        if ((n <= max) && (n >= 1)) {
          incorrect = 0;
	  break;
         }
        }
     fprintf(stdout, "Wrong value\n");
  } while (incorrect);
 
  return n;
  
}
