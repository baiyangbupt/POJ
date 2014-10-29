#include<iostream>
#include<iomanip>
using namespace std;

int list[101], waylist[100001], m, n;
float price[100001],dp[101];

int main(){
    while(cin >> m >> n &&(m||n)){
              for(int i = 1; i <= m; i++)
                      cin >> list[i];
              for(int i = 1; i <= n; i++)
                      cin >> waylist[i] >> price[i];
              
              for(int i = 1; i <= m; i++)
                      dp[i] = -1;
              dp[0] = 0;
              for(int i = 1; i <= n; i++){
                      for(int j = m; j >= 1; j--)
                              if(waylist[i]==list[j]&&dp[j-1]>=0)
                                                      dp[j]= dp[j]==-1?dp[j-1]+price[i]:min(dp[j],dp[j-1]+price[i]);
                      }
              
              if(dp[m]<0)
                         cout << "Impossible" << endl;
              else
                  cout <<setiosflags(ios::fixed) << setprecision(2) << dp[m] << endl;
    }
}
