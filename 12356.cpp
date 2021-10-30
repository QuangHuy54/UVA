#include<iostream>
using namespace std;
int main(){
    int S,B,L,R;
    int left[100005];
    int right[100005];
    while(scanf("%d %d",&S,&B),(S||B)){
        for(int i=1;i<=S;i++){
            left[i]=i-1;
            right[i]=i+1;
        }
        while(B--){
            cin>>L>>R;
            if(left[L]<1){
                cout<<"* ";
            }
            else{
                cout<<left[L]<<" ";
            }
            if(right[R]>S){
                cout<<"*";
            }
            else{
                cout<<right[R];
            }
            left[right[R]]=left[L];
            right[left[L]]=right[R];
            cout<<"\n";
            }
            cout<<"-"<<"\n";
        }
    return 0;
}