#include<iostream>
using namespace std;

__int64 n,dp[1000][1000];

__int64 dfs(int n, int i){
    if(dp[n][i]>=0) return dp[n][i];
    if(n==0) return dp[n][i] = 1;
    if(n==i) return dp[n][i] = 1;
    if(n<i) return dp[n][i] = 0;
    
    __int64 res = 0,sum = n-2*i;
    if(sum==0) return dp[n][i] = 1;
    for(int j = i; j<=sum; j++)
            res += dfs(sum,j);
    
    if(res<0) cout << n << " " << i<< " " << res << endl;
    return dp[n][i] = res;
}

int main(){
    memset(dp,-1,sizeof(dp));
    dp[0][0] = dp[1][1] = dp[1][0] = 1;
    
    
    while(cin>>n&&n){
                     __int64 res = 0;
                     for(int i = 1; i <= n; i++){
                             //cout << dfs(n,i) << endl;
                             res+=dfs(n,i);
                     }
                             
                     cout << n << " " <<res << endl;
    }
}
    
