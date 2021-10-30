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
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin>>n&&n>=0){
        cout<<n<<" coconuts, ";
        int res=0;
        bool ok=false;
        for(int i=sqrt(n)+1;i>=2;i--){
            bool solve=true;
            int temp=n;
            for(int j=0;j<i;j++){
                if(temp%i!=1){
                  solve=false;
                  break;  
                }
                temp-=((temp/i)+1);
            }
            if(solve&&temp%i!=0){
                solve=false;
            }
            if(solve){
                res=i;
                ok=true;
                break;
            }
        }
        if(!ok){
            cout<<"no solution"<<"\n";
        }
        else{
            cout<<res<<" people and 1 monkey"<<"\n";
        }
    }
    return 0;
}