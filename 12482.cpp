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
bool comp(string a,string b){
    return a.size()>b.size();
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int visited[1001];
    int n,l,c,res,line;
    int len;
    while(cin>>n>>l>>c){
        res=0,line=0;
        for(int i=0;i<n;i++){
            cin>>s;
            len=s.size();
            if(res+len<=c){
                res+=len+1;
            }
            else{
                res=len+1;
                line++;
            }
        }
        if(res!=0){
            line++;
        }
        cout<<(line+l-1)/l<<"\n";
    }
    return 0;
}