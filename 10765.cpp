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
void articulationPoint(int u){
    low[u]=num[u]=numtime++;
    for(int v:graph[u]){
        if(num[v]==-1){
            parent[v]=u;
            if(u==root){rootChildren++;}
            articulationPoint(v);
            if(low[v]>=num[u]&&u!=root){
                arpoint[u]++;
            }
            low[u]=min(low[u],low[v]);
        }
        else if(v!=parent[u]){
            low[u]=min(low[u],num[v]);
        }
    }
}
bool compare(pii a,pii b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second>b.second;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,u,v,m;
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
        while(cin>>u>>v){
            if(u==-1&&v==-1) break;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            if(num[i]==-1){
                root=i;
                rootChildren=0;
                articulationPoint(i);
                if(rootChildren>1){arpoint[i]=1;}
            }
        }
        for(int i=0;i<n;i++){
            res.push_back(make_pair(i,arpoint[i]+1));
        }
        sort(res.begin(),res.end(),compare);
        for(int i=0;i<m;i++){
            cout<<res[i].first<<" "<<res[i].second<<"\n";
        }     
        cout<<"\n";
    }
    return 0;
}