#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int a=6;a<=200;a++){
        for(int b=2;b<=a;b++){
            for(int c=b+1;c<=a;c++){
                if(b*b*b+c*c*c>=a*a*a){
                    break;
                }
                else{
                    for(int d=c+1;d<=a;d++){
                        if(b*b*b+c*c*c+d*d*d==a*a*a){
                            cout<<"Cube = "<<a<<", Triple = ("<<b<<","<<c<<","<<d<<")"<<"\n";
                        }
                    }
                }
                /*int k=a*a*a-b*b*b-c*c*c;
                if(k<=c*c*c||c*c*c+b*b*b>a*a*a){
                    break;
                }
                else{
                    int v=cbrt(k);
                    if(v*v*v==k){
                        cout<<"Cube = "<<a<<", Triple = ("<<b<<","<<c<<","<<v<<")"<<"\n";
                    }
                }
                */
            }
        }
    }
    return 0;
}