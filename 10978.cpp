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
    string order[53];
    while(cin>>n&&n){
        int pos=-1;
        string temp,s;
        for(int i=0;i<53;i++){
            order[i]="";
        }
        for(int i=0;i<n;i++){
            cin>>temp>>s;
            int len=s.size();
            while(len){
                pos++;
                if(pos>=n){
                    pos=0;
                }
                if(order[pos]==""){
                    len--;
                }
            }
            order[pos]=temp;
        }
        for(int i=0;i<n-1;i++){
            cout<<order[i]<<" ";
        }
        cout<<order[n-1]<<"\n";
    }
    return 0;
}