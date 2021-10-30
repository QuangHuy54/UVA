#include<iostream>
#include<vector>
#include<utility>
#include<tuple>
#include<algorithm>
#include<cmath>
using namespace std;
typedef pair<int,int> pii;
vector<pii> cordinate;
vector<tuple<double,int,int>> edgeList;
int p1[1004];
int r1[1004];
int p2[1004];
int r2[1004];
int get(int u,int p[]){
    return p[u]==u ? u : get(p[u],p);
}
void uni(int u,int v,int p[],int r[]){
    u=get(u,p);
    v=get(v,p);
    if(u!=v){
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
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,u,v,w,t,res1,c=0;
    double r,res2,res3;
    cin>>t;
    while(t--){
        cin>>n>>r;
        res1=0;
        res2=res3=0;
        edgeList.clear();
        cordinate.clear();
        for(int i=0;i<n;i++){
            p1[i]=i;
            r1[i]=0;
            p2[i]=i;
            r2[i]=0;
        }
        for(int i=0;i<n;i++){
            cin>>u>>v;
            cordinate.push_back(make_pair(u,v));
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                pii u=cordinate[i];
                pii v=cordinate[j];
                double dis=sqrt((u.first-v.first)*(u.first-v.first)+(u.second-v.second)*(u.second-v.second));
                if(dis<=r){
                    uni(i,j,p1,r1);
                }
                edgeList.push_back(make_tuple(dis,i,j));
            }
        }
        for(int i=0;i<n;i++){
            if(p1[i]==i){
                res1++;
            }
        }
        sort(edgeList.begin(),edgeList.end());
        for(int i=0;i<edgeList.size();i++){
            u=get<1>(edgeList[i]);
            v=get<2>(edgeList[i]);
            if(get(u,p2)!=get(v,p2)){
                uni(u,v,p2,r2);
                if(get<0>(edgeList[i])<=r){
                    res2+=get<0>(edgeList[i]);
                }
                else{
                    res3+=get<0>(edgeList[i]);
                }
            }
        }
        cout<<"Case #"<<++c<<": "<<res1<<" "<<round(res2)<<" "<<round(res3)<<"\n";
    }
    return 0;
}