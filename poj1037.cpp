#include<iostream>
using namespace std;

__int64 dp[21][21][2];
bool used[21];

void init(){
     memset(dp,0,sizeof(dp));
     dp[1][1][0] = dp[1][1][1] = 1;
     for(int len = 2; len <= 20; len++){
             for(int st = 1; st <= len; st++){
                     for(int j =1; j <st; j++)
                             dp[st][len][1]+=dp[j][len-1][0];//1 down 0 up
                     for(int j = st; j < len; j++)
                             dp[st][len][0]+=dp[j][len-1][1];
             }
     }
}
             
void decorfence(int n, __int64 k){
     memset(used,0,sizeof(used));
     int r=n,l=1,up;
     for(int i = 1; i <= n; i++){
             if(k>dp[i][n][1]) k-=dp[i][n][1];
             else{
                 used[i] = 1;
                 l = 1, r = i-1;
                 up = 0;
                 cout << i;
                 break;
             }
             if(k>dp[i][n][0]) k-=dp[i][n][0];
             else{
                  l = i+1, r = n;
                  up = 1;
                  used[i] = 1;
                  cout << i;
                  break;
             }
     }
     
     
     for(int len = n-1; len>=1; len--){
             int num = 0;
             for(int i = 1; i < l; i++) if(used[i]==0) num++;
             for(int i = l; i <= r; i++){
                     if(used[i]) continue;
                     num++;
                     //cout << dp[num][len][up] << endl;
                     if(k<=dp[num][len][up]){
                                              cout << " " << i;
                                              used[i] = 1;
                                              up = 1-up;
                                              if(up==0) l = 1, r = i-1;
                                              else l = i+1, r = n;
                                              break;
                     }
                     else k-=dp[num][len][up];
             }
     }
}

int main(){
    int n,t;
    __int64 k;
    init();
    //cout << perm[4][0] << " " << perm[4][1] << endl;
    cin >> t;
    while(t--){
               cin>>n>>k;
               decorfence(n,k);
               cout << endl;
    }
                     
}
