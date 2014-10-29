#include<iostream>
#include<queue>
using namespace std;

int dx[8] = {0,1,0,-1,1,1,-1,-1}, dy[8] = {1,0,-1,0,1,-1,1,-1};
bool grid[25][25],visit[25][25];
int r,c,sum;
void dfs(int x, int y){
    if(visit[x][y]||grid[x][y]==1) return;
    if(x>r||x<1||y>c||y<1) return;
    visit[x][y] = 1;
    int res = 0;
    for(int i = 0; i < 8; i++){
              int newrow = x+dx[i], newcol = y+dy[i];
             if(newrow>0&&newrow<=r&&newcol>0&&newcol<=c&&grid[newrow][newcol]==0)
                                                                                  dfs(newrow,newcol);
    }
    int t = 4;
   if(visit[x+1][y]) t--;
   if(visit[x-1][y]) t--;
   if(visit[x][y+1]) t--;
   if(visit[x][y-1]) t--;
   sum+=t;
}
    

int main(){
    int sr, sc;
    while(cin >> r >> c >> sr >> sc &&(r||c||sr||sc)){
              sum = 0;
              memset(visit,0,sizeof(visit));
              char input;
              for(int i = 1; i <= r; i++)
                      for(int j = 1; j <= c; j++){
                              cin >> input;
                              grid[i][j] = input=='.'?1:0;
                      }
              dfs(sr,sc);
              cout << sum << endl;
    }
}
        
