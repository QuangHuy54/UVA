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
struct Segment{
    int l;
    int r;
};
bool comp(Segment a,Segment b){
    if(a.l==b.l){
        return a.r>b.r;
    }
    return a.l<b.l;
}
Segment a[100008];
Segment choose[100008];
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    int L,R;
    bool first=true;
    cin>>n;
    while(n--){
        cin>>m;
        if(first){
            first=false;
        }
        else{
            cout<<"\n";
        }
        int s=0;
        while(cin>>L>>R&&(L||R)){
            a[s].l=L;
            a[s].r=R;
            s++;
        }
        int covered=0;
        int res=0;
        bool possible=true;
        sort(a,a+s,comp);        
        for(int i=0;i<s&&possible;i++){
            if(covered>=m){
                break;
            }
            if(a[i].r<=covered){
                continue;
            }
            if(a[i].l<=covered){
                int max_id;
                int max_r=-1;
                for(int j=i;j<s&&a[j].l<=covered;j++){
                    if(a[j].r>max_r){
                        max_r=a[j].r;
                        max_id=j;
                    }
                }
                covered=max_r;
                i=max_id;
                choose[res].l=a[i].l;
                choose[res].r=a[i].r;
                res++;
            }
            else{
                possible=false;
            }
        }
        if(!possible||(covered<m)){
            cout<<"0"<<"\n";
        }
        else{
        cout<<res<<"\n";
        for(int i=0;i<res;i++){
            cout<<choose[i].l<<" "<<choose[i].r<<"\n";
        }
        }
    }
}