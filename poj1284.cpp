#include<iostream>
using namespace std;

int oula[65537];

int caoula(int n){
    if(oula[n]>0) return oula[n];
    int res = 1;
    for(int i = 2; i*i <= n; i++)
            if(n%i==0){
                       n/=i;
                       res*=(i-1);
                       while(n%i==0){
                                     n/=i;
                                     res*=i-1;
                       }
            }
    
    if(n>1) res*=n-1;
    return oula[n] = res;
}


int main(){
    int n;
    while(cin>>n)
                 cout << caoula(n-1) << endl;
}
