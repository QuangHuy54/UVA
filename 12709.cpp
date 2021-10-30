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
#include<sstream>
using namespace std;
typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
using namespace std;
struct Ant{
    double H;
    int v;
};
bool cp(Ant a,Ant b){
    if(a.H==b.H){
        return a.v<b.v;
    }
    else{
        return a.H<b.H;
    }
}
int main(){
    Ant a[50001];
    int n,L,W,H;
    while(cin>>n&&n!=0){
        for(int i=0;i<n;i++){
            cin>>L>>W>>a[i].H;
            a[i].v=L*W*a[i].H;
        }
        sort(a,a+n,cp);
        cout<<a[n-1].v;
        cout<<"\n";
    }

    return 0;
}