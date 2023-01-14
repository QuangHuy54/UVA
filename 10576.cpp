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
bool dp[10003][102];
int a[10003];
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        memset(dp,0,sizeof(dp));
        dp[0][(a[0]%k+k)%k]=true;
        for(int i=1;i<n;i++){
            a[i]=(a[i]%k+k)%k;
            for(int j=0;j<=k;j++){
                if(dp[i-1][j]==true){
                    dp[i][(j+a[i])%k]=dp[i][((j-a[i])%k+k)%k]=true;
                }
            }
        }
        cout<<((dp[n-1][0]==true) ? "Divisible": "Not divisible")<<"\n";
    }
    return 0;
}