#include <bits/stdc++.h>
using namespace std;
int res;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{

    for (int i = 1; i <= 2020; i++)
    {
        for (int j = 1; j <= 2020; j++)
        {
            if (gcd(i, j) == 1)
                res++;
        }
    }
    cout << res << endl;
    system("pause");
    return 0;
}
