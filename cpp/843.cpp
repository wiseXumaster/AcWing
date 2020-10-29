/*按行枚举
#include <iostream>
using namespace std;
const int N=20;
int n;
char g[N][N];
bool col[N],dg[N],udg[N];
void dfs(int u){
    if(u==n){
        for(int i=0;i<n;i++) puts(g[i]);//printf("%s\n",g[i]);
        puts("");
        return;
    }

    for(int i=0;i<n;i++)
        if(!col[i] && !dg[u+i] && !udg[n-u+i]){
            g[u][i]='Q';
            col[i]=dg[u+i]=udg[n-u+i]=true;
            dfs(u+1);
            col[i]=dg[u+i]=udg[n-u+i]=false;
            g[u][i]='.';
        }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            g[i][j]='.';
    dfs(0);
    return 0;
}
*/
//枚举每个元素
#include <iostream>
using namespace std;
const int N=20;
int n;
char g[N][N];
bool row[N],col[N],dg[N],udg[N];
void dfs(int x,int y,int s){
    if(y==n) y=0,x++;

    if(x==n){
       if(s==n){
            for(int i=0;i<n;i++) puts(g[i]);
            puts("");
       }
          return;
    }

    //不放皇后
    dfs(x,y+1,s);

    //放皇后
    if(!row[x]&&!col[y]&&!dg[x+y]&&!udg[n-x+y]){
        g[x][y]='Q';
        row[x]=col[y]=dg[x+y]=udg[n-x+y]=true;
        dfs(x,y+1,s+1);
        row[x]=col[y]=dg[x+y]=udg[n-x+y]=false;
        g[x][y]='.';
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            g[i][j]='.';
    dfs(0,0,0);
    return 0;
}