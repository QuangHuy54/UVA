#include<iostream>
#include<deque>
using namespace std;
int n;
int solve(int m){
    deque<int> a;
    for(int i=1;i<=n;i++){
        a.push_back(i);
    }
    while(a.size()>1){
        a.pop_front();
        for(int i=1;i<m;i++){
            a.push_back(a.front());
            a.pop_front();
        }
    }
    return a.front();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n&&n){
        int m=1;
        while(true){
            int res=solve(m);
            if(res==13){
                cout<<m<<"\n";
                break;
            }
            m++;
        }
    }
}