#include<iostream>
using namespace std;
int siz[30004];
int p[30004];
int r[30004];
int res;
int get(int a){
    return p[a]=p[a]==a ? a : get(p[a]);
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
            siz[a]+=siz[b];
            res=max(res,siz[a]);
        } 
        else{
            p[a]=b;
            siz[b]+=siz[a];
            res=max(res,siz[b]);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,t,u,v;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            p[i]=i;
            siz[i]=1;
            r[i]=0;
        }
        res=1;
        while(m--){
            cin>>u>>v;
            uni(u,v);
        }
        cout<<res<<"\n";
    }
    return 0;
}