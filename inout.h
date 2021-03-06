#include "operation.h"
#ifndef inout_H
#define inout_H

void flat(char param, int line_size);
void headline (char *msg, char param, int line_size);
int confirm(char *msg);
void get_string(char *str, int max, char *msg);
int get_integer(int max, char *msg);
void display_subscriber(tSubscriber aSubscriber);
void display_extended(tMessage aMessage);
void display_short(tMessage aMessage);
#endif
