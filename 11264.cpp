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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[1009];
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        long long sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int res=1;
        for(int i=0;i<n-1;i++){
            if(sum+a[i]<a[i+1]){
                sum+=a[i];
                res++;
            }
        }
        cout<<res<<"\n";
    }
}