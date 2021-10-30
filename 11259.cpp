#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,c[5],d[5],dp[100004],q,v;
    cin>>t;
    while(t--){
        memset(dp,0,sizeof(dp));
        for(int i=0;i<4;i++){
            cin>>c[i];
        }
        cin>>q;
        dp[0]=1;
        for(int i=0;i<4;i++){
            for(int j=c[i];j<=100000;j++){
                dp[j]+=dp[j-c[i]];
            }
        }
        while(q--){
            for(int i=0;i<4;i++){
                cin>>d[i];
            }
            cin>>v;
            ll res=dp[v];
            for(int i=1;i<(1<<4);i++){
                int flag=1;
                ll temp=v;
                for(int j=0;j<4;j++){
                    if(i&(1<<j)){
                        flag=-flag;
                        temp-=(d[j]+1)*c[j];
                    }
                }
                if(temp>=0){res+=flag*dp[temp];}
            }
            cout<<res<<"\n";
        }
    }
    return 0;
}