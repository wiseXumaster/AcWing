#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int son[N][26],cnt[N],idx;//下标是0的点，既是根节点，又是空结点
char str[N];
void insert(char str[]){
    int p=0;
    for(int i=0;str[i];i++){
        int u=str[i]-'a';
        if(!son[p][u]) son[p][u]=++idx;//idx只是标记当前节点有没有字母
        p=son[p][u];
    }
    cnt[p]++;
}
int query(char str[]){
    int p=0;
    for(int i=0;str[i];i++){
        int u=str[i]-'a';
        if(!son[p][u]) return 0;
        p=son[p][u];
    }
    return cnt[p];
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        char op[2];
        scanf("%s%s",op,str);
        if(op[0]=='I') insert(str);
        else printf("%d\n",query(str));
    }
    system("pause");
    return 0;
}