#include<iostream>
using namespace std;


char grid[21][21];
bool used[26],visit[21][21];

int r,c,dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};
bool inrange(int x, int y){
     return 0<x&&x<=r&&0<y&&y<=c;
}

int dfs(int x, int y){
    
    int res = 0;
    
    for(int i = 0; i < 4; i++){
            int nx = x+ dx[i], ny = y+dy[i];
            if(inrange(nx,ny)&&used[grid[nx][ny]-'A']==0){
                                               used[grid[nx][ny]-'A'] =1;
                                               res = max(res,dfs(nx,ny));
                                               used[grid[nx][ny]-'A'] = 0;
            }
    }
    
    return res+1;
}

int main(){
    while(cin>>r>>c){
                     for(int i = 1; i <= r; i++)
                             for(int j = 1; j <= c; j++)
                                     cin >> grid[i][j];
                     memset(used,0,sizeof(used));
                     used[grid[1][1]-'A'] = 1;
                     int res = dfs(1,1);
                     
                     cout << res << endl;
    }
}
