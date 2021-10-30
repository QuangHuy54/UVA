#include<iostream>
#include<bitset>
using namespace std;
void print(int i,int n){
    for(int j=n-1;j>=0;j--){
        if(i&(1<<j)){
            cout<<"1";
        }
        else{
            cout<<"0";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,h;
    cin>>t;
    while(t--){
        cin>>n>>h;
        for(int i=0;i<(1<<n);++i){
            if(__builtin_popcount(i)==h){
                print(i,n);
                cout<<"\n";
            }
        }
        if(t){
        cout<<"\n";
        }
    }
    return 0;
}