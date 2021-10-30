#include<iostream>
#include<map>
using namespace std;
int siz[30004];
int p[30004];
int r[30004];
map<string,int> mp;
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
    string s,temp1,temp2;
    while(cin>>n>>m&&(n||m)){
        mp.clear();
        for(int i=1;i<=n;i++){
            cin>>s;
            mp[s]=i;
            p[i]=i;
            siz[i]=1;
            r[i]=0;
        }
        res=1;
        while(m--){
            cin>>temp1>>temp2;
            uni(mp[temp1],mp[temp2]);
        }
        cout<<res<<"\n";
    }
    return 0;
}