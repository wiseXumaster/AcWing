#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e5+10,M=1e6+10;
//模板串 模式串
char p[N],s[M];
int ne[N];
int main(){
    cin>>n>> p+1 >>m>> s+1;
    //求next的过程
    for(int i=2,j=0;i<=n;i++){
        while(j&&p[i]!=p[j+1]) j=ne[j];
        if(p[i]==p[j+1]) j++;
        ne[i]=j;
    }

    //kmp匹配过程
    for(int i=1,j=0;i<=m;i++){
        while(j&&s[i]!=p[j+1]) j=ne[j];
        if(s[i]==p[j+1]) j++;
        if(j==n){
            printf("%d ",i-n);
            j=ne[j];
        }
    }
    system("pause");
    return 0;
}
