#include<bits/stdc++.h>
using namespace std;
struct packet{
    int message;
    int start;
    int end;
    bool operator<(const packet& y) const{
        return start<y.start;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int order[6],n,m,c=0;
    for(int i=0;i<5;i++){
        order[i]=i+1;
    }
    packet a[1001];
    int size[6];
    while(cin>>n>>m&&(n||m)){
        int res=INT_MAX;
        set<packet> buffer[6];
        for(int i=0;i<n;i++){
            cin>>size[i];
        }
        for(int i=0;i<m;i++){
            cin>>a[i].message>>a[i].start>>a[i].end;
        } 
        do{
            int index=0;
            int cur=0;
            int next=1;
            int sizeBuf=0;
            for(int i=0;i<m;i++){
                cur+=(a[i].end-a[i].start+1);
                buffer[a[i].message-1].insert(a[i]);
                while(index<n&&!buffer[order[index]-1].empty()&&(*buffer[order[index]-1].begin()).start==next){
                    auto it=buffer[order[index]-1].begin();
                    cur-=((*it).end-(*it).start+1);
                    next=(*it).end+1;
                    buffer[order[index]-1].erase(it);
                    if(next>=size[order[index]-1]){
                        index++;
                        next=1;
                    }
                }
                sizeBuf=max(sizeBuf,cur);
            }
            res=min(res,sizeBuf);
        }while(next_permutation(order,order+n));
        cout<<"Case "<<++c<<": "<<res<<"\n";
        cout<<"\n";
    }
    return 0;
}