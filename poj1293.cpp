#include<iostream>
using namespace std;

bool dp[2001];
int a[2001], m,l,n, path[2001];

int main(){
    while(cin >> m >> l&&(m||l)){
              int sum = 0;
              cin >> n;
              for(int i = 0; i < n; i++){
                      cin >> a[i];
                      sum += a[i];
              }
              if(sum>m+l){
                          cout << "Impossible to distribute" << endl;
                          continue;
              }
              
              memset(dp,0,sizeof(dp));
              memset(path,-1,sizeof(path));
              dp[0] = 1;
              int Max = 0;
              for(int i = 0; i < n; i++){
                      for(int j = Max; j >= 0; j--)
                              if(dp[j]&&dp[j+a[i]]==0)
                                       dp[j+a[i]] = 1, path[j+a[i]] = i;
                      Max = min(Max+a[i],m);
              }
              
              int p = m;
              while(dp[p]==0) p--;
              
              if(sum-p>l){
                          cout << "Impossible to distribute" << endl;
                          continue;
              }
              
              int res[1000],top = 0;
              while(p>0){
                         res[top++] = path[p]+1;
                         p -= a[path[p]];
              }
              cout << top;
              for(int i = top-1; i>=0; i--)
                      cout << " " << res[i];
              cout << endl;
    }
}
              
    
