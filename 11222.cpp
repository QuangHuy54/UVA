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
struct Player{
    bool pro[10001];
    int solve;
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    int cas=1;
    Player a[3];
    while(t--){
    cout<<"Case #"<<cas<<":"<<"\n";
    cas++;
    int temp,size;
    memset(a[0].pro,0,sizeof(a[0].pro));
    memset(a[1].pro,0,sizeof(a[1].pro));
    memset(a[2].pro,0,sizeof(a[2].pro));
    int maxtemp=0;
    for(int i=0;i<3;i++){
        a[i].solve=0;
        cin>>size;
        for(int k=0;k<size;k++){
            cin>>temp;
            maxtemp=max(maxtemp,temp);
            a[i].pro[temp]=true;
        }
    }
    int maxs=0;
    for(int i=0;i<3;i++){
        for(int j=1;j<=maxtemp;j++){
        if(i==0){
                if(a[i].pro[j]&&!a[1].pro[j]&&!a[2].pro[j]){
                    a[i].solve++;
                }
            }
            else if(i==1){
                if(a[i].pro[j]&&!a[0].pro[j]&&!a[2].pro[j]){
                    a[i].solve++;
                }
         }
            else{
                    if(a[i].pro[j]&&!a[0].pro[j]&&!a[1].pro[j]){
                        a[i].solve++;
                    }
                }
        }
         maxs=max(maxs,a[i].solve);
    }
    for(int i=0;i<3;i++){
        if(a[i].solve==maxs){
            cout<<i+1<<" "<<maxs;
            for(int j=1;j<=maxtemp;j++){
                if(i==0){
                    if(a[i].pro[j]&&!a[1].pro[j]&&!a[2].pro[j]){
                        cout<<" "<<j;
                    }
                }
                else if(i==1){
                    if(a[i].pro[j]&&!a[0].pro[j]&&!a[2].pro[j]){
                        cout<<" "<<j;
                    }
                }
                else{
                    if(a[i].pro[j]&&!a[0].pro[j]&&!a[1].pro[j]){
                        cout<<" "<<j;
                    }
                }
            }
            cout<<"\n";
        }
    }
    }
    return 0;
}
           