#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "inout.h"
#include "operation.h"

#define LINE_SIZE 60
#define CHAR '#'
#define TITLE "PROGRAMA"


int main(){   //main function
  char op;
  
  flat(CHAR, LINE_SIZE);  
  headline (TITLE, CHAR, LINE_SIZE);
  flat(CHAR, LINE_SIZE);
  
  do {
    
    do {
    printf("\nEnter your selection:\nR) Register a new subscriber\nW) Write a message\nL) List the messages for a subscriber\nE) Erase a message\nX) Leave the program\n");
    printf("\nChoose an option: ");
    scanf(" %c", &op);
    printf("\n");

    op = toupper(op);


    switch (op) {
    case 'X':
      break;
    
    case 'R':
      s_register();
      break;
    case 'W':
      m_write();
      break;
    case 'L':
      m_list();
      break;
    case 'E':
      m_erase();
      break;
    default:
      printf("You have chosen an invalid option.\n");
      break;
    }
  } while (op != 'X' );

    
    
  } while (confirm () == 0);

  
  return 0;    //exits main() with 0 value
}
