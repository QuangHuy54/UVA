#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ncows,ncars,nshow;
    while(cin>>ncows>>ncars>>nshow){
        int numerator=ncows*ncars+ncars*ncars-ncars;
        int denominator=(ncars+ncows)*(ncars+ncows-nshow-1);
        cout<<setprecision(5)<<fixed<<(double)numerator/denominator<<"\n";
    }
}