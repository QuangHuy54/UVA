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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s;
    int c=1;
    while(n--){
        int answ=0;
        cin>>s;
        cout<<"Case "<<c<<": ";
        c++;
        for(int i=0;i<s.size();i++){
            if(s[i]=='-'){
                if(s[i+1]=='B'&&i<s.size()-1){
                    continue;
                }
                else if(s[i+2]=='B'&&i<s.size()-2){
                    continue;
                }
                else if(s[i+1]=='S'&&i<s.size()-1){
                    continue;
                }
                else if(s[i-1]=='S'&&i>=1){
                    continue;
                }
                answ++;
            }
        }
        cout<<answ<<"\n";
    }
    return 0;
}