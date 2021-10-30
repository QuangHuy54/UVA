#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int c=1;
    long long n;
    while(t--){
        cin>>n;
        long long sum=(n*(n-1))/2;
        if(sum%2==0){
            cout<<"Case "<<c++<<": "<<sum/2<<"\n";
        }
        else{
            cout<<"Case "<<c++<<": "<<sum<<"/2"<<"\n";
        }
    }
    return 0;
}