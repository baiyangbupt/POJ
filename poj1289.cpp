#include<iostream>
#include<cmath>
using namespace std;

unsigned long long hei,num;

int main(){
    while(cin>>hei>>num){
                         unsigned long long l,m,n;
                         if(num==1){
                                    l = 0;
                                    while(hei!=1){
                                                  hei/=2;
                                                  l++;
                                    }
                                    
                                    cout << l << " " << (unsigned long long)pow(2,double(l+1))-1 << endl;
                         }
                         else{
                              l = 1;
                              while(1){
                                       m = pow(hei,1./l)+0.999999;
                                       n = pow(num,1./l)+0.999999;
                                       if(m==n+1&&hei==(unsigned long long)pow(m,(double)l)&&num==(unsigned long long)pow(n,(double)l))
                                                                                                   break;
                                       l++;
                              }
                              cout << (num-1)/(n-1) << " " << hei*(n+1)-num*n << endl;
                         }
    }
}
                              
                                    
