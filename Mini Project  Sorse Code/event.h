 #ifndef _EVENT_H
#define _EVENT_H

#define TOTAL_MESSAGES 10

typedef struct
{
    int hour;
    int min;
    char *msg;
    int enabled;
}message;

extern message messageList[TOTAL_MESSAGES];

int CheckEvents(int hour,int min);

#endif

