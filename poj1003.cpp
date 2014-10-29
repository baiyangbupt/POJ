#include<iostream>
using namespace std;

int main(){
    int n=1;
    float sum,l;
    while(cin>>l){
                  n = 1;
                  if(l==0.00)
                             break;
                  sum = 0.00;
                  while(sum<l) sum+=1./(n+1), n++;
                  cout << n-1 << " card(s)" << endl;
    }
}
