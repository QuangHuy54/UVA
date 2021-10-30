#include<iostream>
#include<vector>
#include<cmath>
#include<stdio.h>
#include<cstring>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<algorithm>
#include<string>
#include<cstring>
#include<unordered_map>
using namespace std;
typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
const int array_size=200002;
int cnt;
void merge(int a[],int start,int end, int mid){
    int sizeL=mid-start+1;
    int sizeR=end-mid;
    int L[sizeL],R[sizeR];
    for(int i=0;i<sizeL;i++){
        L[i]=a[start+i];
    }
    for(int i=0;i<sizeR;i++){
        R[i]=a[mid+i+1];
    }
    int left=0,right=0,ar=start;
    while(left<sizeL&&right<sizeR){
        if(L[left]<R[right]){
            a[ar++]=L[left++];
        }
        else{
            a[ar++]=R[right++];
            cnt+=sizeL-left;
        }
    }
    while(left<sizeL){
        a[ar++]=L[left++];
    }
    while(right<sizeR){
        a[ar++]=R[right++];
    }
}
void merge_sort(int a[],int start,int end){
    if(start>=end){
        return;
    }
    int mid=(start+end)/2;
    merge_sort(a,start,mid);
    merge_sort(a,mid+1,end);
    merge(a,start,end,mid);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int a[200002];
    while(cin>>n&&n){
        cnt=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        merge_sort(a,0,n-1);
        if(cnt%2==0){
            cout<<"Carlos"<<"\n";
        }
        else{
            cout<<"Marcelo"<<"\n";
        }
    }
    return 0;
}