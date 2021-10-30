#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int c=22000;
int pluss[42];
int minuss[42];
bool dp[42][2][55000];
bool ok[42][55000];
int a[42];
void build(int i,int sum){
    if(i==-1){
        return;
    }
    if(dp[i][1][sum+c]==true&&dp[i][0][sum+c]==true){
        minuss[i]++;
        pluss[i]++;
        build(i-1,sum+a[i]);
        build(i-1,sum-a[i]);
    }
    else if(dp[i][1][sum+c]==true){
        minuss[i]++;
        build(i-1,sum+a[i]);
    }
    else if(dp[i][0][sum+c]==true){
        pluss[i]++;
        build(i-1,sum-a[i]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,f;
    while(cin>>n>>f&&(n||f)){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        memset(pluss,0,sizeof(pluss));
        memset(minuss,0,sizeof(minuss));
        memset(ok,false,sizeof(ok));
        memset(dp,false,sizeof(dp));
        dp[0][0][a[0]+c]=true;
        dp[0][1][-a[0]+c]=true;
        ok[0][a[0]+c]=true;
        ok[0][-a[0]+c]=true;
        int L=-a[0];
        int R=a[0];
        for(int i=1;i<n;i++){
            for(int j=L;j<=R;j++){
                if(ok[i-1][j+c]==true){
                    dp[i][0][j+a[i]+c]=true;
                    dp[i][1][j-a[i]+c]=true;
                    ok[i][j+a[i]+c]=true;
                    ok[i][j-a[i]+c]=true;
                }
            }
            L-=a[i];
            R+=a[i];
        }
        bool solve=true;
        if(dp[n-1][0][f+c]==false&&dp[n-1][1][f+c]==false){
            solve=false;
        }
        if(solve){
            build(n-1,f);
            for(int i=0;i<n;i++){
                if(pluss[i]>0&&minuss[i]>0){
                    cout<<"?";
                }
                else if(pluss[i]>0){
                    cout<<"+";
                }
                else{
                    cout<<"-";
                }
            }
            cout<<"\n";
        }
        else{
            cout<<"*"<<"\n";
        }
    }
    return 0;
}