#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<vector<int>,int> mp;
    vector<int> temp[10004],res;
    int n,z,maxl,ans;
    while(cin>>n&&n){
        maxl=0;
        ans=0;
        for(int i=0;i<n;i++){
            temp[i].clear();
        }
        mp.clear();
        for(int i=0;i<n;i++){
            for(int j=1;j<=5;j++){
                cin>>z;
                temp[i].push_back(z);
            }
            sort(temp[i].begin(),temp[i].end());
            if(mp.find(temp[i])==mp.end()){
                mp.insert(pair<vector<int>,int>(temp[i],1));
            }
            else{
                mp[temp[i]]++;
            }
            if(mp[temp[i]]>maxl){
                maxl=mp[temp[i]];
            }
        }
        for(int i=0;i<n;i++){
            if(mp[temp[i]]==maxl){
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}