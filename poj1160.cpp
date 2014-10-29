#include<iostream>

using namespace std;

int dp[301][31][301],n,np,a[301],rdis[301][301], ldis[301][301];


int main(){
    while(cin >> n >> np){
        for(int i = 1; i <= n; i++)
                cin >> a[i];
        memset(ldis,0,sizeof(ldis));
        memset(rdis,0,sizeof(rdis));
        for(int i = 1; i <= n; i++)
                for(int j = i+1; j <= n; j++){
                        rdis[i][j] = rdis[i][j-1]+a[j]-a[i];
                        //cout << rdis[i][j] << endl;
                } 
        
        for(int i = 1; i <= n; i++)
                for(int j = i-1; j>=1; j--)
                        ldis[j][i] = ldis[j+1][i]+a[i]-a[j];
                        
        
        dp[1][0][0] = dp[1][1][1] = 0;
        for(int i = 2; i <= n; i++){
                for(int k = 1; k <= i; k++){
                        dp[i][1][k] = ldis[1][k]+rdis[k][i];
                        //cout << i << " " << 1 << " " << k << " " << ldis[1][k] << " " << rdis[k][i] <<" "<< dp[i][1][k] << endl;
                }
                        
                for(int j = 2; j <= min(i,np); j++)
                        for(int k = j; k<=i; k++){
                                //if(i==5&&j==2&&k==4) cout << i << " " << j << " " << k << endl;
                                int t = 10000000;
                                for(int m = j-1; m <=k-1;m++){
                                        int inter = m+1, mid = (a[m]+a[k])/2;
                                        while(a[inter]<mid) inter++;
                                        //if(i==5&&j==2&&k==4) cout << dp[k-1][j-1][m]+rdis[m][inter-1]+ldis[inter][k] << " " << t << endl;
                                        t = min(t,dp[m][j-1][m]+rdis[m][inter-1]+ldis[inter][k]);
                                }
                                dp[i][j][k] = t+rdis[k][i];
                                //cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
                        }
        }
        int res = 1000000;
        for(int i = np; i <= n; i++)
                res = min(res,dp[n][np][i]);
        cout << res << endl;
    }
}
    
    
