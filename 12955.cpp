#include<iostream>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int fac[8]={1,2,6,24,120,720,5040,40320};
    int dp[100005],n;
    memset(dp,INF,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=100000;i++){
        for(int j=0;j<8;j++){
            if(i>=fac[j]){
                dp[i]=min(dp[i],dp[i-fac[j]]+1);
            }
        }
    }
    while(cin>>n){
        cout<<dp[n]<<"\n";
    }
    return 0;
}