#include<bits/stdc++.h>
using namespace std;
string intToBit(int n){
    string res="";
    while(n!=0){
        if(n%2==1){
            res+="1";
        }
        else{
            res+="0";
        }
        n/=2;
    }
    reverse(res.begin(),res.end());
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin>>n&&n){
        string s=intToBit(n);
        cout<<"The parity of "<<s<<" is "<<__builtin_popcount(n)<<" (mod 2)."<<"\n";
    }
    return 0;
}