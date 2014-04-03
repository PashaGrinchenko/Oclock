#include "fun.h"
#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
    menu();
    return 0;
}
void menu()
{
    Oclock t1, t2, time1, time2, addsecond1, addsecond2, addtime;
    int add, diff;
    int click;
    int n;
    cout << "Enter the size of time's array\n";
    cin >> n;
    Oclock* arr = 0;
    arr = new Oclock[n];
    while (1)
    {
        cout << "Choose you action:\n";
        cout << "Input and output time for operetion enter '1'\n";
        cout << "Add time to time enter '2'\n";
        cout << "Add second to time enter '3'\n";
        cout << "Difference between times in second enter '4'\n";
        cout << "Input array of times enter '5'\n";
        cout << "Output array of times enter '6'\n";
        cout << "Sort array of times up enter '7'\n";
        cout << "Sort array of times down enter '8'\n";
        cout << "Exit enter '0'\n";
        cin >> click;
        if (click == 1)
        {
            time1 = inPutTime(t1);
            time2 = inPutTime(t1);
            outPutTime(time1);
            outPutTime(time2);
        }
        if (click == 2)
        {
            addtime = addTimeToTime(time1, time2);
            outPutTime(addtime);
        }
        if (click == 3)
        {
            cout << "Input add second\n";
            cin >> add;
            addsecond1 = addSecond(time1, add);
            addsecond2 = addSecond(time2, add);
            outPutTime(addsecond1);
            outPutTime(addsecond2);
        }
        if (click == 4)
        {
            diff = diffInSecond(time1, time2);
            cout << "Difference in Second between two times\n";
            cout << diff << endl;
        }
        if (click == 5)
        {
            inPutTimeArray (arr, n);
        }
        if (click == 6)
        {
            outPutTimeArray(arr, n);
        }
        if (click == 7)
        {
            MergeUser(arr, n , 2, cmpHour);
        }
        if (click == 8)
        {
            MergeUser(arr, n , 1, cmpHour);
        }
        if (click == 0)
        {
            system("cls");
            exit(0);
        }
    }
    delete []arr;
    arr = 0;
}

