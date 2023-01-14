#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <cstring>
#include <stack>
#include <queue>
#include <climits>
#include <deque>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <unordered_map>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
struct ele{
    int t;
    int s;
    int id;
};
bool compare(ele a,ele b){
    return a.t*b.s<a.s*b.t;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ele> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i].t>>a[i].s;
            a[i].id=i+1;
        }
        sort(a.begin(),a.end(),compare);
        for(int i=0;i<n;i++){
            cout<<a[i].id<<" \n"[i==n-1];
        }
        if(t>0){
            cout<<"\n";
        }
    }
}