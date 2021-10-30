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
    vector<string> large;
    vector<string> small;
    int largesum=0;
    int largesmall=0;
    int N,n;
    string s;
    while(cin>>N>>n,N||n){
        for(int i=0;i<N;i++){
            cin>>s;
            large.push_back(s);
        }
        for(int i=0;i<n;i++){
            cin>>s;
            small.push_back(s);
        }
        
    }
}