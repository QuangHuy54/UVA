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
#include<list>
#include<unordered_map>
using namespace std;
typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
using namespace std;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int a[1001];
    int res[1001];
    while(cin>>n&&n){
        int v=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]!=0){
                res[v++]=a[i];
            }
        }
        for(int i=0;i<v-1;i++){
            cout<<res[i]<<" ";
        }
        cout<<res[v-1]<<"\n";

    }
    return 0;
}