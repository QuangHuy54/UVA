#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k=1000000;
    int limit=k*2000;
    for(int a=1;a<=2000;a++){
        if(a*a*a*a>limit){
            break;
        }
        for(int b=a;b<=2000-a;b++){
            if(a*b*b*b>limit){
                break;
            }
            else{
                for(int c=b;c<=2000-a-b;c++){
                    if(a*b*c*c>limit){
                        break;
                    }
                    else{
                        int t=a+b+c;
                        int v=a*b*c;
                        if((v-k)!=0){
                            if((t*k)%(v-k)!=0){
                            continue;
                        }
                        int d=(t*k)/(v-k);
                        if(d<c||(a*b*c*d)>limit||(a+b+c+d)>2000){
                            continue;
                        }
                        cout<<setprecision(2)<<fixed<<a/100.0<<" "<<b/100.0<<" "<<c/100.0<<" "<<d/100.0<<"\n";
                        }
                        
                    }
                }
            }
        }
    }
    return 0;
}