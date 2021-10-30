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
    int n;
    int a[10000];
    int c=0;
    while(cin>>n&&n!=0){
        if(c==0){
            c++;
        }
        else{
            cout<<"\n";
        }
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<=n-6;i++){
            for(int k=i+1;k<=n-5;k++){
                for(int j=k+1;j<=n-4;j++){
                    for(int l=j+1;l<=n-3;l++){
                        for(int v=l+1;v<=n-2;v++){
                            for(int t=v+1;t<=n-1;t++){
                                cout<<a[i]<<" "<<a[k]<<" "<<a[j]<<" "<<a[l]<<" "<<a[v]<<" "<<a[t]<<"\n";
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}