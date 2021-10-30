#include<iostream>
#include<cstring>
using namespace std;
int n,l;
int a[61];
int dp[61][61];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>l&&l){
        memset(dp,0,sizeof(dp));
        cin>>n;
        a[0]=0;
        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        a[n+1]=l;
        for(int i=n-1;i>=0;--i){
            for(int j=i+1;j<=n+1;++j){
                if(j==i+1){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=1e9;
                    for(int k=i+1;k<j;++k){
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+a[j]-a[i]);
                    }
                }
            }
        }
        cout<<"The minimum cutting is "<<dp[0][n+1]<<".\n";
    }
    return 0;
}