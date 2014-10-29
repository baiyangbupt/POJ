#include<iostream>
using namespace std;

bool adj[102][102],visit[102],color[102],valid,connect;
int n,mark[102][2];

void buildinverse(){
     for(int i = 1; i <= n; i++)
             for(int j = i+1; j <= n; j++){
                     if(adj[i][j]&&adj[j][i])
                                             adj[i][j] = adj[j][i] = 0;
                     else
                         adj[i][j] = adj[j][i] = 1;
             }
}

void dfs(int p, int col){
     if(valid==0) return;
     if(visit[p]) {
                  if(col!=color[p]) valid = 0;
                  return;
     }
     
     visit[p] = 1;
     color[p] = col;
     mark[connect][col]++;
     
     for(int i = 1; i <= n; i++)
             if(adj[p][i])
                          dfs(i,1-col);
     
     return;
}

int solve(){
    memset(visit,0,sizeof(visit));
    memset(mark,0,sizeof(mark));
    connect = 1;
    for(int i = 1; i <= n && valid; i++)
            if(visit[i]==0){
                            dfs(i,0);
                            connect++;
            }
    if(valid==0) cout << "No solution" << endl;
    
    bool dp[10010];
    memset(dp,0,sizeof(dp));

    int t = mark[1][0]-mark[1][1]+100,m;
    dp[t] = 1;
    m = t;
    t = 100+mark[1][1]-mark[1][0];
    dp[t] = 1;
    m = max(m,t);
    for(int i = 2; i < connect; i++){
            int tm = 0;
            for(int j = m; j >= 0; j--)
                    if(dp[j]) {
                             dp[j+100+mark[i][0]-mark[0][1]] = dp[j+100+mark[i][1]-mark[i][0]] = 1;
                             tm = max(tm,j+100+mark[i][0]-mark[0][1]);
                             tm = max(tm,j+100+mark[i][1]-mark[i][0]);
                    }
            m = tm;
    }        
    for(n
}
     
     
int main(){
    memset(adj,0,sizeof(adj));
    cin >> n;
    for(int i = 1; i <= n; i++){
            int t;
            while(cin>>t&&t){
                             adj[i][t] = 1;
            }
    }
