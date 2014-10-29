#include<iostream>
using namespace std;

int a[33],n;

int main(){
    while(cin>>n&&n){
                  int total = 0;
                  
                  for(int i = 0; i < n; i++){
                          cin >> a[i];
                          total += a[i];
                  }
                  if(total%2){
                              cout << "No equal partitioning." << endl;
                              continue;
                  }
                  int tt = 0,res = -1;
                  
                  for(int j = 0; j < n; j++){
                          tt+=a[j];
                          if(tt==total/2){
                                          res = j;
                                          break;
                          }
                          else if(tt>total/2)
                               break;
                  }
                  if(res>=0)
                             cout << "Sam stops at position " << res+1 << " and Ella stops at position " << (res+1)%n+1<<"." << endl;
                  else
                      cout << "No equal partitioning." << endl;
    }
}
