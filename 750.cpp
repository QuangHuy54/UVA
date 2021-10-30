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
int column[8];
int res,t;
int r1,c1;
int a[8][8];
bool isSafe(int r,int c){
    for(int i=0;i<c;i++){
        if(column[i]==r||abs(column[i]-r)==abs(i-c)){
            return false;
        }
    }
    return true;
}
void solve(int k){
    if(k==8&&column[c1]==r1){
        if(t<10){
        cout<<" "<<t<<"      ";
        }
        else{
            cout<<""<<t<<"      ";
        }
        for(int i=0;i<7;i++){
            cout<<column[i]+1<<" ";
        }
        cout<<column[7]+1<<"\n";
        t++;
    }
    for(int i=0;i<8;i++){
        if(isSafe(i,k)){
            column[k]=i;
            solve(k+1);
        }
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int r,c;
    bool first=true;
    while(n--){
        cin>>r1>>c1;
        res=0;
        t=1;
        if(first){
            first=false;
        }
        else{
            cout<<"\n";
        }
        memset(a,0,sizeof(a));
        memset(column,0,sizeof(column));
        r1--;
        c1--;
        cout<<"SOLN       COLUMN"<<"\n";
        cout<<" #      1 2 3 4 5 6 7 8"<<"\n";
        cout<<"\n";
        solve(0);
    }
    return 0;
}