#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
int n, m;
int p[N], d[N];

int find(int x)
{
    if (p[x] != x)
    {
        d[x] += d[p[x]];
        p[x] = find(p[x]);
    }
    return p[x];
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        p[i] = i;
    int res = 0;
    while (m--)
    {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);
        if (x > n || y > n)
            res++;
        else
        {
            int px = find(x), py = find(y);
            if (t == 1)
            {
                if (px == py && (d[x] - d[y]) % 3)
                    res++;
                else if (px != py)
                {
                    p[px] = py;
                    d[px] = d[y] - d[x];
                }
            }
            else
            {
                if (px == py && (d[x] - d[y] - 1) % 3)
                    res++;
                else if (px != py)
                {
                    p[px] = py;
                    d[px] = d[y] + 1 - d[x];
                }
            }
        }
    }
    printf("%d", res);
    return 0;
}
