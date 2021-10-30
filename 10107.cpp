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
    long long n;
    vector<long long> a;
    long long prev=0;
    long long size=0;
    long long median;
    while(scanf("%lld",&n)!=EOF){
        size++;
        a.push_back(n);
        sort(a.begin(),a.end());
        if(size%2==0){
            median=(a[size/2]+a[(size/2)-1])/2;
            cout<<median<<"\n";
        }
        else{
            median=a[size/2];
            cout<<median<<"\n";
        }
        prev=n;
    }
    return 0;
}