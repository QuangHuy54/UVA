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
using namespace std;
typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int a;
    int temp,used;
    bool accept;
    int c=1;
    while(cin>>n&&n!=0){
        if(c>1){cout<<"\n";}
        accept=false;
        for(int b=1234;b<=98765/n;b++){
            a=b*n;
            temp=a;
            used=b<10000;
            while(temp){
                used|=1<<(temp%10);
                temp/=10;
            }
            temp=b;
            while(temp){
                used|=1<<(temp%10);
                temp/=10;
            }
            if(used==(1<<10)-1){
                if(b<10000){
                    cout<<a<<" / 0"<<b<<" = "<<n<<"\n";
                }
                else{
                    cout<<a<<" / "<<b<<" = "<<n<<"\n";
                }
                accept=true;
            }
        }
        if(!accept){cout<<"There are no solutions for "<<n<<"."<<"\n";}
        c++;
    }
    return 0;
}