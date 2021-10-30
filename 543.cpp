#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool ok[1000001];
    memset(ok,true,sizeof(ok));
    for(int i=2;i*i<=1000000;i++){
        if(ok[i]){
            for(int j=i+i;j<=1000000;j+=i){
                ok[j]=false;
            }
        }
    }
    int n,a,b;
    while(cin>>n&&n){
        bool solve=false;
        for(int i=3;i<=(n/2);i+=2){
            if(ok[i]&&ok[n-i]){
                a=i; 
                b=n-i;
                solve=true;
                break;
            }
        }
        if(solve){
            cout<<n<<" = "<<a<<" + "<<b<<"\n";
        }
        else{
            cout<<"Goldbach's conjecture is wrong."<<"\n";
        }
    }
    return 0;
}