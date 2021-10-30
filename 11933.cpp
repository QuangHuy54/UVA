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
#include<iomanip>
using namespace std;
typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
int main(){
    long long n;
    long long a,b;
    while(cin>>n&&n!=0){
        vector<int> pos;
        a=0;
        b=0;
        for(int i=0;i<31;i++){
            if(n&(1<<i)){
                pos.push_back(i);
            }
        }
        for(int i=0;i<pos.size();i++){
            if(i%2!=0){
                b|=(1<<pos[i]);
            }
            else{
                a|=(1<<pos[i]);
            }
        }
        cout<<a<<" "<<b<<"\n";
    }
    return 0;
}