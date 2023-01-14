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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;
    while(cin>>m>>n&&(m||n)){
        vector<int> a(m);
        vector<pii> b(n);
        for(int& x:a){
            cin>>x;
        }
        for(int i=0;i<n;i++){
            cin>>b[i].first;
            b[i].second=i+1;
        }
        sort(b.begin(),b.end(),greater<pii>());
        vector<vector<int>> res(m);
        bool ok=true;
        for(int i=0;i<m;i++){
            int k=a[i];
            int pos=0;
            for(int j=0;j<n;j++){
                if(res[i].size()==k){
                    break;
                }
                if(b[j].first>0){
                    b[j].first--;
                    res[i].push_back(b[j].second);
                }
            }
            if(res[i].size()<k){
                cout<<0<<"\n";
                ok=false;
                break;
            }
        }
        if(ok){
            cout<<1<<"\n";
            for(int i=0;i<m;i++){
                for(int j=0;j<a[i];j++){
                    cout<<res[i][j]<<" \n"[j==a[i]-1];
                }
            }
        }
    }
}