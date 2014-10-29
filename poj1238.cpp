#include<iostream>
#include<queue>
using namespace std;

struct node{
       int l,current;
       double value;
       node(int a){
              l = 0;
              value = 1;
              current = a;
       }
};

double conversion[25][25],dp[25][25][25];
int n,trace[25][25][25],l[25][25];

bool solve(){
             memset(trace,-1,sizeof(trace));
             memset(l,0,sizeof(l));
          int cnt = 2;
          while(1){
                   int len = 100000;
                        for(int i = 1; i <= n; i++){
                                len = min(len,l[i][i]);
                           if(dp[i][i][cnt]>1.01){
                                                  cout << " " << i;
                                             for(int j = 0; j < l[i][i]; j++)
                                                     cout << " " << trace[i][i][j];
                                             cout << " " << i << endl;
                                             return 1;
                           }
                        }
                        for(int i = 1; i <= n; i++)
                                for(int j = 1; j <= n; j++){
                                        int mm=-1;
                                        double m = dp[i][j][cnt];
                                        for(int k = 1; k <= n; k++)
                                                if(dp[i][k][cnt]*conversion[k][j]>m){
                                                                                       //cout << i << " " << k << " " << j << endl;
                                                                                       m = dp[i][k][cnt]*conversion[k][j];
                                                                                       //cout << dp[i][k][cnt] << " " << conversion[k][j] <<" " << m << endl;
                                                                                       
                                                                                       mm = k;
                                                }
                                        dp[i][j][cnt+1] = m;
                                        if(mm>-1){
                                                  for(int k = 0; k < l[i][mm]; k++)
                                                          trace[i][j][k] = trace[i][mm][k];
                                                  l[i][j] = l[i][mm];
                                                  trace[i][j][l[i][j]++] = mm;
                                        }
                                        len = min(len,l[i][j]);
                                }
                        if(len>n-2)
                                 break;
          }
          return 0;
}
     

int main(){
    while(cin>>n){
                  for(int i = 1; i <= n; i++)
                          for(int j = 1; j <= n; j++)
                                  if(i!=j){
                                          cin >> conversion[i][j];
                                          dp[i][j][2] = conversion[i][j];
                                  }
                  for(int i = 1; i <= n; i++)
                          dp[i][i][2] = conversion[i][i] = 1;
                  
                  if(solve()==0)
                              cout << "no arbitrage sequence exists" << endl;
                              
    }
}
