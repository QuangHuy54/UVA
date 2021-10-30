#include<iostream>
#include<vector>
#include<cmath>
#include<stdio.h>
#include<cstring>
#include<stack>
#include<queue>
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
using namespace std;
struct Gas{
    int l;
    int r;
};
bool comp(Gas a,Gas b){
    if(a.l==b.l){
        return a.r>b.r;
    }
    return a.l<b.l;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Gas a[10004];
    int L,G,le,ra;
    while(cin>>L>>G&&(L||G)){
        for(int i=0;i<G;i++){
            cin>>le>>ra;
            a[i].l=le-ra;
            a[i].r=le+ra;
        }        
        int res=0;
        int current=0;
        bool ok=true;
        sort(a,a+G,comp);
        if(a[0].l>0){
            ok=false;
        }
        for(int i=0;i<G&&ok;i++){
            if(current>=L){
                break;
            }
            if(a[i].r<=current){
                continue;
            }
            if(a[i].l<=current){
                int max_id;
                int max_r=-1;
                for(int j=i;j<G&&a[j].l<=current;j++){
                    if(a[j].r>=max_r){
                        max_id=j;
                        max_r=a[j].r;
                    }
                }
                current=max_r;
                i=max_id;
                res++;
            }
            else{
                ok=false;
            }
        }  
        if(!ok||current<L){
            cout<<"-1"<<"\n";
        }
        else{
            cout<<G-res<<"\n";
        }
    }
    return 0;
}