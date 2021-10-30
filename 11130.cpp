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
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,v,A,s;
    while(cin>>a>>b>>v>>A>>s&&(a||b||v||A||s)){
        int vertical=int((a+v*s*cos(GocPi*A))/(2*a));
        int horizontal=int((b+v*s*sin(GocPi*A))/(2*b));
        cout<<vertical<<" "<<horizontal<<"\n";
    }
    return 0;
}