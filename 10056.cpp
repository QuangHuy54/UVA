#include<iostream>
#include<vector>
#include<cmath>
#include<stdio.h>
#include<cstring>
#include<stack>
#include<iomanip>
#include<queue>
#include<deque>
#include<map>
#include<algorithm>
#include<string>
#include<cstring>
#include<unordered_map>
using namespace std;
typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    int n,i;
    double p;
    cin>>t;
    while(t--){
        cin>>n>>p>>i;
        if(p==0.0){
            cout<<"0.0000"<<"\n";
        }
        else{
        cout<<setprecision(4)<<fixed<<(double)pow(1-p,i-1)*p*1/(1-pow(1-p,n))<<"\n";
        }
    }
}