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
    int K,x,y,z,min,c=1,mid,result;
    cin>>K;
    while(K--){
        cin>>x>>y>>z;
        mid=(x+y+z)/3;
        min=abs(x-mid);
        result=x;
        if(min>abs(y-mid)){
            min=abs(y-mid);
            result=y;}
        if(min>abs(z-mid)){
            min=abs(z-mid);
            result=z;}
        cout<<"Case "<<c<<": "<<result<<"\n";
        c++;
    }
    return 0;
}