#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int time[104];
    int sphere[105];
    int dp[105][105];
    while(cin>>n&&n){
        for(int i=0;i<n;i++){
            cin>>time[i]>>sphere[i];
        }
        for(int i=0;i<=n;i++){
            dp[n][i]=0;
        }
        for(int i=n-1;i>=0;i--){
            for(int k=0;k<=n;k++){
                dp[i][k]=0x3f3f3f3f;
                dp[i][k]=min(dp[i][k],dp[i+1][min(n,k+sphere[i])]+time[i]);
                if(k>0){
                    dp[i][k]=min(dp[i][k],dp[i+1][min(n,k+sphere[i]-1)]+time[i]/2);
                }
            }
        }
        cout<<dp[0][0]<<"\n";
    }
    return 0;
}