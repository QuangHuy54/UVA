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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    string s;
    while(t--){
        cin>>s;
        int result=0;
        int temp=1;
        for(int i=0;i<s.size();i++){    
            if(s[i]=='O'){
                result+=temp;
                temp++;
            }
            else{
                temp=1;
            }
        }
        cout<<result<<"\n";
    }
    return 0;
}