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
typedef pair<ll,ll> pll;
pll reduce(pll c){
    ll k=__gcd(c.first,c.second);
    return {c.first/k,c.second/k};
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    while (cin>>n>>m&&(n||m))
    {
        vector<vector<ll>> a(n,vector<ll>(m));
        vector<ll> prefsum(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
                prefsum[j]+=a[i][j];
            }
        }
        for(int i=0;i<n;i++){
            pll res=reduce({a[i][m-1],prefsum[m-1]});
            cout<<res.first<<" / "<<res.second<<"\n";
        }
    }
    return 0;
}