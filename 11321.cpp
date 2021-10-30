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
int m;
bool compare(int a,int b){
    /*if(a%m==b%m){
        if(a%2!=b%2){
            if(a%2!=0){
                return true;
            }
            else{
                return false;
            }
        }
        else if(a%2==0){
            return a<b;
        }
        else{
            return a>b;
        }
    }
    else{
        return a%m<b%m;
    }*/
    if(a%m != b%m)
       return a%m < b%m;
    else
    {
        if(abs(a)%2 == 0 && abs(b)%2 == 0)
          return a<b;
        else if(abs(a)%2 != 0 && abs(b)%2 != 0)
                return a>b;
        else if(abs(a)%2 != 0)
                return true;
        else
            return false;
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int a[10001];
    int n;
    while(cin>>n>>m&&(n||m)){
        cout<<n<<" "<<m<<"\n";
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n,compare);
        for(int i=0;i<n;i++){
            cout<<a[i]<<"\n";
        }
    }
    cout<<"0 0"<<"\n";
}