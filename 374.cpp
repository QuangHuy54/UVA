#include<iostream>
using namespace std;
long long powermod(long long a,long long b,long long m){
    a%=m;
    long long res=1;
    while(b>0){
        if(b&1){
            res=res*a%m;
        }
        a=a*a%m;
        b>>=1;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a,b,m;
    while(cin>>a>>b>>m){
        if(a==0){
            cout<<0<<"\n";
        }
        else{
            cout<<powermod(a,b,m)<<"\n";
        }
    }
    return 0;
}