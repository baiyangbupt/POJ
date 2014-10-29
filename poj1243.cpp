#include<iostream>
using namespace std;

int g,l,dp[31][31];

int dfs(int x, int y){
    if(dp[x][y]>=0) return dp[x][y];
    if(y==0) return dp[x][0] = x;
    if(x==0) return dp[x][y] = 0;

    return dfs(x-1,y-1)+1+dfs(x-1,y);
}

int main(){
    memset(dp,-1,sizeof(dp));
    
    for(int i = 0; i <=30; i++)
            dp[0][i] = 0;
    for(int i = 0; i <= 30; i++)
            dp[i][0] = i;
            
    int x,y,nc=1;
    while(cin>>x>>y&&(x||y)){
                             for(int i = 1; i <= x; i++)
                                     for(int j = 1; j <= y; j++)
                                             if(dp[i][j]<0)
                                                            dp[i][j] = dp[i-1][j-1]+1+dp[i-1][j];
                                     
                             cout <<"Case " << nc << ": "<< dfs(x,y) << endl;
                             nc++;
    }
}
