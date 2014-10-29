#include<iostream>
using namespace std;


int n,m,r,num[51];
unsigned long long dp[51][51];

int main(){
    int nc = 1;
    while(cin>>n>>m&&(n||m)){
                             cout << "Case " << nc++ << ":" << endl;
                             int Max = -1, Min = 100;
                             memset(num,0,sizeof(num));
                             memset(dp,0,sizeof(dp));
                             for(int i = 0; i < n; i++){
                                     int t;
                                     cin >> t;
                                     num[t]++;
                                     Max = max(t,Max);
                                     Min = min(t,Min);
                             }
                             
                             int cnt = num[Min];
                             dp[Min][0] = 1;
                             for(int i = 1; i <= cnt; i++)
                                     dp[Min][i] = 1;
                             for(int i = Min+1; i <= Max; i++){
                                     dp[i][0] = 1;
                                     cnt+=num[i];
                                     for(int j = 1; j <= cnt; j++){
                                             dp[i][j] += dp[i-1][j];
                                             for(int k = 1; k <= num[i]; k++)
                                                     dp[i][j] += dp[i-1][j-k];
                                     }
                             }
                             
                             for(int i = 0; i < m; i++){
                                     cin >> r;
                                     cout << dp[Max][r] << endl;
                             }
    }
}
                             
