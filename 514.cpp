#include<iostream>
#include<stack>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int a[1002];
    stack<int> ans;
    while(cin>>n&&n){
        while(true){
            cin>>a[0];
            if(a[0]==0){
                break;
            }
            for(int i=1;i<n;i++){
                cin>>a[i];
            }
            while(ans.empty()==false){
                ans.pop();
            }
            int j=1;
            bool solve=true;
            for(int i=0;i<n;i++){
                while(j<=n&&(ans.empty()||ans.top()!=a[i])){
                    ans.push(j);
                    j++;
                }
                if(ans.top()==a[i]){
                    ans.pop();
                }
                else{
                    solve=false;
                    break;
                }
            }
            if(solve&&ans.empty()){
                cout<<"Yes"<<"\n";
            }
            else{
                cout<<"No"<<"\n";
            }
        }
        cout<<"\n";
    }
    return 0;
}