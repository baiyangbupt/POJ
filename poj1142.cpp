#include<iostream>
#include<map>

using namespace std;
bool prime;

int test(int &n){
    prime = 1;
    int i;
    for(i = 2; i*i <=n; i++)
            if(n%i==0){
                      n/=i;
                      prime = 0;
                      break;
            }
    return i;
}

int sum(int n){
    int res = 0;
    while(n)
            res+=n%10, n/=10;
    return res;
}

int main(){
    int n;
    while(cin>>n&&n){
                     int j = n+1;
                     for(; ; j++){
                          int t = j, s1 = sum(j), s2 = 0;
                          s2+=sum(test(t));
                          if(prime) continue;
                          while(t!=1){
                                      int temp = sum(test(t));
                                      if(prime){
                                                s2+=sum(t);
                                                break;
                                      }
                                      s2+=temp;
                          }
                          if(s1==s2)
                                    break;
                     }
                     cout << j << endl;
    }
}
                          
