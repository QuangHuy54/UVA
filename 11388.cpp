#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    long long a,b,c,d;
    while(t--){
        cin>>a>>b;
        c=__gcd(a,b);
        d=(a*b)/c;
        if(c==a&&d==b){
            cout<<a<<" "<<b<<"\n";
        }
        else{
            cout<<-1<<"\n";
        }
    }
    return 0;
}