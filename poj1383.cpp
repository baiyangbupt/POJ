#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

char grid[1000][1000];
bool visit[1000][1000];
int dr[4] = {1,-1,0,0}, dc[4] = {0,0,1,-1}, res,c,r;

int dfs(int x, int y){
    if(visit[x][y]) 
                    return 0;
    
    visit[x][y] = 1;
    int l[4],m = 0;
    for(int i = 0; i < 4; i++){
            int xx = x+dr[i], yy = y+dc[i];
            if(xx>=0&&xx<r&&yy>=0&&yy<c&&grid[xx][yy]=='.')
                                        l[i] = dfs(xx,yy);
            else
                l[i] = 0;
    }
    sort(l,l+4);
    
    res = max(res,1+l[3]+l[2]);
    return l[3]+1;
}
    
    

int main(){
    int nc;
    scanf("%d", &nc);
    while(nc--){
                scanf("%d%d", &c, &r);
                for(int i = 0; i < r; i++)
                                scanf("%s", grid[i]);
                memset(visit,0,sizeof(visit));
                bool found = 1;
                res = 0;
                for(int i = 0; i < r && found; i++)
                        for(int j = 0; j < c &&found; j++)
                                if(grid[i][j]=='.'){
                                                    dfs(i,j);
                                                    found = 0;
                                }
                cout << "Maximum rope length is " << res-1<<'.' << endl;
    }
}
