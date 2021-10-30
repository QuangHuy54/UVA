#include<iostream>
#include<algorithm>
using namespace std;
struct Constraint{
    int x;
    int y;
    int c;
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[9],n,m,res;
    bool check;
    Constraint con[21];
    while(cin>>n>>m&&(n||m)){
        for(int i=0;i<m;i++){
            cin>>con[i].x>>con[i].y>>con[i].c;
        }
        for(int i=0;i<n;i++){
            a[i]=i;
        }
        res=0;
        do{
            check=true;
            for(int i=0;i<m;i++){
                if(con[i].c>0){
                    if(abs(a[con[i].x]-a[con[i].y])>con[i].c){
                        check=false;
                        break;
                    }
                }
                else{
                    if(abs(a[con[i].x]-a[con[i].y])<(con[i].c)*(-1)){
                        check=false;
                        break;
                    }
                }
            }
            if(check){
                res++;
            }
        }while(next_permutation(a,a+n));
        cout<<res<<"\n";
    }
    return 0;
}