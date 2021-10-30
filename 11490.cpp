#include<iostream>
#include<cmath>
using namespace std;
long long n,res;
const long long modulo=100000007;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n&&n){
        bool flag=false;
        for(long long i=1;(n-i*i*6)>0;i++){
            if((n-i*i*6)%(7*i)==0){
                long long k=((n-i*i*6)/(7*i))%modulo;
                cout<<"Possible Missing Soldiers = "<<(k*k*2)%modulo<<"\n";
                flag=true;
            } 
        }
        if(!flag){
            cout<<"No Solution Possible"<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}