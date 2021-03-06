#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "inout.h"
#include "operation.h"

int confirm(char *msg) {
  char ans, buffer[256], rubbish[256];

  int ret, a, b = 1;

  do {
    fprintf(stdout, "%s", msg);
 

      fgets (buffer, 256, stdin);
      printf("\n");
  
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
    fprintf(stdout, "\n");
    
    if (strlen(input) == 1) {
      fprintf(stdout, "Null length\n\n");
    }

    else if (strlen(input) > (max+1)) {
      fprintf(stdout, "Excessive length\n\n");
    }

    else {
      sscanf(input, "%s", str);
      incorrect = 0;
    }

  }
  while (incorrect);

  return;

}

int get_integer(int max, char *msg) {
  int n, y;
  char buffer[256], *errors, aux[256];
  int incorrect = 1;
 
  do {
    fprintf(stdout, "%s [1-%d]: ", msg, max);
     errors = fgets(buffer, 256, stdin);
     fprintf(stdout, "\n");
     if (errors != NULL) {
       y = sscanf(buffer, "%d%s", &n, aux);
       if (y == 1) {
        if ((n <= max) && (n >= 1)) {
          incorrect = 0;
	  break;
         }
       }
      }
     fprintf(stdout, "Wrong value\n\n");
  } while (incorrect);
 
  return n;
}

void display_subscriber(tSubscriber aSubscriber) {
  fprintf(stdout,"#%3d:%15s\n", aSubscriber.identity, aSubscriber.name);
  return;
}

void display_extended(tMessage aMessage) {
  fprintf(stdout,"> Sender:  %d\n", aMessage.sender);
  fprintf(stdout,"> Receiver:  %d\n", aMessage.receiver);
  fprintf(stdout,"> Text:  %s\n", aMessage.text);
  return;
}

void display_short(tMessage aMessage) {
  //fix to only print up to 12 chars for text, for loop
  fprintf(stdout,"#%3d:%3d:", aMessage.sender, aMessage.receiver);
  for(int i=0;(i<12) && (aMessage.text[i]!='\0'); i++) {
    fprintf(stdout,"%c",aMessage.text[i]);
    }
  fprintf(stdout,"\n");
  return;
}
