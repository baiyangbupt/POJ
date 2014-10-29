#include <iostream>

using namespace std;

bool prime(int x){
     if(x<=1) return false;
     for(int i = 2; i*i<=x; i++)
             if(x%i==0) return false;
     return true;
}

int main(){
    int a,d,n;
    while(cin >> a >> d >> n){
              if(a==0&&d==0&&n==0) break;
              int num = 0;
              while(num<n){
                           if(prime(a))
                                           num++;
                           a+=d;
              }
              cout << a-d << endl;
              }
    }
