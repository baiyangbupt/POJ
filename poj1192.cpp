#include<iostream>
using namespace std;

struct node{
       int x,y,c;
}nn[1001];

const int inf = -10000000;
int n,dp[1001][2];
bool adj[1001][1001],visit[1001];

void dfs(int p){
     visit[p] = 1;
     dp[p][0] = inf, dp[p][1] = nn[p].c;
     for(int i = 0; i < n; i++)
             if(adj[p][i]&&visit[i]==0){
                                        dfs(i);
                                        dp[p][0] = max(dp[p][0],dp[i][0]);
                                        dp[p][0] = max(dp[p][0],dp[i][1]);
                                        if(dp[i][1]>0) dp[p][1]+=dp[i][1];
             }
}
     
                           

int main(){
    while(cin>>n){
                   for(int i = 0; i < n; i++)
                           cin >> nn[i].x >> nn[i].y >> nn[i].c;
                   
                   memset(adj,0,sizeof(adj));
                   for(int i = 0; i < n; i++)
                           for(int j = i+1; j < n; j++)
                                   if(max(nn[i].x-nn[j].x,nn[j].x-nn[i].x)+max(nn[i].y-nn[j].y,nn[j].y-nn[i].y)==1)
                                                                                                                   adj[i][j] = adj[j][i] = 1;
                   
                   dfs(0);
                   cout << max(dp[0][0],dp[0][1]) << endl;
    }
}
                   
                   
