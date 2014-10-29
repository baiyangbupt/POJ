#include<iostream>
using namespace std;

int n,a[100][100],dp[100][100];

int main(){
     while(cin>>n){
                   for(int i = 0; i < n; i++)
                           for(int j = 0; j <= i; j++)
                                   cin >> a[i][j];
                   memset(dp,0,sizeof(dp));
                   dp[0][0] = a[0][0];
                   
                   for(int i = 1; i < n; i++){
                           dp[i][0] = dp[i-1][0]+a[i][0];
                           for(int j = 1; j <= i; j++)
                                   dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + a[i][j];
                   }
                   int res = 0;
                   for(int i = 0; i < n; i++)
                           res = max(res,dp[n-1][i]);
                   
                   cout << res << endl;
     }
}
