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
#define EPS 1e-9
using namespace std;
typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
using namespace std;
struct Is{
    double x;
    double y;
};
bool comp(Is a,Is b){
    if(a.x==b.x){
        return a.y>b.y;
    }
    return a.x<b.x;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,d,l,r;
    int t=1;
    double temp;
    Is a[1005];
    while(cin>>n>>d&&(n||d)){
        bool posible=true;
        for(int i=0;i<n;i++){
            cin>>l>>r;
            if(r>d){
                posible=false;
            }
            else{
            temp=sqrt(d*d-r*r);
            a[i].x=l-temp;
            a[i].y=l+temp;
            }
        }
        cout<<"Case "<<t<<": ";
        t++;
        sort(a,a+n,comp);
        int res=1;
        double covered=a[0].y;
        for(int i=1;i<n&&posible;i++){
            if(a[i].x>covered){
                res++;
                covered=a[i].y;
            }
            else if(a[i].y<covered){
                covered=a[i].y;
            }
        }
        if(!posible){
            cout<<"-1"<<"\n";
        }
        else{
            cout<<res<<"\n";
        }
    }
    return 0;
}