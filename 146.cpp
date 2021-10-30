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
    string s;
    while(cin>>s&&s!="#"){
        string temp=s;
        bool appear=false;
        do{
            if(s>temp){
                cout<<s<<"\n";
                appear=true;
                break;
            }
        }while(next_permutation(s.begin(),s.end()));
        if(!appear){
            cout<<"No Successor"<<"\n";
        }
    }
    return 0;
}