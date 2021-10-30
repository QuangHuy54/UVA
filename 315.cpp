#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<algorithm>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
vvi graph;
vi low;
vi num;
vi parent;
vi arpoint;
int rootChildren,root,res,numtime;
void articulationPoint(int u){
    low[u]=num[u]=numtime++;
    for(int v:graph[u]){
        if(num[v]==-1){
            parent[v]=u;
            if(u==root){rootChildren++;}
            articulationPoint(v);
            if(low[v]>=num[u]&&u!=root){
                arpoint[u]=true;
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
    int n,u,v;
    string s;
    while(cin>>n&&n){
        cin.ignore();
        graph.clear();
        graph.resize(n+1);
        low.assign(n+1,0);
        num.assign(n+1,-1);
        parent.assign(n+1,0);
        arpoint.assign(n+1,0);
        res=0;
        numtime=0;
        while(getline(cin,s)&&s!="0"){
            stringstream ss(s);
            ss>>u;
            while(ss>>v){
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }
        for(int i=1;i<=n;i++){
            if(num[i]==-1){
                root=i;
                rootChildren=0;
                articulationPoint(i);
                if(rootChildren>1){arpoint[i]=true;}
            }
        }
        for(int i=1;i<=n;i++){
            if(arpoint[i]){
                res++;
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}