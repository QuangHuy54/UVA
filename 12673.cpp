#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,g;
    while(cin>>n>>g){
        int s,r;
        vector<int> a;
        int res=0;
        int tie=0;
        for(int i=0;i<n;i++){
            cin>>s>>r;
            if(s>r){
                res+=3;
            }   
            else if(s==r){
                tie++;
                res+=1;
            }
            else{
                a.push_back(r-s+1);
            }
        }
        sort(a.begin(),a.end());
        while(tie>=2&&g>=2){
            tie-=2;
            g-=2;
            res+=4;
        }
        for(int i=0;i<a.size();i++){
            if(g>=a[i]){
                res+=3;
                g-=a[i];
            }  
            else if(tie>0&&g>0){
                tie--;
                g--;
                res+=2;
            }
            else if(a[i]-g==1){
                res++;
                g=0;
            }
            else{
                break;
            }
        }
        if(tie>0&&g>0){
            tie--;
            g--;
            res+=2;
        }
        cout<<res<<"\n";
    }
}