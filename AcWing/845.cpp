// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 10;
// int n, m;

// int bfs(string start)
// {
//     string end = "12345678x";

//     unordered_map<string, int> d;

//     queue<string> q;
//     d[start] = 0;
//     q.push(start);
//     int dx[4] = {0, 1, 0, -1};
//     int dy[4] = {1, 0, -1, 0};
//     while (!q.empty())
//     {
//         auto t = q.front();
//         ;
//         q.pop();

//         int distance = d[t];

//         if (t == end)
//             return distance;

//         int k = t.find('x');
//         int x = k / 3, y = k % 3;

//         for (int i = 0; i < 4; i++)
//         {
//             int a = x + dx[i], b = y + dy[i];
//             if (a >= 0 && a < 3 && b >= 0 && b < 3)
//             {
//                 swap(t[k], t[a * 3 + b]);
//                 if (!d.count(t))
//                 {
//                     d[t] = distance + 1;
//                     q.push(t);
//                 }
//                 swap(t[k], t[a * 3 + b]);
//             }

//         }
//     }
//     return -1;
// }
//     int main()
//     {
//         string start;
//         for (int i = 0; i < 9; i++)
//         {
//             char c;
//             cin >> c;
//             start += c;
//         }
//         cout << bfs(start) << endl;
//         return 0;
//     }

// <滑稽大佬做法>
// <---------------------------------------------------------------->
// #include<cstring>
// #include<iostream>
// #include<queue>
// using namespace std;

// int fact[9];
// bool vis[362880];

// int permutation_hash(char s[])          //求长度为9的字符串某种排列的哈希值
// {
//     int ans = 0;
//     for(int i = 0; i < 9; i ++)
//     {
//         int d = 0;
//         for(int j = 0; j < i; j ++)
//             if(s[j] > s[i])  d ++;      //求s[i]与其前面的字符组成的逆序对个数
//         ans += d * fact[i];
//     }
//     return ans;
// }

// typedef struct{
//     char s[10];
//     int step;
//     int k;          //'x'在第k位
// }Point;

// int dx[4] = {-1, 0, 1, 0};
// int dy[4] = { 0,-1, 0, 1};
// int bfs(Point p)
// {
//     vis[permutation_hash(p.s)] = true;
//     queue<Point> q;
//     q.push(p);
//     while(!q.empty())
//     {
//         p = q.front();
//         q.pop();
//         /*
//         printf("%d ",p.step);       //print调试法
//         puts(p.s);
//         */
//         if(!strcmp(p.s , "12345678x"))  return p.step;

//         int x = p.k / 3;      //'x'的行数
//         int y = p.k % 3;      //'x'的列数
//         Point next;
//         next.step = p.step + 1;
//         for(int i = 0; i < 4; i ++)
//         {
//             int nx = x + dx[i];
//             int ny = y + dy[i];
//             if(nx >= 0 && nx <= 2 && ny >= 0 && ny <= 2)
//             {
//                 next.k = nx * 3 + ny;           //求出'x'在字符串中的的新位置

//                 strcpy(next.s, p.s);
//                 next.s[9] = 0;
//                 next.s[p.k] = p.s[next.k];      //先用即将和'x'交换的字符覆盖'x'之前的位置
//                 next.s[next.k] = 'x';           //再给'x'的新位置赋值'x'

//                 int hash = permutation_hash(next.s);
//                 if(!vis[hash])
//                 {
//                     vis[hash] = true;
//                     q.push(next);
//                 }
//             }
//         }
//     }
//     return -1;
// }

// int main()
// {
//     fact[0] = 1;
//     for(int i = 1; i < 9; i ++)  fact[i] = fact[i - 1] * i;    //预处理fact[i] = i!

//     char c[2],str[10];
//     Point start;
//     for(int i = 0; i < 9; i ++)
//     {
//         scanf("%s",&c);
//         if(c[0] == 'x')  start.k = i;
//         start.s[i] = c[0];
//     }
//     start.s[9] = 0;
//     start.step = 0;
//     printf("%d",bfs(start));
//     return 0;
// }

// <Yolo_0大佬做法>
// <---------------------------------------------------------------->
#include<bits/stdc++.h>
using namespace std;
//该结点是将二维数组状态压缩成一个字符串
typedef unsigned long long ULL;
const int M=10000000;
const int N=100010,P=131;
ULL h[N];//h[]存放字符串的前缀值
int d[M];
ULL hash_CSM(string a)
{
    h[0]=0;
    for(int i=1;i<=10;i++)
    {
        h[i]=h[i-1]*P+(a[i-1]-'0'+1);

    }
    return h[10]%M;
    //y总讲hash时用ULL实现自动取余，但是此题hash值需要作为数组下标，对该结点进行标记，所以通过多次试验，找到M可实现不冲突，且数组可开辟这些空间
}
int bfs(string state)
{
    queue<string>q;//队列存放节点
    //unordered_map<string,int>d;//存放到达该结点的最短步数(d[string]的值)

    q.push(state); //节点入队
    //cout<<hash(state);
    d[hash_CSM(state)]=0;//到达该结点的步数为零步
    string end="12345678x";
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};//遍历当前状态下该结点上下左右四个方向
    while(q.size())//队列中有节点
    {
        string t=q.front();//临时变量t等于队列中的头结点
        q.pop();//出队
        if(t==end)return d[hash_CSM(t)];//找到答案，返回最短路径
        int distance=d[hash_CSM(t)];//临时变量distance存放到达当前节点的最短路径
        /*为什么需要distance临时变量？
        因为下面改变字符串后，字符串t更新，找不到该状态下的上一个状态*/
        int k=t.find('x');//找到可变换节点的坐标
        int x=k/3,y=k%3;//转换为二维，为了寻找其上下左右四个节点
        for(int i=0;i<4;i++)
        {
            int a=x+dx[i];
            int b=y+dy[i];
            if(a>=0&&a<3&&b>=0&&b<3)
            {


                swap(t[a*3+b],t[k]);
                //在一维中将符合条件的节点和可变换节点进行位置交换
                //cout<<t<<endl;
                //cout<<"字符串的哈希值"<<hash(t)<<endl;
                //cout<<"到该节点的步数"<<d[hash(t)]<<endl;
                if(!d[hash_CSM(t)])//d数组初始化时0，是0代表该结点 未被访问过
                {

                    d[hash_CSM(t)]=distance+1;
                    q.push(t);
                }
                swap(t[a*3+b],t[k]);//字符串恢复到原来，继续遍历下种状态是否可行
            }

        }
    }
    return -1;
}
int main()
{
    string state;

    char c;
    for(int i=0;i<9;i++)
    {
        cin>>c;
        state+=c;
    }

    cout << bfs(state) << endl;

    return 0;
}
