#include <stdio.h>
#include <string.h>
#include "operation.h"
#include "inout.h"

int s_init(tSubscriber *Subscribers, int *n_sub, int *max_ID) {
  FILE *file;
  char buffer[256], name[20];
  int identity, count;
  file = fopen("abonados.txt", "r");
  if (file != NULL) {
    //Read subscribers
    while (fgets(buffer, 256, file) != NULL) {
      
      sscanf(buffer, "%d %d %s", &identity, &count, name);
      if (identity > *max_ID) {
	*max_ID = identity;
      }
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
  char buffer[256], text[200];
  int sender, receiver;
  file = fopen("mensajes.txt", "r");
  if (file != NULL) {
    //Read messages
    while (fgets(buffer, 256, file) != NULL) {
      
      sscanf(buffer, "%d %d %s", &sender, &receiver, text);
      Messages[*n_msg].sender = sender;
      Messages[*n_msg].receiver = receiver;
      strcpy(Messages[*n_msg].text, text);
      (*n_msg) ++;
    }
    fclose(file);
  }
  
  return 0;
}

int s_register(tSubscriber *Subscribers, int *n_sub, int *max_ID) {
  char name[20];
  int identity = ++(*max_ID);
  printf("Register\n\n");
  get_string(name, 15, "Subscriber's name");
  Subscribers[*n_sub].identity = identity;
  Subscribers[*n_sub].count = 0;
  strcpy(Subscribers[*n_sub].name, name);
  printf("Subscriber registered:\n");
  display_subscriber(Subscribers[*n_sub]);
  (*n_sub) ++;
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

int s_unregister() {
    printf("You have chosen unregistering.\n");
    return 0;
}

int p_exit(tSubscriber *Subscribers, int *n_sub, tMessage *Messages, int *n_msg) {
  FILE *s_file;
  FILE *m_file;
  char buffer[256];
  int i;
  //Subscribers
  s_file = fopen("abonados.txt", "w");
  for (i=0; i<(*n_sub); i++) {
    sprintf(buffer, "%d %d %s", Subscribers[i].identity, Subscribers[i].count, Subscribers[i].name);
    fputs(buffer, s_file);
  }
  fclose(s_file);
  
  //Messages
  m_file = fopen("mensajes.txt", "w");
  for (i=0; i<(*n_msg); i++) {
    sprintf(buffer, "%d %d %s", Messages[i].sender, Messages[i].receiver, Messages[i].text);
    fputs(buffer, m_file);
  }
  fclose(m_file);
  
  
  return 0;
}
