#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N=1e5+10;
int n,m;
int h[N],e[N],ne[N],idx;
int d[N],q[N];

void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

int bfs(){
    int hh=0,tt=0;
    q[0]=1;

    memset(d,-1,sizeof h);

    d[1]=0;

    while(hh<=tt){
        int t=q[hh++];

        for(int i=h[t];i!= -1; i = ne[i]){
            int j=e[i];
            if(d[j]==-1){
                d[j]=d[t]+1;
                q[++tt]=j;
            }
        }
    }
    return d[n];
}

int main(){
    cin>>n>>m;

    memset(h,-1,sizeof h);

    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
    }
    cout<<bfs()<<endl;
    return 0;
}
