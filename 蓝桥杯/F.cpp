#include <bits/stdc++.h>
using namespace std;

//  及格人数 优秀人数
int res1, res2;
int main()
{
    int n;
    cin >> n;
    int t = n;
    while (n--)
    {
        double x;
        cin >> x;
        if (x >= 60)
            res1++;
        if (x >= 85)
            res2++;
    }
    res1 = round((double)res1 * 100 / t);
    res2 = round((double)res2 * 100 / t);
    printf("%d%%\n", res1);
    printf("%d%%", res2);
    system("pause");
    return 0;
}
