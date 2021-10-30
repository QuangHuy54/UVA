#include<iostream>
using namespace std;
int n,q,m,dx,dy,x,y,c=0,xtemp1,ytemp1,xtemp2,ytemp2,resx,resy,res,temp,tx,ty;
int sum[2048][2048];
void rotate(int x, int y, int &tx, int &ty) {
    tx = x+y;
    ty= dy+y-x;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>dx>>dy>>n>>q){
        if(!(dx||dy||n||q)){
            break;
        }
        for(int i=1;i<=dx+dy;i++){
            for(int j=1;j<=dy+dx;j++){
                sum[i][j]=0;
            }
        }
        for(int i=0;i<n;i++){
            cin>>y>>x;
            rotate(x,y,tx,ty);
            sum[tx][ty]++;
        }
        for(int i=1;i<=dx+dy;i++){
            for(int j=1;j<=dy+dx;j++){
                if(i>1) {sum[i][j]+=sum[i-1][j];}
                if(j>1) {sum[i][j]+=sum[i][j-1];}
                if(i>1&&j>1) {sum[i][j]-=sum[i-1][j-1];}
            }
        }
        cout<<"Case "<<++c<<":"<<"\n";
        while(q--){
            cin>>m;
            res=0;
            resx=1;
            resy=1;
            for(int i=1;i<=dy;i++){
                for(int j=1;j<=dx;j++){
                    rotate(i,j,tx,ty);
                    xtemp1=tx>m ? tx-m : 1; 
                    ytemp1=ty>m ? ty-m : 1;
                    xtemp2=(dx+dy-tx)>m ? tx+m : dx+dy;
                    ytemp2=(dx+dy-ty)>m ? ty+m : dy+dx;
                    temp=sum[xtemp2][ytemp2];
                    if(xtemp1>1){temp-=sum[xtemp1-1][ytemp2];}
                    if(ytemp1>1){temp-=sum[xtemp2][ytemp1-1];}
                    if(xtemp1>1&&ytemp1>1){temp+=sum[xtemp1-1][ytemp1-1];}
                    if(temp>res){
                        res=temp;
                        resx=j;
                        resy=i;
                    }
                }
            }
            cout<<res<<" ("<<resx<<","<<resy<<")"<<"\n";
        }
    }
    return 0;
}