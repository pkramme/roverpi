#ifndef HEADLESS_H_INCLUDED
#define HEADLESS_H_INCLUDED

#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<unistd.h>
#include<string.h>
#include"headlessinput.h"

int server(void);

#endif
