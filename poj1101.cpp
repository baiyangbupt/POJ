#include<iostream>
#include<queue>
#include<string>
using namespace std;

bool visit[100][100], grid[100][100];
int sr,sc,er,ec,w,h,dist[100][100];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

struct qnode{
       int row,col;
       qnode(int a, int b):row(a),col(b){}
};

int bfs(){
    memset(visit,0,sizeof(visit));
    queue<qnode> q;
    qnode s(sr,sc);
    dist[sr][sc] = 0;
    visit[sr][sc] = 1;
    q.push(s);
    while(!q.empty()){
                      qnode t = q.front();
                      q.pop();
                      if(t.row==er&&t.col==ec) return dist[er][ec];
                      
                      int r = t.row, c = t.col, nr, nc;
                      for(int i = 0; i < 4; i++){
                              nr = r+dr[i];
                              nc = c+dc[i];
                              while(nr<=h+1&&nr>=0&&nc<=w+1&&nc>=0&&visit[nr][nc]==0&&grid[nr][nc]==0){
                                                                                                   dist[nr][nc] = dist[r][c]+1;
                                                                                                   visit[nr][nc] = 1;
                                                                                                   q.push(qnode(nr,nc));
                                                                                                   nr = nr+dr[i];
                                                                                                   nc = nc+dc[i];
                              }
                      }
    }
    return -1;                
}

int main(){
    string s;
    int nc = 1;
    while(cin>>w>>h&&(h||w)){
                             cout << "Board #" << nc << ":" << endl;
                             nc++;
                             memset(grid,0,sizeof(grid));
                             cin.get();
                             for(int i = 1; i<=h; i++){
                                     getline(cin,s);
                                     for(int j = 1; j <= w; j++)
                                             grid[i][j] = (s[j-1]==' '?0:1);
                             }
                             int a,b,c,d,np=1;
                             while(cin>>a>>b>>c>>d&&(a||b||c||d)){
                                                                  sc = a, sr = b;
                                                                  ec = c, er = d;
                                                                  grid[b][a] = grid[d][c] = 0;
                                                                  int res = bfs();
                                                                  cout << "Pair " << np++ << ": ";
                                                                  if(res==-1) cout << "impossible."<<endl;
                                                                  else cout << res << " segments." << endl;
                                                                  grid[b][a] = grid[d][c] = 1;
                             }
                             cout << endl;
    }
}                                                                  
