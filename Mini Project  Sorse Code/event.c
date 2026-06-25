#include "event.h"
#include "lcd.h"
#include "lcd_defines.h"

message messageList[TOTAL_MESSAGES] =
{
  {7, 45, "Good Morning! Classes Start Soon", 1},
 {13, 45, "C Programming Session in Classroom number 2", 1},
 {10, 15, "C module theory exam in 4th floor lab1", 1},
 {10, 15, "C module lab exam in 4th floor lab2 and middle lab at 10:30AM", 1},
 {12, 45, "Lunch Break from 1PM-2PM", 1},
 {9, 45, "ARM Workshop on external interrupts in LAB1 at 10AM", 1},
 {9, 45, "ARM kit issue time from 10AM -10:30AM in middle lab", 1},
 {15, 15, "Only 15 mins break time for next ARM session", 1},
 {17, 00, " Revise todays Class programs at home!", 1},
 {17, 45, " End of Day !See You Tomorrow!", 1}
};

int CheckEvents(int hour,int min)
{
    int i;

    for(i=0;i<TOTAL_MESSAGES;i++)
    {
        if(hour==messageList[i].hour && min==messageList[i].min)
        {
            return 1;
        }
    }

    return -1;
}
