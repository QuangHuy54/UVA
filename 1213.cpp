#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> prime;
    bool check[1121];
    memset(check,true,sizeof(check));
    check[0]=check[1]=false;
    for(int i=2;i<=1120;i++){
        for(int j=i*i;j<=1120;j+=i){
            check[j]=false;
        }
    }
    for(int i=2;i<=1120;i++){
        if(check[i]){
            prime.push_back(i);
        }
    }
    int a[1121][15];
    memset(a,0,sizeof(a));
    a[0][0]=1;
    for(int j=0;j<prime.size();j++){
        for(int i=1120;i>=2;i--){
            for(int k=1;k<=14;k++){
                if(i>=prime[j]){
                    a[i][k]+=a[i-prime[j]][k-1];
                }
            }
        }
    }
    int n,k;
    while(cin>>n>>k&&n&&k){
        cout<<a[n][k]<<"\n";
    }
    return 0;
}