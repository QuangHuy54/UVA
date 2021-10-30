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
using namespace std;
    long long a[101][101];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0;i<101;i++){
            a[i][0] = a[i][i] = 1;
		    int k = i >> 1;
		    for (int j = 1; j < k + 1; j++)
			    a[i][j] = a[i][i - j] = (a[i - 1][j] + a[i - 1][j - 1]);

    }
    int n,m;
    while(cin>>n>>m&&(n||m)){
        cout<<n<<" things taken "<<m<<" at a time is "<<a[n][m]<<" exactly."<<"\n";
    }
    
    return 0;
}