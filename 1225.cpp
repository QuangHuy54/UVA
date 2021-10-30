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
    int n,t;
    cin>>t;
    int a[10];
    while(t--){
        cin>>n;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            int j=i;
            while(j!=0){
                a[j%10]++;
                j/=10;
            }
        }
        for(int i=0;i<=8;i++){
            cout<<a[i]<<" ";
        }
        cout<<a[9]<<"\n";
    }
    return 0;
}