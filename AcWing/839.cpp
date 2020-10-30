#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 1e6 + 10;
int n, m, num;

int h[N], hp[N], ph[N];

void heap_swap(int a, int b)
{
    swap(hp[a], hp[b]);
    swap(ph[hp[a]], ph[hp[b]]);
    swap(h[a], h[b]);
}

void up(int u)
{
    while (u / 2 && h[u / 2] > h[u])
        heap_swap(u/2, u), u /= 2;
}

void down(int u)
{

    int t = u;
    if (u * 2 <= num && h[u * 2] < h[t])
        t = u * 2;
    if (u * 2 + 1 <= num && h[u * 2 + 1] < h[t])
        t = u * 2 + 1;
    if (u != t)
    {
        heap_swap(u, t);
        down(t);
    }
}

int main()
{
    cin >> n;

    while (n--)
    {
        char op[3];
        int k, x;
        scanf("%s", op);
        if (!strcmp(op, "I"))
        {
            scanf("%d", &x);
            num++;
            m++;
            //堆中的位置
            ph[m] = num;
            //位置上的点是第几个插入的
            hp[num] = m;
            //赋值
            h[num] = x;
            //up操作
            up(num);
        }
        else if (!strcmp(op, "PM"))
        {
            printf("%d\n", h[1]);
        }
        else if (!strcmp(op, "DM"))
        {
            heap_swap(1, num);
            num--;
            down(1);
        }
        else if (!strcmp(op, "D"))
        {
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, num);
            num--;
            down(k), up(k);
        }
        else if (!strcmp(op, "C"))
        {
            scanf("%d%d", &k, &x);
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
    }
    return 0;
}
