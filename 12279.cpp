#include<iostream>
#include<vector>
#include<cmath>
#include<stdio.h>
#include<cstring>
using namespace std;
typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,S,x,c=1;
    while(cin>>N&&N!=0){
        S=0;
        while(N--){
            cin>>x;
            if(x>0){
                S+=1;
            }
            else{
                S-=1;
            }
        }
        cout<<"Case "<<c<<": "<<S<<"\n";
        c++;
    }
}