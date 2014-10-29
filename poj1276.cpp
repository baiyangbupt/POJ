#include<iostream>
using namespace std;

bool dp[100001];
int n, a[11], num[11], cash, d[150];

int main(){
    while(cin>>cash){
                     cin >> n;
                     for(int i = 1; i <= n; i++)
                             cin >> num[i] >> a[i];
                     
                     int nn = 0;
                     for(int i = 1; i <= n; i++)
                             if(a[i]!=0){
                                         int base = a[i], bit = 1;
                                         while(num[i]>=bit){
                                                            num[i]-=bit;
                                                            d[nn++] = base;
                                                            base*=2;
                                                            bit<<=1;
                                         }
                                         if(num[i]>0)
                                                  d[nn++] = a[i]*num[i];
                             }
                                               
                             
                     memset(dp,0,sizeof(dp));
                     int m = 0;
                     dp[0] = 1;
                     for (int i = 0; i < nn; i++){
                         //cout << d[i];
                             m = min(cash-d[i],m);
                             for(int k = m; k>=0; k--)
                                     if(dp[k])
                                              dp[k+d[i]] = 1;
                             m = m+d[i];
                     }
                     
                     for(int i = min(cash,m); i >= 0; i--)
                             if(dp[i]){
                                       cout << i << endl;
                                       break;
                             }
    }
}
                             
                         
                  
