#include<iostream>
#include<queue>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x,cost,a,b;
    while(cin>>n&&n){
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            cin>>x;
            pq.push(x);
        }
        cost=0;
        while(pq.size()>1){
            a=pq.top();
            pq.pop();
            b=pq.top();
            pq.pop();
            cost+=(a+b);
            pq.push(a+b);
        }
        cout<<cost<<"\n";
    }
    return 0;
}