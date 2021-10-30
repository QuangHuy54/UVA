#include<iostream>
#include<cmath>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    long long n;
    while(t--){
        cin>>n;
        cout<<(long long)floor((-1.0+sqrt((long double)1+8*n))/2.0)<<"\n";
    }
    return 0;
}