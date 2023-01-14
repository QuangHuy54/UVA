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
int a[100002];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c,t=1;
    cin>>c;
    while(c--){
        int n,h,ta,td;
        cin>>n>>h>>ta>>td;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        int r=n-1;
        ll res=0;
        for(int l=0;l<=r;l++){
            if(l==r){
                res+=ta;
            }
            else {
                while(a[l]+a[r]>=h&&l<r){
                    res+=ta;
                    r--;
                }
                if(l<r&&a[l]+a[r]<h&&ta+ta>=td){
                    res+=td;
                    r--;
                }
                else{
                    res+=ta;
                }
            }
        }
        cout<<"Case "<<t++<<": "<<res<<"\n";
    }
    return 0;
}