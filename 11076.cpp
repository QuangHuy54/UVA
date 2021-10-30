#include<iostream>
#include<cstring>
using namespace std;
typedef unsigned long long ull;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull frac[13];
    frac[0]=1;
    for(int i=1;i<=12;i++){
        frac[i]=frac[i-1]*i;
    }
    int n;
    ull x,C;
    int a[10];
    while(cin>>n&&n){
        memset(a,0,sizeof(a));
        C=frac[n];
        ull sum=0;
        ull temp1=1;
        for(int i=0;i<n;i++){
            cin>>x;
            a[x]++;
            sum+=x;
            temp1=temp1*10+1;
        }
        temp1/=10;
        for(int i=0;i<=9;i++){
            C/=frac[a[i]];
        }
        cout<<C*sum/n*temp1<<"\n";
    }
    return 0;
}