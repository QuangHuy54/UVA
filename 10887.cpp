#include<iostream>
#include<string>
#include<set>
#include<unordered_set>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_set<string> a;
    unordered_set<string> b;
    string x;
    unordered_set<string> res;
    int m,n,t,c=0;
    cin>>t;
    while(t--){
        cin>>m>>n;
        a.clear();
        b.clear();
        res.clear();
        cin.ignore();
        for(int i=0;i<m;++i){
            getline(cin,x);
            a.insert(x);
        }
        for(int i=0;i<n;++i){
            getline(cin,x);
            b.insert(x);
        }
        for(auto i=a.begin();i!=a.end();i++){
            for(auto j=b.begin();j!=b.end();j++){
                x=(*i)+(*j);
                res.insert(x);
            }
        }
        cout<<"Case "<<++c<<": "<<res.size()<<"\n";
    }
    return 0;
}