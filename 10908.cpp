#include<iostream>
using namespace std;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t,m,n,q,x,y;
    char a[120][120];
    cin>>t;
    while(t--){
        cin>>m>>n>>q;
        for(int i=0;i<m;i++){
           scanf("%s",&a[i]);
        }
        cout<<m<<" "<<n<<" "<<q<<"\n";
        while(q--){
            cin>>x>>y;
            int res=1;
            for(int i=0;i<min(n,m)&&x-i>=0&&x+i<m&&y-i>=0&&y+i<n;i++){
                if(a[x+i][y]==a[x][y]&&a[x][y+i]==a[x][y]&&a[x-i][y]==a[x][y]&&a[x][y-i]==a[x][y]&&a[x-i][y-i]==a[x][y]&&a[x-i][y+i]==a[x][y]&&a[x+i][y-i]==a[x][y]&&a[x+i][y+i]==a[x][y]){
                    bool ok=true;
                    for(int j=x-i;j<=x+i;j++){
                        if(a[j][y-i]!=a[x][y]||a[j][y+i]!=a[x][y]){
                            ok=false;
                            break;
                        }
                    }
                    if(!ok){
                        break;
                    }
                    for(int j=y-i;j<=y+i;j++){
                        if(a[x-i][j]!=a[x][y]||a[x+i][j]!=a[x][y]){
                            ok=false;
                            break;
                        }
                    }
                    if(!ok){
                        break;
                    }
                    res=max(res,2*i+1);
                }
                else{
                    break;
                }
            }
            cout<<res<<"\n";
        }
    }
    return 0;
}