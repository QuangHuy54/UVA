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
    int ar[26];
    memset(ar,0,sizeof(ar));
    for(int i=0;i<26;i++){
        if(i+'A'=='B'||i+'A'=='F'||i+'A'=='P'||i+'A'=='V'){
            ar[i]=1;
        }
        else if(i+'A'=='C'||i+'A'=='G'||i+'A'=='J'||i+'A'=='K'||i+'A'=='Q'||i+'A'=='S'||i+'A'=='X'||i+'A'=='Z'){
            ar[i]=2;
        }
        else if(i+'A'=='D'||i+'A'=='T'){
            ar[i]=3;
        }
        else if(i+'A'=='L'){
            ar[i]=4;
        }
        else if(i+'A'=='M'||i+'A'=='N'){
            ar[i]=5;
        }
        else if(i+'A'=='R'){
            ar[i]=6;
        }
    }
    string s;
    while(cin>>s){
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                if(ar[s[i]-'A']==ar[s[j]-'A']){
                    i++;
                }
                else{
                    break;
                }
            }
            if(ar[s[i]-'A']){
                cout<<ar[s[i]-'A'];
            }
        }
        cout<<"\n";
    }
}