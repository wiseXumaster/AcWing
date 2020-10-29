#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N=10;
int n,m;
int path[N];
bool st[N];

void dfs(int u){
    if(u==n){
        for(int i=0;i<n;i++){
            printf("%d ",path[i]);
        }
        puts("");
    }

    for(int i=1;i<=n;i++){
        if(!st[i]){
            st[i]=true;
            path[u]=i;
            dfs(u+1);
            st[i]=false;
        }
    }

}

int main(){
    cin>>n;
    dfs(0);
    system("pause");
    return 0;
}
