#include<bits/stdc++.h>
using namespace std;
long long res[7489];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[5]={1,5,10,25,50};
    res[0]=1;
    for(int j=0;j<5;j++){
        for(int i=1;i<=7489;i++){
            if(i-a[j]>=0){
                res[i]+=res[i-a[j]];
            }
        }
    }
    int n;
    while(cin>>n){
        cout<<res[n]<<"\n";
    }
}
