#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,x1,x2,x3,x4,x5,x,y,sum1,sum2,sum3,sum4,sum5,sum;
    cin>>t;
    int n,a[26][26];
    while(t--){
        cin>>n;
        memset(a,0,sizeof(a));
        int res[5];
        for(int i=0;i<n;i++){
            cin>>x>>y;
            cin>>a[x][y];
        }
        int minl=INT_MAX;
        for(int i=0;i<=20;i++){
            for(int j=i+1;j<=21;j++){
                for(int k=j+1;k<=22;k++){
                    for(x=k+1;x<=23;x++){
                        for(y=x+1;y<=24;y++){
                            sum=0;
                            for(int temp1=0;temp1<5;temp1++){
                                for(int temp2=0;temp2<5;temp2++){
                                    sum1=abs(temp1-(i/5))+abs(temp2-(i%5));
                                    sum2=abs(temp1-(j/5))+abs(temp2-(j%5));
                                    sum3=abs(temp1-(k/5))+abs(temp2-(k%5));
                                    sum4=abs(temp1-(x/5))+abs(temp2-(x%5));
                                    sum5=abs(temp1-(y/5))+abs(temp2-(y%5));
                                    sum+=a[temp1][temp2]*min(sum1,min(sum2,min(sum3,min(sum4,sum5))));
                                }
                            }
                            if(sum<minl){
                                minl=sum;
                                res[0]=i;
                                res[1]=j;
                                res[2]=k;
                                res[3]=x;
                                res[4]=y;
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<5;i++){
            cout<<res[i];
            if(i==4){
                cout<<"\n";
            }
            else{
                cout<<" ";
            }
        }
    }
    return 0;
}