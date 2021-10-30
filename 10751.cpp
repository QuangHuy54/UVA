#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1){
            cout<<"0.000"<<"\n";
        }
        else{
            double res=4*(n-1)+(n*n-4*(n-1))*sqrt(2);
            cout<<fixed<<setprecision(3);
            cout<<res<<"\n";
        }
        if(t){
            cout<<"\n";
        }
    }
    return 0;
}