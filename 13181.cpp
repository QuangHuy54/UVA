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
#include<iomanip>
using namespace std;
typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while(cin>>s){
        int pos=0;
        int left=0;
        int temp=0;
        int right=0;
        int dis=0;
        for(int i=0;i<s.size();i++){
           if(s[i]=='X'){
               pos=i;
               break;
           }
           else{
               left++;
           }
        }
        for(int i=s.size()-1;i>=0;i--){
           if(s[i]=='X'){
               break;
           }
           else{
               right++;
           }
        }
        int answ=max(left,right)-1;
        for(int i=pos;i<s.size();i++){
            if(s[i]=='X'){
                dis=max(dis,temp);
                temp=0;
            }
            else{
                temp++;
            }
        }
        dis=max(dis,temp);
        temp=(dis+1)/2;
        temp--;
        if(temp>answ){
            answ=temp;
        }
        cout<<answ<<"\n";
    }
    return 0;
}