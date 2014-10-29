#include<iostream>
#include<string>
using namespace std;

__int64 dp[55][55];
int n,m;
bool grid[55][55];

__int64 gcd(__int64 x, __int64 y){
          if(x==0) return y;
          if(x>y) return gcd(y,x);
          return gcd(y%x,x);
}

int main(){
    while(cin >> n >> m){
              char c;
              int i = 0,j = 0;
              while(i<n){
                         if(j==i+1){
                                    i++;
                                    j = 0;
                                    continue;
                         }
                         while(cin>>c&&(c!='.'&&c!='*'));
                         grid[i][j] = c=='.'?0:1;
                         j++;
              }
              
              for(int j = 0; j <= n; j++)
                      grid[n][j] = 1;
                      
              memset(dp,0,sizeof(dp));
              if(grid[0][0]==0)
                                dp[2][1] += 4;
              dp[0][0] = 1;
              
              for(int i = 1; i <= n; i++){
                      for(int j = 0; j <= i; j++){
                              if(grid[i][j]!=0){
                                                dp[i][j] += (grid[i-1][j]==0?0:dp[i-1][j]) + (grid[i-1][j-1]==0||j==0?0:dp[i-1][j-1]);
                              }
                              else
                                  dp[i+2][j+1] += ((grid[i-1][j]==0?0:dp[i-1][j]) + (grid[i-1][j-1]==0||j==0?0:dp[i-1][j-1]))*4;
                                  
                              cout << dp[i][j] << " ";
                      }
                      cout << endl;
              }
              
              __int64 total = (1<<(n)), fac = gcd(total,dp[n][m]);
              __int64 res = dp[n][m]/fac;
              cout << res << "/";
              res = total/fac;
              cout << res << endl;
    }
}
