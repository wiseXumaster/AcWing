#include <bits/stdc++.h>
using namespace std;

int y = 2000, m = 1, d = 1, w = 6;
int month[13] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int res;

int isYear(int year)
{
    if (year % 4 == 0 || year % 100 != 0 && year % 4 == 0)
        return 1;
    else
        return 0;
}

int main()
{

    while (1)
    {
        if (w == 1 || d == 1)
        {
            res += 2;
        }
        else
        {
            res += 1;
        }
        d++;
        w++;
        if (w == 8)
            w = 1;

        if (m == 2)
        {
            day[m] += isYear(y);
        }

        if (d > day[m])
        {
            d = 1;
            m += 1;
        }

        if (m == 13)
        {
            m = 1;
            y += 1;
        }
        day[2] = 28;
        if (y == 2020 && m == 10 && d == 1)
        {
            res += 2;
            cout << res << endl;
            system("pause");
            return 0;
        }
    }
    return 0;
}
