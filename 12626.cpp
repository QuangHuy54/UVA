#include<iostream>
#include<vector>
#include<cmath>
#include<stdio.h>
#include<cstring>
#include<string.h>
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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    string s;
    int a[6];
    while(t--){
        cin>>s;
        memset(a,0,sizeof(a));
        int res=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='M'){a[0]++;}
            else if(s[i]=='A'){a[1]++;}
            else if(s[i]=='R'){a[2]++;}
            else if(s[i]=='G'){a[3]++;}
            else if(s[i]=='I'){a[4]++;}
            else if(s[i]=='T'){a[5]++;}
        }
        while(a[0]>=1&&a[1]>=3&&a[2]>=2&&a[3]>=1&&a[4]>=1&&a[5]>=1){
            res++;
            a[0]--;
            a[1]-=3;
            a[2]-=2;
            a[3]--;
            a[4]--;
            a[5]--;
        }
        cout<<res<<"\n";
    }
    return 0;
}