#include<iostream>
#include<map>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
int siz[300009];
int p[300009];
ll sum[300009];
int r[300009];
int res,n,m,k,u,v;
int get(int a){
    return p[a]=(p[a]==a ? a : get(p[a]));
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
            sum[a]+=sum[b];
        } 
        else{
            p[a]=b;
            siz[b]+=siz[a];
            sum[b]+=sum[a];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n>>m){
        memset(r,0,sizeof(r));
        for(int i=1;i<=n;i++){
            p[i]=i+n;
            p[i+n]=i+n;
            siz[i+n]=1;
            sum[i+n]=i;
        }
        while(m--){
            cin>>k;
            if(k==1){
                cin>>u>>v;
                uni(u,v);
            }
            else if(k==2){
                cin>>u>>v;
                int a=get(u);
                int b=get(v);
                if(a!=b){
                    p[u]=b;
                    siz[a]--;
                    siz[b]++;
                    sum[a]-=u;
                    sum[b]+=u;
                }
            }
            else{
                cin>>u;
                int a=get(u);
                cout<<siz[a]<<" "<<sum[a]<<"\n";
            }
        }
    }
    return 0;
}