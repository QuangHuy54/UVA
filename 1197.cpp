#include<iostream>
#include<map>
#include<vector>
using namespace std;
int siz[30004];
int p[30004];
int r[30004];
int res,n,m,k,u,v;
typedef long long ll;
int get(int a){
    return p[a]==a ? a : get(p[a]);
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
        } 
        else{
            p[a]=b;
            siz[b]+=siz[a];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n>>m&&(n||m)){
        for(int i=0;i<=n;i++){
            p[i]=i;
            siz[i]=1;
        }
        while(m--){
            cin>>k;
            cin>>u;
            k--;
            for(int i=0;i<k;i++){
                cin>>v;
                uni(u,v);
            }
        }
        cout<<siz[get(0)]<<"\n";
    }
    return 0;
}