#include<iostream>
#include<cmath>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    long long res1,res2,temp,mid;
    while(cin>>n&&n){
        if(n==1){
            cout<<"1 1"<<"\n";
        }
        else{
            temp=ceil(sqrt((long double)n));
            mid=((temp-1)*(temp-1)+1+temp*temp)/2;
            if(n==mid){
                res1=res2=temp;
            }
            else if(n>mid){
                res2=temp;
                res1=temp-(n-mid);
            }
            else{
                res1=temp;
                res2=temp-(mid-n);
            }
            if(temp%2==0){
                swap(res1,res2);
            }
            cout<<res1<<" "<<res2<<"\n";
        }
    }
    return 0;
}