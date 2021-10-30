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
#include<iomanip>
using namespace std;
typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
int main(){
    long long mod,step;
    bool first=true;
    while(cin>>step>>mod){
        cout<<setw(10)<<step<<setw(10)<<mod<<"    ";
       if(__gcd(step,mod)==1){
           cout<<"Good Choice"<<"\n";
       }
       else{
           cout<<"Bad Choice"<<"\n";
       }
       cout<<"\n";
    }
    return 0;
}