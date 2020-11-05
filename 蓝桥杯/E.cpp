#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int p[N], e[N][N], use[N], res;

void init()
{
    // a b c d e f g
    // 1 2 3 4 5 6 7
    e[1][2] = e[1][6] = 1;
    e[4][3] = e[4][5] = 1;
    e[2][1] = e[2][3] = e[2][7] = 1;
    e[3][2] = e[3][4] = e[3][7] = 1;
    e[5][4] = e[5][6] = e[5][7] = 1;
    e[6][1] = e[6][5] = e[6][7] = 1;
}

// 并查集
int find(int x)
{
    // 路径压缩
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void dfs(int u)
{
    if (u > 7)
    {
        // 初始化祖宗节点
        for (int i = 1; i <= 7; i++)
            p[i] = i;

        // 查看使用状态和联通情况
        for (int i = 1; i <= 7; i++)
            for (int j = 1; j <= 7; j++)
            {
                // 如果联通并且两个都被使用，合并集合
                if (e[i][j] && use[i] && use[j])
                {
                    int px = find(i), py = find(j);
                    if (px != py)
                    {
                        p[px] = py;
                    }
                }
            }

        // 记录集合数
        int k = 0;

        // 计算集合数;
        for (int i = 1; i <= 7; i++)
            if (use[i] && p[i] == i)
                k++;

        // 合法集合数根据题意只能为一
        if (k == 1)
            res++;
        return;
    }
    // 使用
    use[u] = 1;
    dfs(u + 1);
    // 不使用
    use[u] = 0;
    dfs(u + 1);
}

int main()
{
    init();
    dfs(1);
    cout << res << endl;
    system("pause");
    return 0;
}