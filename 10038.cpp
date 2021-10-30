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
    int arr1[3000];
    int arr2[3000];
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>arr1[i];
        }
        int k=0;
        for(int i=0;i<n-1;i++){
            arr2[k++]=abs(arr1[i]-arr1[i+1]);
        }
        bool jolly=true;
        sort(arr2,arr2+k);
        for(int i=0;i<k;i++){
            if(arr2[i]!=i+1){
                jolly=false;
                break;
            }
        }
        if(jolly){
            cout<<"Jolly"<<"\n";
        }
        else{
            cout<<"Not jolly"<<"\n";
        }
    }
    return 0;
}