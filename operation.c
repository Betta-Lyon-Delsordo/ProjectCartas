#include <stdio.h>
#include <string.h>
#include "operation.h"

int s_init(tSubscriber *Subscribers, int *n_sub) {
  FILE *file;
  char buffer[256], name[20];
  int identity, count;
  file = fopen("abonados.txt", "r");
  if (file != NULL) {
    //Read subscribers
    while (fgets(buffer, 256, file) != NULL) {
      
      sscanf(buffer, "%d %d %s", &identity, &count, name);
      Subscribers[*n_sub].identity = identity;
      Subscribers[*n_sub].count = count;
      strcpy(Subscribers[*n_sub].name, name);
      (*n_sub) ++;
    }
    fclose(file);
  }
  
  return 0;

}

int m_init(tMessage *Messages, int *n_msg) {
  FILE *file;
  file = fopen("mensajes.txt", "r");
  if (file != NULL) {
    //Read messages
    fclose(file);
  }
  return 0;
}

int s_register() {
  printf("You have chosen registering.\n");
  return 0;
}

int m_write() {
  printf("You have chosen writing.\n");
  return 0;
}

int m_list() {
  printf("You have chosen listing.\n");
  return 0;
}

int m_erase() {
  printf("You have chosen erasing.\n");
  return 0;
}

