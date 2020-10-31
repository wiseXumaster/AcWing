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
