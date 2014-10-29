#include<iostream>
using namespace std;

int son[101][101], level[101], sons[101], add[101][101], value[101], dp[101];
int m,n;

void init(){
     cin >> m >> n;
     for(int i = 1; i <= n; i++){
             cin >> value[i] >> level[i] >> sons[i];
             for(int j = 1; j <= sons[i]; j++)
                     cin >> son[i][j] >> add[i][j];
     }
     memset(dp,-1,sizeof(dp));
}

int dfs(int p, int left, int right){
         if(dp[p]>0) return dp[p];
         
         if(level[p]<left||level[p]>right) return dp[p] = -1;
         if(sons[p]==0) return dp[p] = value[p];
         
         dp[p] = value[p];
         int newleft = max(left,level[p]-m), newright = min(right,level[p]+m);
         if(newright<newleft) return dp[p];
         
         for(int i = 1; i <= sons[p]; i++){
                 int t = dfs(son[p][i],newleft,newright);
                 if(t>0) dp[p] = min(dp[p],t+add[p][i]);
         }
         
         return dp[p];
}

int main(){
    init();
    int res = dfs(1,-1000,1000);
    
    cout << res << endl;
    system("pause");
}
