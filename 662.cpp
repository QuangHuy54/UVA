#include<iostream>
#include<climits>
#include<cmath>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
int a[201],dp[203][33],mid[203][203],sum[203][203],n,k,mark[203][33],id,v=1;
void printPath(int i,int j){
    if(i<1||j<1){
        return;
    }
    printPath(mark[i][j]-1,j-1);
    cout<<"Depot "<<++id<<" at restaurant "<<mid[mark[i][j]][i]<<" serves restaurant";
    if(mark[i][j]==i){
        cout<<" "<<i<<"\n";
        return;
    }
    else{
        cout<<"s "<<mark[i][j]<<" to "<<i<<"\n";
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n>>k&&(n||k)){
        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        for(int i=1;i<=n;++i){
            for(int j=i;j<=n;++j){
                sum[i][j]=0;
            }
        }
        for(int i=1;i<=n;++i){
            mid[i][i]=i;
            for(int j=i+1;j<=n;++j){
                int midd=(i+j)/2;
                mid[i][j]=midd;
                for(int t=i;t<=j;++t){
                    sum[i][j]+=abs(a[midd]-a[t]);
                }
            }
        }
        for(int i=0;i<=n;++i){
            for(int j=0;j<=k;++j){
                dp[i][j]=INF;
            }
        }
        for(int i=0;i<=k;++i){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=k;++j){
                for(int t=1;t<=i;++t){
                    if(dp[i][j]>=(dp[t-1][j-1]+sum[t][i])){ 
                        dp[i][j]=dp[t-1][j-1]+sum[t][i];
                        mark[i][j]=t;
                    }
                }
            }
        }
        cout<<"Chain "<<v++<<"\n";
        id=0;
        printPath(n,k);
        cout<<"Total distance sum = "<<dp[n][k]<<"\n";
        cout<<"\n";
    }
    return 0;
}