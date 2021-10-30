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
int res;
bool isSafe(int x,int y,char a[4][4],int n){
    int x1,y1;
    for(int i=x+1;i<n;i++){
        if(a[i][y]=='X'){
            break;
        }
        if(a[i][y]=='I'){
            return false;
        }
    }
    for(int i=x+1;i<n;i++){
        if(a[x][i]=='X'){
            break;
        }
        if(a[x][i]=='I'){
            return false;
        }
    }
    for(int i=x-1;i>=0;i--){
        if(a[x][i]=='X'){
            break;
        }
        if(a[x][i]=='I'){
            return false;
        }
    }
    for(int i=x-1;i>=0;i--){
        if(a[i][y]=='X'){
            break;
        }
        if(a[i][y]=='I'){
            return false;
        }
    }
    return true;
}
void solve(int num,char a[4][4],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(isSafe(i,j,a,n)&&a[i][j]=='.'){
                a[i][j]='I';
                solve(num+1,a,n);
                a[i][j]='.';
            }
        }
    }
    res=max(res,num);
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    char a[4][4];
    while(cin>>n&&n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        res=0;
        solve(0,a,n);
        cout<<res<<"\n";
    }
    return 0;
}