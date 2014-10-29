#include<iostream>
#include<string>
#include<queue>

using namespace std;

bool grid[51][51],visit[51][51][4];
int m,n,str,stc,edr,edc,stdir;
int dr[4] = {-1, 1, 0 ,0}, dc[4] = {0,0,-1,1};

struct node{
       int t, x, y, dir;
       node(int a, int b, int c,  int d): t(a), x(b), y(c), dir(d){}
};

int bfs(){
    queue<node> q;
    q.push(node(0,str,stc,stdir));
    while(!q.empty()){
                      node t = q.front();
                      q.pop();
                      int row = t.x, col = t.y, dir = t.dir, time = t.t;
                      if(row==edr&&col==edc)
                                            return time;
                      
                      if(visit[row][col][dir])
                                               continue;
                      
                      visit[row][col][dir] = 1;
                      if(dir<=1)
                                q.push(node(time+1,row,col,2)), q.push(node(time+1,row,col,3));
                      else
                          q.push(node(time+1,row,col,0)), q.push(node(time+1,row,col,1));
                      
                      int nr = row+dr[dir], nc = col+dc[dir], i = 0, valid = 1;
                      while(i<3){
                                 if(nr<=0||nr>m-1||nc<=0||nc>n-1){
                                                               valid = 0;
                                                               break;
                                 }
                                 
                                 if(grid[nr+1][nc+1]||grid[nr][nc+1]||grid[nr+1][nc]||grid[nr][nc])
                                                                                                   break;
                                 q.push(node(time+1,nr,nc,dir));
                                 nr+=dr[dir], nc+=dc[dir], i++;
                      }
    }            
    return -1;
}

int main(){
    while(cin>>m>>n&&m){
                     for(int i = 1;  i<= m; i++)
                             for(int j = 1; j <= n; j++)
                                     cin >> grid[i][j];
                     cin >> str >> stc >> edr >> edc;
                     string s;
                     cin >> s;
                     if(grid[str][stc]||str>0&&grid[str-1][stc]||stc>0&&grid[str][stc-1]||stc>0&&str>0&&grid[str-1][stc-1]){
                                                                                                                            cout << -1 << endl;
                                                                                                                            continue;
                     }
                     if(s[0]=='n')
                                  stdir = 0;
                     else if(s[0]=='s')
                          stdir = 1;
                     else if(s[0]=='l')
                          stdir = 2;
                     else
                         stdir = 3;
                     memset(visit,0,sizeof(visit));
                     cout << bfs() << endl;
    }
}
                     
                     
