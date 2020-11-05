#include <bits/stdc++.h>
using namespace std;
const int n = 40;
int a[n][n];
int cnt=1;
int main()
{
    for (int i = 1; i <= n; i++)
    {

        // 奇数行(↗) 行数由i→1,列数由1→i;
        if (i % 2 == 1)
        {
            for (int x = i, y = 1; x >= 1 && y <= i; x--, y++)
                a[x][y] = cnt++;
        }

        // 偶数行(↙) 行数由1→i,列数由i→1;
        if (i % 2 == 0)
        {
            for (int x = 1, y = i; x <= i && y >= 1; x++, y--)
                a[x][y] = cnt++;
        }
    }
    cout << a[20][20] << endl;
    system("pause");
    return 0;
}
