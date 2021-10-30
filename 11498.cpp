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
    int K,x,y,M,N;
    while(cin>>K&&K!=0){
        cin>>M>>N;
        while(K--){
            cin>>x>>y;
            x=x-M;
            y=y-N;
            if(x==0||y==0){
                cout<<"divisa"<<"\n";
            }
            else if(x<0&&y>0){
                cout<<"NO"<<"\n";
            }
            else if(x>0&&y>0){
                cout<<"NE"<<"\n";
            }
            else if(x>0&&y<0){
                cout<<"SE"<<"\n";
            }
            else{
                cout<<"SO"<<"\n";
            }
        }
    }
}