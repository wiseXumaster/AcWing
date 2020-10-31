#include <bits/stdc++.h>
using namespace std;

int y = 2020, m = 1, d = 1, w = 6;
int month[13] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int res=1;

int isYear(int year)
{
    if (year % 4 == 0 || year % 100 != 0 && year % 4 == 0)
        return 1;
    else
        return 0;
}

int main()
{

    while(y!=2020&&m!=10&&d!=1){
        if(w==1||d==1){
            res+=2;
        }else{
            res+=1;
        }

        d++;
        if(d>day[m]){
            d=1;
            m+=1;
        }

        if(m==13){
            m=1;
            y+=1;
        }
    }
    cout<<res<<endl;
    system("pause");
    return 0;
}
