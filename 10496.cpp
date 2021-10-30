#include<iostream>
#include<utility>
#include<cmath>
#include<climits>
#include<cstring>
using namespace std;
int dp[12][1<<12];
int dis[12][12];
pair<int,int> a[12];
int n,t,temp1,temp2;
int solve(int pos,int mask){
    if(mask==1){
        return dis[pos][0];
    }
    if(dp[pos][mask]!=-1){
        return dp[pos][mask];
    }
    int ans=0x3f3f3f3f;
    for(int i=0;i<=n;i++){
        if(i!=pos&&mask&(1<<i)){
            ans=min(ans,dis[pos][i]+solve(i,mask^(1<<i)));
        }
    }
    return dp[pos][mask]=ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>temp1>>temp2;
        cin>>a[0].first>>a[0].second;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].first>>a[i].second;
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                dis[i][j]=abs(a[i].first-a[j].first)+abs(a[i].second-a[j].second);
            }
        }
        memset(dp,-1,sizeof(dp));
        cout<<"The shortest path has length "<<solve(0,(1<<(n+1))-1)<<"\n";
    }
    return 0;
}