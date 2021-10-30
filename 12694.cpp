#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
bool comp(pii a,pii b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second<b.second;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,x,y,n;
    cin>>t;
    pii a[22];
    while(t--){
        n=0;
        while(cin>>x>>y&&(x||y)){
            a[n].first=x;
            a[n].second=y;
            ++n;
        }
        sort(a,a+n,comp);
        int res=0;
        int temp=-1;
        for(int i=0;i<n;i++){
            if(a[i].first>=temp){
                temp=a[i].second;
                res++;
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}