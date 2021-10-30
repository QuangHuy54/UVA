#include<iostream>
#include<utility>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
int l,m,n;
int dp[101][101];
int a[101][101];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n){
        if(n==0){
            cout<<"*"<<"\n";
            break;
        }
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++){
            cin>>l>>m;
            a[l][m]++;
        }
        for(int i=1;i<=100;i++){
            for(int j=1;j<=100;j++){
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                dp[i][j]+=a[i][j];
            }
        }
        cout<<dp[100][100]<<"\n";
    }
    return 0;
}
