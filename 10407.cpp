#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a[1002];
    long long res=0;
    while(cin>>a[0]&&a[0]){
        int n=1;
        while(cin>>a[n]){
            if(a[n]==0){
                break;
            }
            n++;
        }
        res=abs(a[1]-a[0]);
        for(int i=2;i<n;i++){
            res=__gcd(res,abs(a[i]-a[i-1]));
        }
        cout<<res<<"\n";
    }
}