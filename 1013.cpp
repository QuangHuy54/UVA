#include<iostream>
#include<vector>
#include<utility>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<cstring>
using namespace std;
typedef pair<int,int> pii;
vector<tuple<double,int,int>> edgeList;
vector<pii> cordinate;
int p[104];
int r[104];
long long m[104];
long long inhabitant[104];
double res;
bool visited[104];
int get(int u){
    return p[u]==u ? u : get(p[u]);
}
void uni(int u,int v){
    u=get(u);
    v=get(v);
    if(u!=v){
        if(r[u]==r[v]){
            r[u]++;
        }
        if(r[u]>r[v]){
            p[v]=u;
            inhabitant[u]+=inhabitant[v];
        }
        else{
            p[u]=v;
            inhabitant[v]+=inhabitant[u];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,u,v,w,t=0,c,s,q;
    double res1;
    bool first=1;
    while(cin>>n&&n){
        cordinate.clear();
        edgeList.clear();
        res1=0;
        for(int i=0;i<n;i++){
            p[i]=i;
            r[i]=0;
            cin>>u>>v>>m[i];
            inhabitant[i]=m[i];
            res1+=m[i];
            cordinate.push_back(make_pair(u,v));
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double dis=hypot(cordinate[i].first-cordinate[j].first,cordinate[i].second-cordinate[j].second);
                edgeList.push_back(make_tuple(dis,i,j));
            }
        }
        sort(edgeList.begin(),edgeList.end());
        res=0;
        for(int i=0;i<edgeList.size();i++){
            u=get<1>(edgeList[i]);
            v=get<2>(edgeList[i]);
            if(get(u)!=get(v)){
                if(get(u)==get(0)){
                    res+=inhabitant[get(v)]*(get<0>(edgeList[i]));
                }
                if(get(v)==get(0)){
                    res+=inhabitant[get(u)]*(get<0>(edgeList[i]));
                }
                uni(u,v);
            }
        }
        cout<<"Island Group: "<<++t<<" Average "<<setprecision(2)<<fixed<<res/res1<<"\n";
        cout<<"\n";
    }
    return 0;
}