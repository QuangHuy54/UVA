#include<iostream>
using namespace std;
int h[10001],w[10001],n,t,c=0,dp1[10001],dp2[10001];
int res1,res2;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>h[i];
        }
        for(int i=0;i<n;i++){
            cin>>w[i];
            dp1[i]=w[i];
            dp2[i]=w[i];
        }
        res1=0;
        res2=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(h[j]<h[i]){
                    dp1[i]=max(dp1[i],dp1[j]+w[i]);
                }
                else if(h[j]>h[i]){
                    dp2[i]=max(dp2[i],dp2[j]+w[i]);
                }
            }
            res1=max(res1,dp1[i]);
            res2=max(res2,dp2[i]);
        }
        cout<<"Case "<<++c<<". ";
        if(res1>=res2){
            cout<<"Increasing ("<<res1<<"). Decreasing ("<<res2<<")."<<"\n";
        }
        else{
            cout<<"Decreasing ("<<res2<<"). Increasing ("<<res1<<")."<<"\n";
        }
    }
    return 0;
}
