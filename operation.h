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


int s_init(tSubscriber *Subscribers, int *n_sub);
int m_init(tMessage *Messages, int *n_msg);
int s_register();
int m_write();
int m_list();
int m_erase();
int s_unregister();
int p_exit();





#endif
