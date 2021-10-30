#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int hole[6]={1,5,3,2,4,0};
char picture[6]={'A','D','J','K','S','W'};
int res[205];
bool visited[203][203];
char a[204][204];
int h,w,n,c=0;
string binary(int a){
    string s="";
    for(int i=0;i<4;i++){
        if(a&(1<<i)){
            s+="1";
        }
        else{
            s+="0";
        }
    }
    reverse(s.begin(),s.end());
    return s;
}
string convert(char a){
    if(a=='a') return binary(10);
    if(a=='b') return binary(11);
    if(a=='c') return binary(12);
    if(a=='d') return binary(13);
    if(a=='e') return binary(14);
    if(a=='f') return binary(15);
    return binary(a-'0');
}
void floodfill(int r,int c,bool flag){
    if((!flag&&a[r][c]=='1')||r<0||c<0||r>h+1||c>w+1||visited[r][c]){
        return;
    }
    if(flag&&a[r][c]=='0'){
        flag=false;
        res[n]++;
    }
    visited[r][c]=true;
    floodfill(r+1,c,flag);
    floodfill(r-1,c,flag);
    floodfill(r,c+1,flag);
    floodfill(r,c-1,flag);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string temp,bin;
    while(cin>>h>>w&&(h||w)){
        w=(w*4);
        for(int i=0;i<=w+1;i++){
            a[0][i]='0';
            a[h+1][i]='0';
            visited[0][i]=false;
            visited[h+1][i]=false;
        }
        for(int i=0;i<=h+1;i++){
            a[i][0]='0';
            a[i][w+1]='0';
            visited[i][0]=false;
            visited[i][w+1]=false;
        }
        for(int i=1;i<=h;i++){
            cin>>temp;
            for(int j=0;j<temp.size();j++){
                bin=convert(temp[j]);
                for(int k=0;k<4;k++){
                    a[i][j*4+k+1]=bin[k];
                    visited[i][j*4+k+1]=false;
                }
            }
        }
        memset(res,0,sizeof(res));
        floodfill(0,0,false);
        n=0;
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                if(!visited[i][j]&&a[i][j]=='1'){
                    floodfill(i,j,true);
                    n++;
                }
            }
        }
        cout<<"Case "<<++c<<": ";
        for(int i=0;i<6;i++){
            for(int j=0;j<n;j++){
                if(res[j]==hole[i]){
                    cout<<picture[i];
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}