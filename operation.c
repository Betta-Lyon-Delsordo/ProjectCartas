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

int m_write(tSubscriber *Subscribers, int *n_sub, tMessage *Messages, int *n_msg, int *max_ID) {
  int i, sender, receiver;
  int s = 0;
  int r = 0;
  char text[200];
  printf("Write\n\n");
  if (*n_sub == 0) {
    printf("No subscribers yet\n\n");
    return -1;
  }
  sender = get_integer(*max_ID, "Sender's identity");
  for(i=0;i<(*n_sub);i++) {
    if(Subscribers[i].identity == sender){
      s = 1;
      break;
    }
  }
  if(s==0){
    printf("Subscriber not found\n\n");
    return -1;
  }
  receiver = get_integer(*max_ID, "Receiver's identity");
  for(i=0;i<(*n_sub);i++) {
    if(Subscribers[i].identity == receiver){
      r = 1;
      (Subscribers[i].count)++;
      break;
    }
  }
  if(r==0){
    printf("Subscriber not found\n\n");
    return -1;
  }
  get_string(text, 100, "Message text");
  Messages[*n_msg].sender = sender;
  Messages[*n_msg].receiver = receiver;
  strcpy(Messages[*n_msg].text, text);
  printf("Message registered:\n");
  display_extended(Messages[*n_msg]);
  (*n_msg)++;
    
  return 0;
}

int m_list(tSubscriber *Subscribers, int *n_sub, tMessage *Messages, int *n_msg) {
  int ID, i;
  int n = 0;
  char name[20];
  printf("List\n\n");
  if (*n_sub == 0) {
    printf("No subscribers yet\n\n");
    return -1;
  }
  get_string(name, 15, "Receiver's name");
  for(i=0;i<(*n_sub);i++) {
    if(Subscribers[i].name == name) {
      n = 1;
      ID = Subscribers[i].identity;
    }
  }
  if(n == 0) {
    printf("Subscriber not found\n\n");
    return -1;
  }
  printf("Messages for %s:\n", name);
  for(i=0;i<(*n_msg);i++){
    if(Messages[i].receiver == ID){
      display_short(Messages[i]);
    }
  }
  return 0;
}

int m_erase(tSubscriber *Subscribers, int *n_sub, tMessage *Messages, int *n_msg, int *max_ID) {
  int position, receiver, i;
  int r = 0;
  int del_index = 0;
  tMessage copy_Messages[200];
  printf("Erase\n\n");
  if (*n_sub == 0) {
    printf("No subscribers yet\n\n");
    return -1;
  }
  receiver = get_integer(*max_ID, "Receiver's identity");

  for (i=0;i<(*n_sub);i++) {
    if (Subscribers[i].identity == receiver) {
      if (Subscribers[i].count == 0) {
	printf("No messages found");
	return -1;
	  }
      else {
	position = get_integer(Subscribers[i].count, "Message position");
	(Subscribers[i].count)--;
	//Remove message using code below
      }
      r = 1;
      break;
      }
  }

  if (r == 0) {
    printf("Subscriber not found\n\n");
    return -1;
  }

  // From here on will only execute if there is a message to remove
  for(i=0;i<(*n_msg);i++) {
    if (Messages[i].receiver == receiver) {
      if (position == 1) {
	//extract this one
	del_index = i;
	break;
      }
      else {
	position--;
      }
    }
  }

  //To remove message and reorder the table
  //Above the messge to remove
  for(i=0;i<del_index;i++) {
    copy_Messages[i].sender = Messages[i].sender;
    copy_Messages[i].receiver = Messages[i].receiver;
    strcpy(copy_Messages[i].text, Messages[i].text);
  }
  //Below the message to remove
  for(i=(del_index+1);i<(*n_msg);i++) {
    copy_Messages[i-1].sender = Messages[i].sender;
    copy_Messages[i-1].receiver = Messages[i].receiver;
    strcpy(copy_Messages[i-1].text, Messages[i].text);
  }
  (*n_msg)--;
  
  //To replace the original table with the copy
  for(i=0;i<(*n_msg);i++) {
    Messages[i].sender = copy_Messages[i].sender;
    Messages[i].receiver = copy_Messages[i].receiver;
    strcpy(Messages[i].text, copy_Messages[i].text);
  }

  printf("Message erased\n\n");
  
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
