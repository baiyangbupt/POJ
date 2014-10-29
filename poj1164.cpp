#include<iostream>
using namespace std;

bool adj[51][51][51][51],visit[51][51];
int m,n,dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};

bool inrange(int x, int y){
     return 0<x&&x<=m&&0<y&&y<=n;
}

int dfs(int x, int y){
    if(visit[x][y]) return 0;
    if(!inrange(x,y)) return 0;
    
    visit[x][y] = 1;
    int res = 0;
    for(int i = 0; i < 4; i++)
            if(adj[x][y][x+dx[i]][y+dy[i]])
                                           res += dfs(x+dx[i],y+dy[i]);
    
    return res+1;
}

int main(){
           while(cin >> m >> n){
               memset(adj,0,sizeof(adj));
               memset(visit,0,sizeof(visit));
               int p;
               for(int i = 1; i <= m; i++){
                       for(int j = 1; j <= n; j++){
                               cin >> p;
                               if((p&1)==0)
                                      adj[i][j][i][j-1] = 1;
                               if((p&2)==0)
                                         adj[i][j][i-1][j] = 1;
                               if((p&4)==0)
                                         adj[i][j][i][j+1] = 1;
                               if((p&8)==0)
                                         adj[i][j][i+1][j] = 1;
                       }
               }
               int roomnum = 0, maxroom = 0,total = 0;
               for(int i = 1; i<= m&&total<m*n; i++)
                       for(int j = 1; j <= n&&total<m*n; j++){
                               int t = dfs(i,j);
                               if(t>0) roomnum++;
                               maxroom = max(maxroom,t);
                               total += t;
                       }
               cout << roomnum << endl;
               cout << maxroom << endl;
           }
}
                               
                               
