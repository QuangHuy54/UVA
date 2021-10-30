#include<iostream>
#include<vector>
#include<cmath>
#include<stdio.h>
#include<cstring>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<algorithm>
#include<string>
#include<cstring>
#include<unordered_map>
#include<sstream>
using namespace std;
typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    cout<<"PERFECTION OUTPUT"<<"\n";
    while(cin>>n&&n!=0){
        int S=1;
        for(int i=2;i<n;i++){
            if(n%i==0){
                S=S+i;
            }
        }
        if(n<10){cout<<"    ";}
        else if(n<100){cout<<"   ";}
        else if(n<1000){cout<<"  ";}
        else if(n<10000){cout<<" ";}
        cout<<n<<"  ";
        if(n==1){
            cout<<"DEFICIENT"<<"\n";
        }
        else if(S==n){
            cout<<"PERFECT"<<"\n";
        }
        else if(S<n){
            cout<<"DEFICIENT"<<"\n";
        }
        else{
            cout<<"ABUNDANT"<<"\n";
        }
    }
    cout<<"END OF OUTPUT"<<"\n";
    return 0;
}