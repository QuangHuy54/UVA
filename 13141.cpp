#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,w;
    cin>>a>>b>>w;
    w*=1000;
    int res1=0;
    int res2=1e7;
    int maxl=w/b;
    for(int i=0;i<=maxl;i++){
        if((w-(a-b)*i)%b==0){
            res1=max(res1,(w-(a-b)*i)/b);
            res2=min(res2,(w-(a-b)*i)/b);
        }
    }
    cout<<res2<<" "<<res1;
    return 0;
}