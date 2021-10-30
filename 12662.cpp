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
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s[101];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    string a[101];
    for(int i=0;i<n;i++){
        a[i]="";
    }
    for(int i=0;i<n;i++){
        if(s[i]!="?"){
            a[i]+=s[i];
        }
        else{
            int posleft=0;
            int posright=0;
            for(int j=i-1;j>=0;j--){
                if(s[j]!="?"){
                    posleft=i-j;
                    break;
                }
            }
            for(int j=i+1;j<n;j++){
                if(s[j]!="?"){
                    posright=j-i;
                    break;
                }
            }
            if(posleft==posright){
                a[i]+=string("middle of ");
                a[i]+=s[i-posleft];
                a[i]+=string(" and ");
                a[i]+=s[posright+i];
            }
            else if(posleft==0){
                for(int j=0;j<posright;j++){
                    a[i]+="left of ";
                }
                a[i]+=s[posright+i];
            }
            else if(posright==0){
                for(int j=0;j<posleft;j++){
                    a[i]+="right of ";
                }
                a[i]+=s[i-posleft];
            }
            else if(posleft<posright){
                for(int j=0;j<posleft;j++){
                    a[i]+="right of ";
                }
                a[i]+=s[i-posleft];
            }
            else if(posleft>posright){
                for(int j=0;j<posright;j++){
                    a[i]+="left of ";
                }
                a[i]+=s[posright+i];
            }
        }
    }
    int q,temp;
    cin>>q;
    while(q--){
        cin>>temp;
        cout<<a[--temp]<<"\n";
    }
}