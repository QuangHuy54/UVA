#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        int a[101];
        int len=0;
        int n;
        while((cin>>n)&&(n!=-999999)){
            a[len++]=n;
        }
        int sum=a[0];
        int res=-999999;
        for(int i=1;i<len;i++){
            sum=max(a[i],sum*a[i]);
            res=max(res,sum);
        }
        cout<<res<<"\n";
    }
    return 0;
}