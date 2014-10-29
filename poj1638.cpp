#include<iostream>
using namespace std;
int main()
{int a[10], t;
void f(int);
cin>>t;cout<<t<<endl;
for(int i=1;i<=t;i++)
cin>>a[i]; 
for(int i=1;i<=t;i++)
f(a[i]);
}
void f(int n){
int prime(int n);
int d=0,b=0,i=1,m,j;

while(n>=1)
{if(n>=1&&n<=3){if(i%2==1){d=d+1;n=n-1;i++;f(n);}
                else {b=b+1;n=n-1;i++;f(n);}}
else {if(prime(n)==1){if(i%2==1)d=d+1,n=n-1,i++,f(n);}
      else{j=i,i++,m=n,n=prime(n),f(n);
           i=j,i++,n=m/prime(n),f(n);}}
}
cout<<d<<"   "<<b<<endl;}
int prime(int n)
{int c=1;
for(int i=2;i<=n;i++)
{if(n%i==0)c=i;break;}
return c;}
