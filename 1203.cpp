#include<iostream>
#include<tuple>
#include<queue>
using namespace std;
typedef tuple<int,int,int> tiii;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<tiii,vector<tiii>,greater<tiii>> pq;
    string s;
    int qnum,p,k;
    while(cin>>s){
        if(s=="#"){
            cin>>k;
            break;
        }
        cin>>qnum>>p;
        pq.push(make_tuple(p,qnum,p));
    }
    while(k--){
        tiii pr=pq.top();
        pq.pop();
        cout<<get<1>(pr)<<"\n";
        get<0>(pr)+=get<2>(pr);
        pq.push(pr);
    }
    return 0;
}