#include<iostream>
#include<cstring>
using namespace std;
long long dp[14][14][14];
int t,n,p,r;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dp[1][1][1]=1;
    for(int i=2;i<=13;i++){
        for(int j=1;j<=i;j++){
            for(int k=1;k<=i;k++){
                dp[i][j][k]=dp[i-1][j-1][k]+dp[i-1][j][k-1]+(i-2)*dp[i-1][j][k];
            }
        }
    }
    cin>>t;
    while(t--){
        cin>>n>>p>>r;
        cout<<dp[n][p][r]<<"\n";
    }
    return 0;
}