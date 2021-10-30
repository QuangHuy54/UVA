#include<iostream>
#include<cmath>
#include<climits>
#include<iomanip>
#include<cstring>
using namespace std;
struct Point{
    int x;
    int y;
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Point a[10];
    double dp[10][1<<9];
    double dis[10][10];
    int next[10][1<<9];
    int n,t=1;
    while(cin>>n&&n){
        for(int i=0;i<n;++i){
            cin>>a[i].x>>a[i].y;
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                dis[i][j]=hypot(a[i].x-a[j].x,a[i].y-a[j].y);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<=(1<<n)-1;j++){
                dp[i][j]=(double)INT_MAX;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<=(1<<n)-1;j++){
                next[i][j]=0;
            }
        }
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
        for(int mask=0;mask<=(1<<n)-1;mask++){
            for(int i=0;i<n;i++){
                if((mask&(1<<i))==0){
                    for(int j=0;j<n;j++){
                        if((mask&(1<<j))&&i!=j){
                            if(dp[i][mask]>dp[j][mask^(1<<j)]+dis[i][j]+16.0){
                                dp[i][mask]=dp[j][mask^(1<<j)]+dis[i][j]+16.0;
                                next[i][mask]=j;
                            }
                        }
                    }
                }
            }
        }
        int min=0;
        for(int i=1;i<n;i++){
            if(dp[min][((1<<n)-1)^(1<<min)]>dp[i][((1<<n)-1)^(1<<i)]){
                min=i;
            }
        }
        cout<<"**********************************************************"<<"\n";
        cout<<"Network #"<<t++<<"\n";
        int mask=((1<<n)-1)^(1<<min);
        int k=min;
        while(mask!=0){
            int nxt=next[min][mask];
            cout<<"Cable requirement to connect ("<<a[min].x<<","<<a[min].y<<") to ("<<a[nxt].x<<","<<a[nxt].y<<") is "<<fixed<<setprecision(2)<<dis[min][nxt]+16.0<<" feet."<<"\n";
            mask^=(1<<nxt);
            min=nxt;
        }
        cout<<"Number of feet of cable required is "<<fixed<<setprecision(2)<<dp[k][((1<<n)-1)^(1<<k)]<<"."<<"\n";
    }
    return 0;
}