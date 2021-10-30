#include<iostream>
#include<vector>
#include<cmath>
#include<stdio.h>
#include<numeric>
#include<cstring>
#include<stack>
#include<queue>
#include<set>
#include<deque>
#include<map>
#include<algorithm>
#include<string>
#include<cstring>
#include<unordered_map>
using namespace std;
typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
ll ar[4100000];
ll n,m,u,v,q,k,t,cs=0,qs=0;
ll res[4100000];
string s,s1;
char c;
void build(int id,int l,int r){
    if(l==r){
        res[id]=s[l]-'0';
        ar[id]=0;
        return;
    }
    int m=(l+r)/2;
    build(2*id,l,m);
    build(2*id+1,m+1,r);
    res[id]=res[2*id]+res[2*id+1];
    ar[id]=0;
}
/*void apply(ll& a,lazy b,int len){
    if(b.a==0&&b.d==0){
        return;
    }
    else{
        a=b.assign*len;
        a+=b.add*len;
    }
}*/
void apply(ll& a,ll b){
    if(b==0){
        return;
    }
    if(b==1||b==2){
        a=b;
    }
    else{
        if(a==1) a=2;
        else if(a==2) a=1;
        else if(a==3) a=0;
        else if(a==0) a=3;
    }
}
void apply(ll&a, ll b,int len){
    if(b==0){
        return;
    }
    if(b==1){
        a=len;
    }
    else if(b==2){
        a=0;
    }
    else{
        a=len-a;
    }
}
/*void propagate(int id,int l,int r){
    if(l==r){
        return;
    }
    int m=(l+r)/2;
    apply(ar[2*id],ar[id],l);
    apply(ar[2*id+1],ar[id],l);
    ar[id].a=0;
    ar[id].d=0;
}*/
void modify(int id,int lx,int rx,int l,int r,ll v){
    if(ar[id]!=0){
        apply(res[id],ar[id],rx-lx+1);
        if(rx!=lx){
            apply(ar[2*id],ar[id]);
            apply(ar[2*id+1],ar[id]);
        }
        ar[id]=0;
    }
    if(rx<l||lx>r){
        return;
    }
    if(lx>=l&&rx<=r){
        apply(res[id],v,rx-lx+1);
        if(rx!=lx){
            apply(ar[2*id],v);
            apply(ar[2*id+1],v);
        }
        return;
    }
    int m=(lx+rx)/2;
    modify(2*id,lx,m,l,r,v);
    modify(2*id+1,m+1,rx,l,r,v);
    res[id]=res[2*id]+res[2*id+1];
}
ll get(int id,int lx,int rx,int l,int r){
    if(ar[id]!=0){
        apply(res[id],ar[id],rx-lx+1);
        if(rx!=lx){
            apply(ar[2*id],ar[id]);
            apply(ar[2*id+1],ar[id]);
        }
        ar[id]=0;
    }
    if(rx<l||lx>r){
        return 0;
    }
    if(lx>=l&&rx<=r){
        return res[id];
    }
    int m=(lx+rx)/2;
    ll temp1=get(2*id,lx,m,l,r);
    ll temp2=get(2*id+1,m+1,rx,l,r);
    return temp1+temp2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>m;
        cout<<"Case "<<++cs<<":"<<"\n";
        s="";
        qs=0;
        n=0;
        while(m--){
            cin>>u>>s1;
            n+=u*s1.size();
            for(int i=0;i<u;++i){
                s+=s1;
            }
        }
        build(1,0,n-1);
        cin>>q;
        while(q--){
            cin>>c>>u>>v;
            if(c=='F'){
                modify(1,0,n-1,u,v,1);
            }
            else if(c=='E'){
                modify(1,0,n-1,u,v,2);
            }
            else if(c=='I'){
                modify(1,0,n-1,u,v,3);
            }
            else{
                cout<<"Q"<<++qs<<": "<<get(1,0,n-1,u,v)<<"\n";
            }
        }
    }
    return 0;
}