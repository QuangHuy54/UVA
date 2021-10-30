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
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    list<char> ans;
    while(cin>>s){
        ans.clear();
        auto it=ans.begin();
        for(int i=0;i<s.size();i++){
            if(s[i]=='['){
                it=ans.begin();
            }
            else if(s[i]==']'){
                it=ans.end();
            }
            else{
                ans.insert(it,s[i]);
            }
        }
        for(auto i=ans.begin();i!=ans.end();i++){
            cout<<*i;
        }
        cout<<"\n";
    }
    return 0;
}