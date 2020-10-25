#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+10;

int a[N],b[N];
int n,m,x;

int main(){
    
    scanf("%d%d%d",&n,&m,&x);

    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<m;i++) scanf("%d",&b[i]);
    
    int i=0,j=0;
    for(int i=0,j=m-1;i<n;i++){
        while(j>=0&&a[i]+b[j]>x) j--;
        if(a[i]+b[j]==x){
            printf("%d %d",i,j);
            break;
        }
    }
    return 0;
}