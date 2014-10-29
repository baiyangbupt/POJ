#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


int main(){
    int dp[21][801], path[21][801], a[201], b[201], n, m, count=1;
    
    vector<int> res;
    while(cin >> n >> m&&(n||m)){
     //         cout << m << endl;
             for(int i = 1; i <= n; i++)
                     cin >> a[i] >> b[i];
             
             memset(dp,-1,sizeof(dp));
             memset(path,0,sizeof(path));
             
             int level = 20*m;
             dp[0][level] = 0;
             
             for(int i = 1; i <= m; i++){
                     int h = level+(i-1)*20, l = level-(i-1)*20;
                     for(int j = l; j<=h; j++)
                             if(dp[i-1][j]>=0)
                                              for(int k = 1; k <= n; k++){
                                                      if(dp[i][j+a[k]-b[k]]<dp[i-1][j]+a[k]+b[k]){
                                                          bool used = 0;
                                                          int p = path[i-1][j], t = j, idx = i-1;
                                                          while(idx>0&&p>0){
                                                                   if(p==k){
                                                                            used = 1;
                                                                            break;
                                                                   }
                                                                   idx--, t-=a[p]-b[p];
                                                                   p = path[idx][t];
                                                          }
                                                          if(used) continue;
                                                      
                                                          dp[i][j+a[k]-b[k]] = dp[i-1][j]+a[k]+b[k];
                                                          path[i][j+a[k]-b[k]] = k;
                                                      }
                                              }
             }
             
             /*for(int i = 0; ; i++){
                     if(i==0&&dp[m][level]>0||dp[m][level+i]>dp[m][level-i]){
                                                       int p = path[m][level+i], t = level+i, idx = m;
                                                       while(idx>0&&p>0){
                                                                    res.push_back(p);
                                                                    idx--, t-=a[p]-b[p];
                                                                    p = path[idx][t];
                                                       }
                                                       break;
                     }
                     else if(dp[m][level-i]>dp[m][level+i]){
                                                            int p = path[m][level-i], t = level-i, idx = m;
                                                       while(idx>0&&p>0){
                                                                    res.push_back(p);
                                                                    idx--, t-=a[p]-b[p];
                                                                    p = path[idx][t];
                                                       }
                                                       break;
                     }
             }*/
             int i = 0;
             for(i = 0; dp[m][level+i]<0&&dp[m][level-i]<0; i++);
             i = dp[m][level+i]>dp[m][level-i]?level+i:level-i;
             
             int idx = m, t = i;
             while(idx>0){
                        res.push_back(path[idx][t]);
                        t-=a[path[idx][t]]-b[path[idx][t]];
                        idx--;
             }
             sort(res.begin(),res.end());
             cout << "Jury #" <<count++ << endl; 
             cout << "Best jury has value " << (dp[m][i]+i-level)/2 << " for prosecution and value " << (dp[m][i]-i+level)/2 << " for defence:" << endl; 
             for(int i = 0; i < res.size(); i++)
                     cout << " " << res[i]; 
             cout << endl;
             res.clear();
             }
             system("pause");
    }
