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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,Q,l,u;
    int a[601][601];
    while(cin>>N>>M&&N&&M){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>a[i][j];
            }
        }
        cin>>Q;
        while(Q--){
            cin>>l>>u;
            int res=0;
            for(int i=0;i<N;i++){
                int left=0;
                int right=M-1;
                int temp=0;
                while(left<right){
                    int mid=(left+right)/2;
                    if(a[i][mid]>=l){
                        right=mid;
                    }
                    else{
                        left=mid+1;
                    }
                }
                temp=a[i][left];
                if(temp<l){
                    continue;
                }
                for(int j=res;j<N;j++){
                    if(i+j>=N||left+j>=M||a[i+j][left+j]>u){
                        break;
                    }
                    res=max(res,j+1);
                }
            }
            cout<<res<<"\n";
        }
        cout<<"-"<<"\n";
    }

    
    return 0;
}