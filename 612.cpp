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
struct ADN{
    string s;
    int res;
    int pos;
};
bool compare(ADN a,ADN b){
    if(a.res==b.res){
        return a.pos<b.pos;
    }
    return a.res<b.res;
}
int main () {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int M,n,m;
    cin>>M;
    bool first=true;
    ADN a[101];
    while(M--){
        cin>>n>>m;
        if(first){
            first=false;
        }
        else{
            cout<<"\n";
        }
        for(int i=0;i<m;i++){
            cin>>a[i].s;
            int t=0;
            for(int j=0;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(a[i].s[j]>a[i].s[k]){
                        t++;
                    }
                }
            }
            a[i].res=t;
            a[i].pos=i;
        }
        sort(a,a+m,compare);
        for(int i=0;i<m;i++){
           cout<<a[i].s<<"\n";
        }
    }
}