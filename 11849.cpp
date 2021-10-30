#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,x,res;
    set<int> a;
    while(cin>>n>>m&&(n||m)){
        res=0;
        a.clear();
        for(int i=0;i<n;++i){
            cin>>x;
            a.insert(x);
        }
        for(int i=0;i<m;++i){
            cin>>x;
            if(a.find(x)!=a.end()){
                res++;
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}