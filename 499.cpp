#include<iostream>
#include<vector>
#include<cmath>
#include<stdio.h>
#include<cstring>
#include<string.h>
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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    string s;
    int up[26];
    int low[26];
    while(getline(cin,s)){
        memset(up,0,sizeof(up));
        memset(low,0,sizeof(low));
        for(int i=0;i<s.size();i++){
            if(s[i]>='a'&&s[i]<='z'){
                low[s[i]-'a']++;
            }
            else if(s[i]>='A'&&s[i]<='Z'){
                up[s[i]-'A']++;
            }
        }
        int max=0;
        for(int i=0;i<26;i++){
            if(up[i]>max){
                max=up[i];
            }
        }
        for(int i=0;i<26;i++){
            if(low[i]>max){
                max=low[i];
            }
        }
        for(int i=0;i<26;i++){
            if(up[i]==max){
                char c=i+'A';
                cout<<c;
            }
        }
        for(int i=0;i<26;i++){
            if(low[i]==max){
                char c=i+'a';
                cout<<c;
            }
        }
        cout<<" "<<max<<"\n";
    }
    return 0;
}