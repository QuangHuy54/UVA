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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,x;
    int a[100001];
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cin>>m;
        sort(a,a+n);
        int answ1=0;
        int answ2=0;
        for(int i=0;i<n;i++){
            x=m-a[i];
            x=lower_bound(a+i,a+n,x)-a;
            if(a[x]+a[i]==m){
                answ1=a[i];
                answ2=a[x];
            }
        }
        cout<<"Peter should buy books whose prices are "<<answ1<<" and "<<answ2<<".\n\n";
    }
    return 0;
}