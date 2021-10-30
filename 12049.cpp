#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    multiset<int> a;
    int n,m,t,x,res;
    cin>>t;
    while(t--){
        res=0;
        cin>>n>>m;
        a.clear();
        for(int i=0;i<n;++i){
            cin>>x;
            a.insert(x);
        }
        for(int i=0;i<m;++i){
            cin>>x;
            auto pos=a.find(x);
            if(pos!=a.end()){
                a.erase(pos);
            }
            else{
                res++;
            }
        }
        if(!a.empty()){
            res+=a.size();
        }
        cout<<res<<"\n";
    }
    return 0;
}