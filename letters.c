#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "inout.h"
#include "operation.h"

#define LINE_SIZE 60
#define CHAR '+'
#define TITLE "CARTAS"


int main(){   
  char op, buffer[256], rubbish[256];
  int a;
  int max_ID = 0;
  
  
  //Setting up the Subscribers table
  tSubscriber Subscribers[200];
  int n_sub = 0;


  //Setting up the Messages table
  tMessage Messages[200];
  int n_msg = 0;

  s_init(Subscribers, &n_sub, &max_ID);
  m_init(Messages, &n_msg);
  



  
  
  
  flat(CHAR, LINE_SIZE);  
  headline (TITLE, CHAR, LINE_SIZE);
  flat(CHAR, LINE_SIZE);
  
  do {
    
    do {
    printf("\nR) Register a new subscriber\nW) Write a message\nL) List the messages for a subscriber\nE) Erase a message\nU) Unregister a subscriber\n\nX) Exit the program\n");
    printf("\nChoose an option: ");
    fgets (buffer, 256, stdin);

    
    //fix for printing confirm() twice
    a = sscanf(buffer, "%c %s", &op, rubbish);
    if (a != 1) {
      op = 'Z'; //To trigger invalid option
    }
      
    printf("\n");

    op = toupper(op);


    switch (op) {
    case 'X':
      break;
    
    case 'R':
      s_register(Subscribers, &n_sub, &max_ID);
      break;
    case 'W':
      m_write(Subscribers, &n_sub, Messages, &n_msg, &max_ID);
      break;
    case 'L':
      m_list(Subscribers, &n_sub, Messages, &n_msg);
      break;
    case 'E':
      m_erase(Subscribers, &n_sub, Messages, &n_msg, &max_ID);
      break;
    case 'U':
      s_unregister(Subscribers, &n_sub, Messages, &n_msg, &max_ID);
      break;
    default:
      printf("You have chosen an invalid option\n");
      break;
    }
  } while (op != 'X' );

    printf("Exit\n\n");

    
    
  } while (confirm ("Are you sure you want to exit? (y/n): ") == 0);

  p_exit(Subscribers, &n_sub, Messages, &n_msg);

  
  return 0;   
}
