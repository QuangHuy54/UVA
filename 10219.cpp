#include<iostream>
#include<cmath>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,k;
    long double res;
    while(cin>>n>>k){
        res=0;
        for(long long i=n-k+1;i<=n;i++){
            res+=log10((double)i);
        }
        for(long long i=1;i<=k;i++){
            res-=log10((double)i);
        }
        cout<<(long long)res+1<<"\n";
    }
}