#include<iostream>
using namespace std;


int a[301], dp[301][31], sum[301][301],n,np;

int main(){
    while(cin >> n >> np){
        for(int i = 1; i <= n; i++)
                cin >> a[i];
        
        for(int i = 1; i <= n; i++)
                sum[i][i] = 0;
                
        for(int i = 1; i <= n; i++)
                for(int j = i+1; j <= n; j++)
                        sum[i][j] = sum[i][j-1] + a[j]-a[(i+j)/2];
        
        for(int i = 1; i <= n; i++){
                dp[i][1] = sum[1][i];
                for(int j = 2; j <= min(i,n); j++){
                        int t = 100000;
                        for(int k = j-1; k <= i-1; k++)
                                t = min(t,dp[k][j-1]+sum[k+1][i]);
                        dp[i][j] = t;
                }
        }
        
        cout << dp[n][np] << endl;
    }
}
