#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
long long lcm(long long a,long long b){
    long long c=a*b;
    long long gcdd=__gcd(a,b);
    return c/gcdd;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a;
    while(cin>>a&&a){
        long long res=0;
        vector<long long> ar;
        for(long long i=1;i<=(long long)sqrt(a);i++){
            if(a%i==0){
                ar.push_back(i);
                if(i*i!=a){
                    ar.push_back(a/i);
                }
            }
        }
        for(int i=0;i<ar.size();i++){
            for(int j=i;j<ar.size();j++){
                if(lcm(ar[i],ar[j])==a){
                    res++;
                }
            }
        }
        cout<<a<<" "<<res<<"\n";
    }
}