#include<iostream>
#include<map>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
int siz[300009];
int p[300009];
int sum[300009];
int r[20004];
int res,n,m,k,u,v;
int get(int a){
    if(a==p[a]) return a;
    else{
        int k=get(p[a]);
        sum[a]+=sum[p[a]];
        return p[a]=k;
    }
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
            sum[a]+=(abs(b-a))%1000;
        } 
        else{
            p[a]=b;
            sum[b]+=(abs(b-a))%1000;
        }
    }
}
string s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            p[i]=i;
            sum[i]=0;
        }
        while(cin>>s&&(s!="O")){
            if(s=="I"){
                cin>>u>>v;
                p[u]=v;
                sum[u]=(abs(u-v))%1000;
            }
            else{
                cin>>u;
                get(u);
                cout<<sum[u]<<"\n";
            }
        }
    }
    return 0;
}