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
#define GocPi 3.14159265/180
using namespace std;
typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
using namespace std;
bool ok;
void solve(int a[5],int t,int sum){
    if(t==5){
        if(sum==23){
            ok=true;
        }
        return;
    }
    else{
        int num=a[t];
        solve(a,t+1,sum+num);
        solve(a,t+1,sum-num);
        solve(a,t+1,sum*num);
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[5];
    int b,c,d,e,f;
    while(cin>>b>>c>>d>>e>>f&&(b||c||d||e||f)){
        ok=false;
        a[0]=b;
        a[1]=c;
        a[2]=d;
        a[3]=e;
        a[4]=f;
        sort(a,a+5);
        do {
            solve(a,1,a[0]);
            if(ok){
                break;
            }
        } while (next_permutation(a, a + 5));
        if(ok){
            cout<<"Possible"<<"\n";
        }
        else{
            cout<<"Impossible"<<"\n";
        }
    }
    return 0;
}