#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
bool visited[52];
double p[52];
double res[52];
int n,r;
double sum;
void combination(int index,int size){
    if(size==r){
        double temp=1.0;
        for(int i=0;i<n;i++){
            if(visited[i]){
                temp*=p[i];
            }
            else{
                temp*=(1-p[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(visited[i]){
                res[i]+=temp;
            }
        }
        sum+=temp;
    }
    for(int i=index;i<n;i++){
        if(!visited[i]){
            visited[i]=true;
            combination(i+1,size+1);
            visited[i]=false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=0;
    while(cin>>n>>r&&(n||r)){
        for(int i=0;i<n;i++){
            cin>>p[i];
        }
        memset(visited,0,sizeof(visited));
        memset(res,0,sizeof(res));
        sum=0;
        combination(0,0);
        cout<<"Case "<<++t<<":"<<"\n";
        for(int i=0;i<n;i++){
            cout<<setprecision(6)<<fixed<<res[i]/sum<<"\n";
        }
    }
    return 0;
}