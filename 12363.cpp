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
int p[100005];
int r[100005];
vvi graph;
vi low;
vi num;
vi parent;
vi arpoint;
vii res;
int rootChildren,root,numtime;
int get(int a){
    return (p[a]=p[a]==a ? a : get(p[a]));
}
void uni(int a,int b){
    a=get(a);
    b=get(b);
    if(a!=b){
        if(r[a]==r[b]){
            r[a]++;
        }
        if(r[a]>r[b]){
            p[b]=a;
        }
        else{
            p[a]=b;
        }
    }
}
void bridge(int u){
    low[u]=num[u]=numtime++;
    for(int v:graph[u]){
        if(num[v]==-1){
            parent[v]=u;
            bridge(v);
            if(low[v]>num[u]){
                uni(v,u);
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
    while(cin>>n>>m>>q&&(n||m||q)){
        graph.clear();
        graph.resize(n+1);
        low.assign(n+1,0);
        num.assign(n+1,-1);
        parent.assign(n+1,0);
        arpoint.assign(n+1,0);
        for(int i=1;i<=n;i++){
            p[i]=i;
            r[i]=0;
        }
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
        while(q--){
            cin>>u>>v;
            if(get(u)!=get(v)){
                cout<<"N"<<"\n";
            }
            else{
                cout<<"Y"<<"\n";
            }
        }
        cout<<"-"<<"\n";
    }
    return 0;
}