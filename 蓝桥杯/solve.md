# 蓝桥杯_2020/10/17(B组C++填空题题解)
---
## A.门牌制作
```
#include <bits/stdc++.h>
using namespace std;
int res,x,t;
int main(){
    for(int i=0;i<=2020;i++){
        x=i;
        while(x){
            t=x%10;
            x/=10;
            if(t==2) res++;
        }
    }
    cout<<res<<endl;
    system("pause");
    return 0;
}
```
思路：对0-2020每个数进行枚举,暴力算出2的个数
答案：624
![](https://img2020.cnblogs.com/blog/1627656/202011/1627656-20201101025625888-1250393220.png)

---
## B.既约分数

```
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
```
思路：对分子分母进行判断,数据不大直接暴力
答案：2481215
![](https://img2020.cnblogs.com/blog/1627656/202011/1627656-20201101025714208-1670846845.png)

---

## C.蛇形填数
```
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
```
思路：找规律
答案：761
![](https://img2020.cnblogs.com/blog/1627656/202011/1627656-20201101025744374-2047477638.png)

---
手算
![](https://img2020.cnblogs.com/blog/1627656/202011/1627656-20201101023752252-1410500738.png)

---
## D.跑步锻炼
```
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
```
思路：模拟日历
答案：8879
![](https://img2020.cnblogs.com/blog/1627656/202011/1627656-20201101025759480-2094116216.png)

---
## E.七段码
```
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
                // 如果联通并且两个都被使用,合并集合
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
```
思路：dfs枚举出每种情况,用并查集将相连的电子管进行统一
答案：80
![](https://img2020.cnblogs.com/blog/1627656/202011/1627656-20201101025814794-1450405270.png)

[原文链接](https://blog.csdn.net/qq_45530271/article/details/109189978?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-4.channel_param&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-4.channel_param)

---

## F.成绩统计
```
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
```
思路：模拟题目。
[四舍五入](https://blog.csdn.net/m0_46070659/article/details/105558575?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.channel_param&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.channel_param)

---

## G: 回文日期
```
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N=1e5+10;
int y,m,d;
int month[13] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int flag1,flag2;
// 普通回文
bool check_1(int yy,int mm,int dd){
    int x1,x2,x3,x4,x5,x6,x7,x8;
    x1=yy/1000;
    x2=yy/100%10;
    x3=yy/10%10;
    x4=yy%10;
    x5=mm/10;
    x6=mm%10;
    x7=dd/10;
    x8=dd%10;
    if(x1==x8&&x2==x7&&x3==x6&&x4==x5) return true;
    return false;
}

// ABABBABA
bool check_2(int yy,int mm,int dd){
     int x1,x2,x3,x4,x5,x6,x7,x8;
    x1=yy/1000;
    x2=yy/100%10;
    x3=yy/10%10;
    x4=yy%10;
    x5=mm/10;
    x6=mm%10;
    x7=dd/10;
    x8=dd%10;
    if(x1==x3&&x1==x6&&x1==x8&&x2==x4&&x2==x5&&x2==x7) return true;
    return false;
}

int isYear(int year){
    if(year%400==0||year%4==0&&year%100!=0) return 1;
    return 0;
}

void up(){
     day[2]+=isYear(y);
        d++;
        if(d>day[m]){
            d=1;
            m+=1;
        }

        if(m==13){
            m=1;
            y+=1;
        }
        day[2]=28;
}
int main(){
    int t;
    cin>>t;
    y=t/10000;
    m=t%10000/100;
    d=t%100;

    // 题目说了下一个回文日期,所以直接加一天
    while(1){
        up();
        if(check_1(y,m,d)&&!flag1){
            flag1=1;
            cout<<y;
            if(m<10) cout<<0<<m;
            else cout<<m;
            if(d<10) cout<<0<<d;
            else cout<<d;
            up();
            puts("");
        }

        if(check_2(y,m,d)&&!flag2&&flag1){
            flag2=1;
            cout<<y;
            if(m<10) cout<<0<<m;
            else cout<<m;
            if(d<10) cout<<0<<d;
            else cout<<d;
            up();
        }

        if(flag1&&flag2){
            system("pause");
            return 0;
        }
    }
    system("pause");
    return 0;
}
```
思路：模拟日期

---
## H.子串分值和
```
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
LL dp[N];
LL pos[27];

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    for (int i = 0; i < 27; i++)
        pos[i] = -1;

    dp[0] = 1;
    pos[s[0] - 'a'] = 0;

    for (int i = 1; i < n; i++)
    {
        dp[i] = dp[i - 1] + i - pos[s[i] - 'a'];
        pos[s[i] - 'a'] = i;
    }
    LL res = 0;
    for (int i = 0; i < n; i++)
        res += dp[i];
    cout << res << endl;
    system("pause");
    return 0;
}


```
思路：看了网上大佬的题解,由于自己在dp没有下功夫,对着样例比划了些许时间,终于理解了,看原文更好理解
[原文链接](https://blog.csdn.net/qq_43461168/article/details/109146495)

---
## I.平面切分
```
```
思路：


---
