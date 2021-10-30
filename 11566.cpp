#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
int n,x,t,k,sum,price,temp,res;
int dp[23][10001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n>>x>>t>>k){
        if(n==0&&x==0&&t==0&&k==0){
            break;
        }
        memset(dp,-1,sizeof(dp));
        dp[0][0]=0;
        res=0;
        int pricemax=(n+1)*x/(float)1.1-(n+1)*t;
        for(int i=0;i<k;i++){
            cin>>price;
            sum=0;
            for(int j=0;j<n+1;j++){
                cin>>temp;
                sum+=temp;
            }
            for(int z=0;z<2;z++){
                for(int p=1;p<=2*(n+1);p++){
                    for(int l=pricemax;l>=price;l--){
                        if(l-price>=0&&dp[p-1][l-price]>=0){
                            dp[p][l]=max(dp[p][l],dp[p-1][l-price]+sum);
                        }
                        res=max(res,dp[p][l]);
                    }
                }
            }
        }
        cout<<fixed<<setprecision(2)<<(double)res/(n+1)<<"\n";
        
    }
    return 0;
}