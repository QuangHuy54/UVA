#include<iostream>
#include<vector>
#include<utility>
#include<tuple>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
vector<tuple<int,int,int>> edgeList;
int p[200004];
int r[200004];
int get(int u){
    return p[u]==u ? u : get(p[u]);
}
void uni(int u,int v){
    u=get(u);
    v=get(v);
    if(r[u]==r[v]){
        r[u]++;
    }
    if(r[u]>r[v]){
        p[v]=u;
    }
    else{
        p[u]=v;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,u,v,w;
    long long res,sum;
    while(cin>>n>>m&&(n||m)){
        edgeList.clear();
        sum=0;
        for(int i=0;i<n;i++){
            p[i]=i;
            r[i]=0;
        }
        for(int i=0;i<m;i++){
            cin>>u>>v>>w;
            edgeList.push_back(make_tuple(w,u,v));
            sum+=w;
        }
        res=0;
        sort(edgeList.begin(),edgeList.end());
        for(int i=0;i<m;i++){
            u=get<1>(edgeList[i]);
            v=get<2>(edgeList[i]);
            if(get(u)!=get(v)){
                res+=get<0>(edgeList[i]);
                uni(u,v);
            }
        }
        cout<<sum-res<<"\n";
    }
    return 0;
}