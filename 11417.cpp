#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long res;
    while(cin>>n&&n){
        res=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                res+=__gcd(i,j);
            }
        }
        cout<<res<<"\n";
    }
}