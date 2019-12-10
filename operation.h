#ifndef operation_H
#define operation_H

//Defining the Subscriber type
  typedef struct aSubscriber {
    int identity;
    int count;
    char name[20];
  } tSubscriber;

//Defining the Message type
  typedef struct aMessage {
    int sender;
    int receiver;
    char text[200];
  } tMessage;


int s_init(tSubscriber *Subscribers, int *n_sub, int *max_ID);
int m_init(tMessage *Messages, int *n_msg);
int s_register(tSubscriber *Subscribers, int *n_sub, int *max_ID);
int m_write(tSubscriber *Subscribers, int *n_sub, tMessage *Messages, int *n_msg, int *max_ID);
int m_list(tSubscriber *Subscribers, int *n_sub, tMessage *Messages, int *n_msg);
int m_erase();
int s_unregister();
int p_exit(tSubscriber *Subscribers, int *n_sub, tMessage *Messages, int *n_msg);





#endif
