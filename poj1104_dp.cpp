#include<iostream>
using namespace std;

int w,h,t;
bool grid[102][102][102];
int num[102];

int zeros(int t){
    int res = 0;
    for(int i = 1; i <= h; i++)
            for(int j = 1; j <= w; j++){
                    res+=(grid[t][i][j]==0);
                    //if(grid[t][i][j]==0){
                     //                    cout << t<< " " << i << " " << j <<endl;
                    //}
            }
    
    return res;
}
bool inRange(int curH, int curW)
{
    return (curH >= 1 && curH <= h && curW >= 1 && curW <= w);
}

int dir[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool check(int curH, int curW, int curT, int pT)
{
    if(grid[curT][curH][curW])
        return false;
    int d, nH, nW;
    for(d = 0; d < 5; d++)
    {
        nH = curH + dir[d][0];
        nW = curW + dir[d][1];
        if(inRange(nH, nW))
        {
            if(!grid[pT][nH][nW])
                return false;
        }
    }
    grid[curT][curH][curW] = true;
    return true;
}


int main(){
    int nc = 1;
    while(cin>>w>>h>>t&&(w||h||t)){
                                   cout << "Robbery #" << nc++ << ":" << endl;
                                   memset(grid,0,sizeof(grid));
                                   int n;
                                   cin >> n;
                                   for(int i = 0; i < n; i++){
                                           int a,b,c,d,e;
                                           cin >> a >> b >> c >> d >> e;
                                           for(int ii = c; ii <= e; ii++)
                                                   for(int j = b; j <= d; j++)
                                                           grid[a][ii][j] = 1;
                                   }
                                   
                                   
                                   int path[101][2];
                                   for(int time = 2; time <= t; time++){
                                           for(int i = 1; i <= h; i++)
                                                   for(int j = 1; j <= w; j++)
                                                           if(grid[time][i][j]==1) continue;
                                                           else if((i>1&&grid[time-1][i-1][j]==0||
                                                           i<h&&grid[time-1][i+1][j]==0||j>1&&grid[time-1][i][j-1]==0||
                                                           j<w&&grid[time-1][i][j+1]==0||grid[time-1][i][j]==0))
                                                                                                               grid[time][i][j] = 0;
                                                           else grid[time][i][j] = 1;
                                   }
                                   
                                   for(int time = t; time>=1; time--){
                                           for(int i = 1; i <= h; i++)
                                                   for(int j = 1; j <= w; j++)
                                                           if(grid[time][i][j]==1) continue;
                                                           else if((i>1&&grid[time+1][i-1][j]==0||
                                                           i<h&&grid[time+1][i+1][j]==0||j>1&&grid[time+1][i][j-1]==0||
                                                           j<w&&grid[time+1][i][j+1]==0||grid[time+1][i][j]==0))
                                                                                                               grid[time][i][j] = 0;
                                                           else grid[time][i][j] = 1;
                                   }
                                   /*cout << endl;
                                   for(int time = 1; time <= t; time++){
                                           for(int i = 1; i <= h; i++)
                                                   for(int j = 1; j <= w; j++)
                                                           if(grid[time][i][j]==0)
                                                                                  cout << time << " " << i << " " << j << endl;
                                   }*/
                                   
                                   bool multi = 1, escape = 1;
                                   for(int time = 1; time <= t; time++){
                                           int cnt = 0;
                                           for(int i = 1; i <= h; i++)
                                                   for(int j = 1; j <= w; j++)
                                                           if(grid[time][i][j]==0)
                                                                            path[time][0] = j, path[time][1] = i, cnt++;
                                           num[time] = cnt;
                                           if(cnt==0)
                                                          multi = 0;
                                           else {
                                                escape = 0;
                                                if(cnt==1){
                                                           multi = 0;
                                                }
                                           }
                                                
                                   }          
                                   if(escape)
                                             cout << "The robber has escaped." << endl;
                                   else if(multi)
                                        cout << "Nothing known." << endl;
                                   else{
                                        for(int i = 1; i <= t; i++)
                                                if(num[i]==1){
                                                              cout << "Time step " << i << ": The robber has been at " << path[i][0] << "," << path[i][1] <<"."<< endl;
                                                }
                                   }
                                   cout << endl;
    }
}
