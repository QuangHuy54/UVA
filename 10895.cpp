#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,temp[10009],t,x;
    vector<pair<int,int>> a[1009];
    while(cin>>n>>m)
    {
        for(int i=1;i<=m;i++){
            a[i].clear();
        }
        for(int i=1;i<=n;i++){
            cin>>t;
            for(int j=1;j<=t;j++){
                cin>>temp[j];
            }
            for(int j=1;j<=t;j++){
                cin>>x;
                a[temp[j]].push_back(make_pair(i,x));
            }
        }
        cout<<m<<" "<<n<<"\n";
        for(int i=1;i<=m;i++){
            if(a[i].empty()){
                cout<<"0"<<"\n"<<"\n";
            }
            else{
                cout<<a[i].size()<<" ";
                for(int j=0;j<a[i].size();j++){
                    cout<<a[i][j].first;
                    if(j==a[i].size()-1){
                        cout<<"\n";
                    }
                    else{
                        cout<<" ";
                    }
                }
                for(int j=0;j<a[i].size();j++){
                    cout<<a[i][j].second;
                    if(j==a[i].size()-1){
                        cout<<"\n";
                    }
                    else{
                        cout<<" ";
                    }
                }
            }
        }
    }   
    return 0;
}