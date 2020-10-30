/*
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int h[N],e[N],ne[N],idx;
void insert(int x){
    int k=(x%N+N)%N;
    e[idx]=x;
    // h[N] 相当于单链表里的多个head指针
    ne[idx]=h[k];
    h[k]=idx++;
}
bool find(int x){
    int k=(x%N+N)%N;
    // 此处i就是idx;
    for(int i=h[k];i!=-1;i=ne[i])
        if(e[i]==x)
            return true;
    return false;
}
int main(){
    int n;
    scanf("%d",&n);
    memset(h,-1,sizeof(h));
    while(n--){
        char op[2];
        int x;
        scanf("%s%d",op,&x);
        if(op[0]=='I') insert(x);
        else{
            if(find(x)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
*/
// 开放寻址法
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int h[N],null=0x3f3f3f3f;
// 如果x在哈希表中，返回x的下标；如果x不在哈希表中，返回x应该插入的位置
int find(int x)
    {
        int k = (x % N + N) % N;
        while (h[k] != null && h[k] != x)
        {
            k ++ ;
            if(k == N) k = 0;
        }
        return k;
    }
int main(){
    int n;
    scanf("%d",&n);
    memset(h,0x3f,sizeof(h));
    while(n--){
        char op[2];
        int x;
        scanf("%s%d",op,&x);
        int k=find(x);
        if(op[0]=='I') h[k]=x;
        else{
            if(h[k]!=null) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}