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
    int n,m;
    int a[1001];
    int t=1;
    long long query;
    while(cin>>n&&n!=0){
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    cin>>m;
    cout<<"Case "<<t<<":"<<"\n";
    while(m--){
        cin>>query;
        long long summin=0;
        long long distance=0;
        bool first=true;
        for(int i=n-1;i>=1;i--){
            for(int j=i-1;j>=0;j--){
                if(first){
                    first=false;
                    distance=abs(a[i]+a[j]-query);
                    summin=a[i]+a[j];
                }
                else{
                    if(a[i]>query&&i!=1){
                        continue;
                    }
                    else{
                    if(abs(a[i]+a[j]-query)<distance){
                        distance=abs(a[i]+a[j]-query);
                        summin=a[i]+a[j];
                    }
                    }
                }
            }
        }
        cout<<"Closest sum to "<<query<<" is "<<summin<<"."<<"\n";
    }
    t++;
    }
    return 0;
}