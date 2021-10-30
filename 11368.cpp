#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
bool compare(pii a,pii b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second>b.second;
}
vector<int> res;
vector<pii> a;
int t,n,w,h;
bool solve;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        a.clear();
        res.clear();
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>w>>h;
            a.push_back(make_pair(w,h));
        }
        sort(a.begin(),a.end(),compare);
        res.push_back(a[0].first);
        for(int i=1;i<n;i++){
            int pos=upper_bound(res.begin(),res.end(),a[i].first)-res.begin();
            if(pos==res.size()){
                res.push_back(a[i].first);
            }
            else{
                res[pos]=a[i].first;
            }
        }
        cout<<res.size()<<"\n";
    }
    return 0;
}