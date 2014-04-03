#include "fun.h"
#include <windows.h>
#include <cstring>
#include <conio.h>
#include <iostream>
using namespace std;

Oclock inPutTime(Oclock t1)
{
    Oclock t;
    cin >> t1.hour;
    t.hour = t1.hour;
    cin >> t1.minute;
    t.minute = t1.minute;
    cin >> t1.second;
    t.second = t1.second;
    return t;
}
void outPutTime(Oclock t)
{
    if (t.hour < 10 && t.minute < 10 && t.second < 10)
    {
        cout << '0' << t.hour << ":0" << t.minute << ":0" << t.second << endl;
    }
    else
    {
        cout << t.hour << ":" << t.minute << ":" << t.second << endl;
    }
}
Oclock addSecond(Oclock t, int add)
{
    Oclock sec;
    if ( (add > 0) && (add <= 60) )
    {
        sec.hour = t.hour;
        sec.minute = t.minute;
        sec.second = t.second + add;
    }
    else
    {
        if ( (add > 0) && (add > 60) && (t.minute < 60) && (t.second < 60) )
        {
            sec.hour = t.hour + add/3600;
            sec.minute = t.minute + (add%3600)/60;
            sec.second = t.second + (add%3600)%60;
        }
    }
    return sec;
}
Oclock addTimeToTime(Oclock t1, Oclock t2)
{
    Oclock result;
    result.hour = t1.hour + t2.hour + (t1.minute + t2.minute + (t1.second + t2.second)/60)/60;
    result.minute = (t1.minute + t2.minute)%60 + (t1.second + t2.second)/60;
    result.second = (t1.second + t2.second)%60;
    return result;
}
int diffInSecond(Oclock t1, Oclock t2)
{
    int result;
    if ((3600*t1.hour + 60*t1.minute+ t1.second) > (3600*t2.hour + 60*t2.minute + t2.second))
    {
        result = (3600*t1.hour + 60*t1.minute+ t1.second) - (3600*t2.hour + 60*t2.minute + t2.second);
    }
    else
    {
        result = (3600*t2.hour + 60*t2.minute + t2.second) - (3600*t1.hour + 60*t1.minute+ t1.second);
    }
    return result;
}
void inPutTimeArray (Oclock* arr, int n)
{
    cout << "Please, enter you time's array:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter hour:\n";
        cin >> arr[i].hour;
        cout << "Enter minute:\n";
        cin >> arr[i].minute;
        cout << "Enter second:\n";
        cin >> arr[i].second;
    }
}
void outPutTimeArray(Oclock* arr, int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (arr[i].hour < 10 && arr[i].minute < 10 && arr[i].second)
        {
            cout << "0" << arr[i].hour << ":0" << arr[i].minute << ":0" << arr[i].second  << endl;
        }
        else
        {
            cout << arr[i].hour << ":" << arr[i].minute << ":" << arr[i].second << endl;
        }
    }
}
bool order (int upDown)
{
    return !(upDown%2);
}
int cmpHour (Oclock ch1, Oclock ch2)
{
    return ch1.hour - ch2.hour;
}
void MergeTo(Oclock* arr, int startA, int endA, int startB, int endB, int upDown, int (*fun)(Oclock, Oclock))
{
    int fStart = startA;
    int fEnd = endB;
    int i = 0; //индекс результирующего массива
    Oclock* fr = new Oclock[endB-startA+1];//рузельтирующий массив
    while (startA <= endA && startB <= endB)
    {
        if (order(upDown))
        {
            if (((*fun)(arr[startA], arr[startB])) < 0)
            {
                fr[i] = arr[startA];
                ++startA;
            }
            else
            {
                fr[i] = arr[startB];
                ++startB;
            }
        }
        else
        {
            if (((*fun)(arr[startA], arr[startB])) < 0)
            {
                fr[i] = arr[startB];
                ++startB;
            }
            else
            {
                fr[i] = arr[startA];
                ++startA;
            }
        }
        ++i;
    }
    if (startA <= endA)
    {
        for (int j = startA; j <= endA; ++j)
        {
            fr[i] = arr[j];
            ++i;
        }
    }
    else
    {
        for (int j = startB; j <= endB; ++j)
        {
            fr[i] = arr[j];
            ++i;
        }
    }
    i = 0;
    for ( int k = fStart; k <= fEnd; ++k)
    {
        arr[k] = fr [i];
        ++i;
    }
    delete []fr;
}
void Merge(Oclock* arr, int l, int r, int upDown, int (*fun)(Oclock, Oclock))
{
    if (l < r)
    {
        Merge(arr, l, (r+l)/2, upDown, (*fun));
        Merge(arr, (r+l)/2+1, r, upDown, (*fun));
        MergeTo(arr, l, (r+l)/2, (r+l)/2+1, r, upDown, (*fun));
    }
}
void MergeUser(Oclock* arr, int n, int upDown,int (*fun)(Oclock, Oclock))
{
    int l = 0;
    int r = n-1;
    Merge(arr, l, r, upDown, (*fun));
}
