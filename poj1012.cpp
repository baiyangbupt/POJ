#include<iostream>
using namespace std;

int ans[20],res[20];

int main(){
    int n,k;
    while(cin>>k&&k){
                     if(res[k]>0){
                                  cout << res[k] << endl;
                                  continue;
                     }
                     
                     int n = 2*k,m;
                     for(m = k+1; ; m++){
                             ans[0] = 0;
                             int i;
                             for(i = 1; i <= k; i++){
                                     ans[i] = (ans[i-1]+m-1)%(n-i+1);
                                     if(ans[i]<k)
                                                 break;
                             }
                             if(i==k+1)
                                       break;
                     }
                     res[k] = m;
                     cout << m << endl;
    }
}
                     
