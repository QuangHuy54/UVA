#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double dp[502][502];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    double p;
    while(cin>>n>>p&&n){
        for(int i=1;i<=n;i++){
            dp[i][0]=pow(1-p,i);
            dp[0][i]=1;
        }
        dp[0][0]=1;
        dp[1][1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                if(i==j){
                    dp[i][j]=1;
                }
                else if(j==i-1){
                    dp[i][j]=1-pow(p,i);
                }
                else{
                    if(i-j-2>=j){
                        dp[i][j]=dp[i-1][j]-dp[i-j-2][j]*(1-p)*pow(p,j+1);
                    }
                    else{
                       dp[i][j]=dp[i-1][j]-(1-p)*pow(p,j+1); 
                    }
                }
            }
        }
        double res=0;
        for(int i=1;i<=n;i++){
            res+=(double)(dp[n][i]-dp[n][i-1])*i;
        }
        cout<<setprecision(12)<<fixed<<res<<"\n";
    }
    return 0;
}