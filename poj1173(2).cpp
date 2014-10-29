#include<iostream>
#include<string>
using namespace std;

int dp[35][35],n,k,m,s;

int main(){
    while(cin>>n>>k>>m){
                        memset(dp,0,sizeof(dp));
                        for(int i = 1; i <= m; i++)
                                dp[i][1] = 1;
                        for(int i = 2; i <= n; i++)
                                for(int j = 1; j <= min(k,i); j++){
                                        for(int k = 1; i-k>=0&&k<=m; k++)
                                                dp[i][j] += dp[i-k][j-1];
                                        //cout << i << " " << j << " " << dp[i][j] << endl;
                                }
                        cout << dp[n][k] << endl;
                        cin >> s;
                        string t;
                        for(int j = 0; j < s; j++){
                                cin >> t;
                                int res = 0,resi_part = k;
                                int zeros = 0, i = 1, ones = 0;
                                while(i<t.size()){
                                                  if(t[i]=='0'){
                                                                zeros++, ones;
                                                                if(t[i]!=t[i-1]) resi_part--;
                                                  }
                                                  else{
                                                       if(t[i-1]=='0'){
                                                                       resi_part--;
                                                                       if(zeros<m){
                                                                                   int temp = i;
                                                                                   while(temp-i+1+zeros<=m){
                                                                                                           res+=dp[n-1-temp-1+1][resi_part];
                                                                                                           temp++;
                                                                                   }
                                                                       }
                                                       }
                                                       else{
                                                            res += dp[n-1-i+1][resi_part-1];
                                                       }
                                                       zeros = 0;
                                                  }
                                                  i++;
                                }
                                cout << res << endl;
                        }
                                
    }
}
