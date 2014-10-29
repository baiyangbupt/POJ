#include<iostream>
using namespace std;

long long dp[201][201],tdp[201][201];
int n,k;

int main(){
    while(cin>>n>>k&&(n||k)){
                     memset(tdp,0,sizeof(tdp));
                     memset(dp,0,sizeof(dp));
                     
                     for(int i = 1; i <= n; i++)
                             tdp[i][i] = dp[i][i] = 1;
                     
                     for(int i = 2; i <= k; i++){
                             for(int j = 1; j <= n; j++)
                                     for(int l = 1; l*i<=j; l++){
                                             tdp[j][l] = 0;
                                             for(int m = l; m*(i-1) <= j-l; m++)
                                                     tdp[j][l]+=dp[j-l][m];
                                     }
                             for(int j = 1; j <= n; j++)
                                     for(int l = 1; l*i<=j; l++)
                                             dp[j][l] = tdp[j][l];
                     }
                     
                     lo res = 0;
                     for(int i = 1; i*k<=n; i++)
                             res += dp[n][i];
                     cout << res << endl;
                     
    }
}
