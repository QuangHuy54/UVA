#include<bits/stdc++.h>
using namespace std;
struct Object{
    int price;
    int weight;
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,g,mw;
    Object a[1005];
    int ans[1001][31];
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i].price>>a[i].weight;
        }
        cin>>g;
        for(int i=1;i<=30;i++){
            if(a[0].weight>i){
                ans[0][i]=0;
            }
            else{
                ans[0][i]=a[0].price;
            }
        }
        for(int i=0;i<n;i++){
            ans[i][0]=0;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=30;j++){
                if(a[i].weight>j){
                    ans[i][j]=ans[i-1][j];
                }
                else{
                    ans[i][j]=max(ans[i-1][j],ans[i-1][j-a[i].weight]+a[i].price);
                }
            }
        }
        int answ=0;
        while(g--){
            cin>>mw;
            answ+=ans[n-1][mw];
        }
        cout<<answ<<"\n";
    }
    return 0;
}