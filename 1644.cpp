#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
bool prime[1299792];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> primenum;
    memset(prime,true,sizeof(prime));
    for(long long i=2;i<=1299709;i++){
        if(prime[i]==true){
            primenum.push_back(i);
            for(long long j=i*i;j<=1299709;j+=i){
                prime[j]=false;
            }
        }
    }
    int n;
    while(cin>>n&&n){
        if(prime[n]){
            cout<<0<<"\n";
        }
        else{
            int pos=lower_bound(primenum.begin(),primenum.end(),n)-primenum.begin();
            cout<<primenum[pos]-primenum[pos-1]<<"\n";
        }
    }
    return 0;
}