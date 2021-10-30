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
#include<iomanip>
using namespace std;
typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,C,P;
    int a[1000001];
    while(cin>>N&&N){
        bool solve=true;
        memset(a,0,sizeof(a));
        for(int i=0;i<N;i++){
            cin>>C>>P;
            if(i+P>=N||i+P<0){
                solve=false;
                continue;
            }
            else if(solve&&a[i+P]!=0){
                solve=false;
                continue;
            }
            a[i+P]=C;
        }
        if(!solve){
            cout<<"-1";
        }
        else{
            for(int i=0;i<N-1;i++){
                cout<<a[i]<<" ";
            }
            cout<<a[N-1];
        }
        cout<<"\n";
    }
}