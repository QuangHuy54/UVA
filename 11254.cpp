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
#include<list>
#include<unordered_map>
using namespace std;
typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
using namespace std;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    while(cin>>n&&n!=-1){
        cout<<n<<" = ";
        bool solve=false;
        int res=0;
        long long k=0;
        for(int i=sqrt(2*n);i>=1;i--){
            if((2*n+i-i*i)%(2*i)==0){
                solve=true;
                res=i;
                k=(2*n+i-i*i)/(2*i);
                break;
            }
        }
        if(solve){
            cout<<k<<" + ... + "<<k+res-1<<"\n";
        }
        else{
            cout<<n<<" + ... + "<<n<<"\n";
        }
    }
    return 0;
}