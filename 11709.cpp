#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<cstring>
#include<string>
using namespace std;
map<string,int> vt;
string ar[1002];
int res;
vector<int> graph[1002];
int low[1002],num[1002],timer;
bool visited[1002];
vector<int> s;
void SCC(int u){
    low[u]=num[u]=++timer;
    visited[u]=true;
    s.push_back(u);
    for(int v:graph[u]){
        if(num[v]==-1){
            SCC(v);
        }
        if(visited[v]){
            low[u]=min(low[u],low[v]);
        }
    }
    if(low[u]==num[u]){
        bool first=true;
        while(true){
            int v=s.back();
            s.pop_back();
            visited[v]=false;
            if(u==v){break;}
        }
        res++;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,index;
    string a,b;
    bool blank=false;
    int c=0;
    while(cin>>n>>m&&(n||m)){
        cin.ignore();
        vt.clear();
        s.clear();
        memset(num,-1,sizeof(num));
        memset(low,0,sizeof(low));
        memset(visited,0,sizeof(visited));
        timer=0;
        index=0;
        res=0;
        for(int i=1;i<=n;i++){
            graph[i].clear();
        }
        for(int i=1;i<=n;i++){
            getline(cin,a);
            vt[a]=++index;
            ar[index]=a;
        }
        for(int i=0;i<m;++i){
            getline(cin,a);
            getline(cin,b);
            graph[vt[a]].push_back(vt[b]);
        }
        for(int i=1;i<=n;i++){
            if(num[i]==-1){
                SCC(i);
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}