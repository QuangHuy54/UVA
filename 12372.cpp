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
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,l,w,h;
    int n=1;
    cin>>t;
    while(t--){
        cin>>l>>w>>h;
        if(l>20||w>20||h>20){
            cout<<"Case "<<n<<": bad"<<"\n";
        }
        else{
            cout<<"Case "<<n<<": good"<<"\n";
        }
        n++;
    }
    return 0;
}