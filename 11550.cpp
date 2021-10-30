#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int n,m,a[9][30],t,temp,first,second;
vector<pair<int,int>> edge;
bool comp(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first<b.first;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        bool ok=true;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        edge.clear();
        for(int j=0;j<m;j++){
            temp=0;
            first=-1;
            second=-1;
            for(int i=0;i<n;i++){
                if(a[i][j]==1){
                    temp++;
                    if(first!=-1){
                        second=i;
                    }
                    else{
                        first=i;
                    }
                }
            }
            if(temp!=2){
                ok=false;
                break;
            }
            else{
                edge.push_back(make_pair(first,second));
            }
        }
        if(!ok){
            cout<<"No"<<"\n";
        }
        else{
            bool multiple=false;
            if(edge.size()>=2){
            sort(edge.begin(),edge.end(),comp);
            for(int i=0;i<edge.size()-1;i++){
                if(edge[i].first==edge[i+1].first&&edge[i].second==edge[i+1].second){
                    multiple=true;
                    break;
                }
            }
            }
            if(multiple){
                cout<<"No"<<"\n";
            }
            else{
                cout<<"Yes"<<"\n";
            }
        }
    }
    return 0;
}