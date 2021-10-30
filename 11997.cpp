#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct ele{
    int sum;
    int id;
    bool operator<(const ele& a) const{
        return a.sum<sum;
    }
};
int a[752][752];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        sort(a[0],a[0]+n);
        for(int i=1;i<n;i++){
            priority_queue<ele> pq;
            sort(a[i],a[i]+n);
            for(int j=0;j<n;j++){
                pq.push({a[i][0]+a[0][j],0});
            }
            for(int j=0;j<n;j++){
                ele temp=pq.top();
                pq.pop();
                a[0][j]=temp.sum;
                temp.sum=temp.sum-a[i][temp.id]+a[i][temp.id+1];
                temp.id++;
                if(temp.id<n){
                    pq.push(temp);
                }
            }
        }
        cout<<a[0][0];
        for(int i=1;i<n;i++){
            cout<<" "<<a[0][i];
        }
        cout<<"\n";
    }
    return 0;
}