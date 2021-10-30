#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
bool comp(pair<int,int> a,pair<int,int> b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second>b.second;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pair<int,int> a[1001];
    int n,t=1;
    while(cin>>n&&n){
        for(int i=0;i<n;i++){
            cin>>a[i].first>>a[i].second;
        }
        sort(a,a+n,comp);
        int temp=0;
        int res=0;
        for(int i=0;i<n;i++){
            temp+=a[i].first;
            res=max(res,temp+a[i].second);
        }
        cout<<"Case "<<t<<": "<<res<<"\n";
        t++;
    }
    return 0;
}