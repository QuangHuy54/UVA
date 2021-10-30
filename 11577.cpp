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
    int t;
    cin>>t;
    string s;
    int a[30];
    cin.ignore();
    while(t--){
        getline(cin,s);
        memset(a,0,sizeof(a));
        for(int i=0;i<s.size();i++){
            if(s[i]>='a'&&s[i]<='z'){
                a[s[i]-'a']++;
            }
            else if(s[i]>='A'&&s[i]<='Z'){
                a[s[i]-'A']++;
            }
        }
        int max=0;
        for(int i=0;i<26;i++){
            if(a[i]>max){
                max=a[i];
            }
        }
        for(int i=0;i<26;i++){
            if(a[i]==max){
                char c=i+'a';
                cout<<c;
            }
        }
        cout<<"\n";
    }
}