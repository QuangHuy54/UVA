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
using namespace std;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    while(cin>>n&&n!=0){
    long long k=sqrt(n);
    if(k*k==n){
        cout<<"yes"<<"\n";
    }
    else{
        cout<<"no"<<"\n";
    }
    }
    return 0;
}