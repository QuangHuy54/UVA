#include<iostream>
#include<vector>
#include<cmath>
#include<stdio.h>
#include<cstring>
#include<stack>
#include<queue>
#include<deque>
#include<climits>
#include<map>
#include<algorithm>
#include<string>
#include<cstring>
#include<unordered_map>
#include<iomanip>
using namespace std;
typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,p,c;
    int a[10002];
    int b[10002];
    cin>>n;
    while(n--){
        cin>>p>>c;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=1;i<=p;i++){
            cin>>b[i];
        }
        for(int i=0;i<c;i++){
            cin>>a[i];
        }
        b[0]=0;
        a[c]=INT_MAX;
        p++;
        c++;
        sort(a,a+c);
        sort(b,b+p);
        int angry=INT_MAX,price=0;
        for(int i=0;i<c;i++){
            int pos1=lower_bound(a,a+c,a[i])-a;
            int pos2=upper_bound(b,b+p,a[i])-b;
            if(pos2>p){
                pos2=p;
            }
            if(pos1+p-pos2<angry){
                angry=pos1+p-pos2;
                price=a[i];
            }
            else if(pos1+p-pos2==angry){
                price=min(a[i],price);
            }
        }
        for(int i=0;i<p;i++){
            int pos1=lower_bound(a,a+c,b[i])-a;
            int pos2=upper_bound(b,b+p,b[i])-b;
            if(pos2>p){
                pos2=p;
            }
            if(pos1+p-pos2<angry){
                angry=pos1+p-pos2;
                price=a[i];
            }
            else if(pos1+p-pos2==angry){
                price=min(b[i],price);
            }
        }
        cout<<price<<" "<<angry<<"\n";
    }
    return 0;
}