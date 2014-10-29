#include<iostream>
using namespace std;

int c,m,n;
double dp[2][101];

int main(){
    while(cin>>c>>n>>m&&c){
                           if(m>c||(m+n)%2||m>n){
                                                 cout << "0.000" << endl;
                                                 continue;
                           }
                           
                           if(n>1001)
                                     n = n%2?1001:1000;
                           memset(dp,0,sizeof(dp));
                           dp[0][0] = 1.0;
                           for(int i = 1; i <= n; i++)
                                   for(int j = 0; j <= i&&j<=c; j++){
                                           dp[i%2][j] = 0.0;
                                           if((i+j)%2)
                                                      continue;
                                           if(j>0)
                                                  dp[i%2][j] += dp[1-i%2][j-1]*((c-j+1.)/c);
                                           if(j+1<=i-1)
                                                     dp[i%2][j] += dp[1-i%2][j+1]*((j+1.0)/c);
                                           //cout << dp[i%2][j] << endl;
                                   }
                           printf("%.3lf\n", dp[n%2][m]);
    }
}
                           
