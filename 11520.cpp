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
#include<list>
#include<unordered_map>
using namespace std;
typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
using namespace std;
char a[11][11];
bool isSafe(int n,int x,int y,char k){
    if(x==0&&y==0){
        if(a[x+1][y]==k||k==a[x][y+1]){
            return false;
        }
        return true;
    }
    else if(x==0&&y==n-1){
        if(a[x+1][y]==k||k==a[x][y-1]){
            return false;
        }
        return true;
    }
    else if(x==n-1&&y==0){
        if(a[x-1][y]==k||k==a[x][y+1]){
            return false;
        }
        return true;
    }
    else if(x==n-1&&y==n-1){
        if(a[x-1][y]==k||k==a[x][y-1]){
            return false;
        }
        return true;
    }
    else if(x==0){
        if(a[x+1][y]==k||a[x][y-1]==k||a[x][y+1]==k){
            return false;
        }
        return true;
    }
    else if(y==0){
        if(a[x+1][y]==k||a[x-1][y]==k||a[x][y+1]==k){
            return false;
        }
        return true;
    }
    else if(x==n-1){
        if(a[x-1][y]==k||a[x][y-1]==k||a[x][y+1]==k){
            return false;
        }
        return true;
    }
    else if(y==n-1){
        if(a[x-1][y]==k||a[x][y-1]==k||a[x+1][y]==k){
            return false;
        }
        return true;
    }
    else{
        if(a[x-1][y]==k||a[x][y-1]==k||a[x+1][y]==k||a[x][y+1]==k){
            return false;
        }
        return true;
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    int cas=1;
    while(t--){
        cin>>n;
        cout<<"Case "<<cas<<":"<<"\n";
        cas++;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int z=0;z<26;z++){
                    if(a[i][j]!='.'){
                        break;
                    }
                    if(isSafe(n,i,j,z+'A')){
                        a[i][j]=z+'A';
                        break;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<a[i][j];
            }
            cout<<"\n";
        }
    }
    return 0;
}