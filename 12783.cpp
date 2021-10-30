#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<utility>
#include<algorithm>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;
vvi graph;
vi low;
vi num;
vi parent;
vi arpoint;
vii res;
int rootChildren,root,numtime;
void bridge(int u){
    low[u]=num[u]=numtime++;
    for(int v:graph[u]){
        if(num[v]==-1){
            parent[v]=u;
            bridge(v);
            if(low[v]>num[u]){
                res.push_back(make_pair(min(u,v),max(u,v)));
            }
            low[u]=min(low[u],low[v]);
        }
        else if(v!=parent[u]){
            low[u]=min(low[u],num[v]);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,u,v,m,q;
    string s;
    while(cin>>n>>m&&(n||m)){
        graph.clear();
        graph.resize(n+1);
        low.assign(n+1,0);
        num.assign(n+1,-1);
        parent.assign(n+1,0);
        arpoint.assign(n+1,0);
        res.clear();
        numtime=0;
        while(m--){
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            if(num[i]==-1){
                bridge(i);
            }
        }
        sort(res.begin(),res.end());
        cout<<res.size();
        for(int i=0;i<res.size();i++){
            cout<<" "<<res[i].first<<" "<<res[i].second;
        }
        cout<<"\n";
    }
    return 0;
}