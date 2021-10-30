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
using namespace std;
typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
vector<ll> store;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long m,res;
    ll limit=pow(2,30)*3;
    for(ll i=0;i<=31;i++){
        ll k=0;
        while(pow(2,i)*pow(3,k)<limit){
            store.push_back(pow(2,i)*pow(3,k));
            k++;
        }
    }
    sort(store.begin(),store.end());
    while(cin>>m&&m){
        auto it=lower_bound(store.begin(),store.end(),m);
        cout<<*it<<"\n";
    }
    return 0;
}