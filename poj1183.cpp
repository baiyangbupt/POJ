#include<iostream>
#include<cmath>
using namespace std;

unsigned long a;
int main(){
           cin >> a;
                  unsigned long m,n;
                  for(m = a; m >= 1; m--)
                        if((a*a+1)%m==0)
                                        break;
                  n = (a*a+1)/m;
                  unsigned long res = 2*a+m+n;
                  cout << res << endl;
    }
