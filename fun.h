#ifndef FUN_H
#define FUN_H

struct Oclock
{
    int hour;
    int minute;
    int second;
};

Oclock inPutTime(Oclock time);
void outPutTime(Oclock time);
void inPutTimeArray(Oclock* arr, int sizeOfArray);
void outPutTimeArray(Oclock* arr, int sizeOfArray);
Oclock addSecond(Oclock time, int addSecond);
Oclock addTimeToTime(Oclock time1, Oclock time2);
int diffInSecond(Oclock time1, Oclock time2);
void MergeUser(Oclock* arr, int n, int upDown,int (*fun)(Oclock, Oclock));
int cmpHour (Oclock characteristic1, Oclock characteristic2);
void menu();

#endif // FUN_H
