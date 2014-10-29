#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> upper, down, left, right;
bool visit[37];
int grid[6][6];

int n,m;
bool dfs(int x, int y){
     if(grid[x][y]>=0)
                      return dfs(x,y+1);
     if(y==m)
             return dfs(x+1,0);
     if(x==n)
             return 1;
     
     bool l = 0, r = 0, u = 0, d = 0;
     if(x==0)
             u = 1;
     if(y==0)
             l = 1;
     if(x==n-1)
               d = 1;
     if(y==m-1)
               r= 1;
     for(int i = 0; i<n*m; i++)
             if(visit[i]==0){
                             if(u&&block[i][0]!='F'||l&&block[i][3]!='F'||d&&block[i][2]!='F'||r&&block[i][1]!='F')
                                                                                                                   continue;
                             if(x>0&&block[i][0]==block[grid[x-1][y]][2]||y>0&&block[i][3]==block[grid[x][y-1]][1])
                                                                                                                   continue;
                             visit[i] = 1;
                             grid[x][y] = i;
                             if(dfs(x,y+1)==1)
                                              return 1;
                             visit[i] = 0;
                             grid[x][y] = -1;
             }
     return 0;
}

int main(){
    while(cin>>n>>m&&n){
                        upper.clear(), left.clear(), down.clear(), right.clear();
                        string s;
                        bool invalid = 0;
                        memset(grid,-1,sizeof(grid));
                        memset(visit,0,sizeof(visit));
                        for(int i = 0; i < n*m; i++){
                                cin >> block[i];
                                int t = 0, po;
                                for(int j = 0; j < 4; j++)
                                        if(block[i][j]=='F')
                                                      t++, po = j;
                                if(t==2){
                                         if(block[i][0]=='F'&&block[i][3]=='F'){
                                                                             if(grid[0][0]>=0)
                                                                                              invalid = 1;
                                                                             else
                                                                                  grid[0][0] = i, visit[i] = 1;
                                         }
                                         else if(block[i][0]=='F'&&block[i][2]=='F'){
                                              if(grid[0][m-1]>=0)
                                                                 invalid = 1;
                                              else
                                                  grid[0][m-1] = i, visit[i] = 1;
                                         }
                                         else if(block[i][1]=='F'&&block[i][3]=='F'){
                                              if(grid[n-1][0]>=0)
                                                                 invalid = 1;
                                              else
                                                  grid[n-1][0] = i, visit[i] = 1;
                                         }
                                         else if(block[i][1]=='F'&&block[i][2]=='F'){
                                              if(grid[n-1][m-1]>=0)
                                                                   invalid = 1;
                                              else 
                                                   grid[n-1][m-1]=i, visit[i] = 1;
                                         }
                                         else
                                             invalid = 1;
                                }
                                                  
                        
                        memset(visit,0,sizeof(visit));
                        if(dfs(0,0))
                                    cout << "YES" << endl;
                        else
                            cout << "NO" << endl;
    }
}
