#include<iostream>
using namespace std;

int dis[4][4],n;
bool nonco[4][4][4][4];
char grid[4][4];

int main(){
    while(cin>>n&&n){
                     memset(dis,0,sizeof(dis));
                     for(int i = 0; i < n; i++)
                             for(int j = 0; j < n; j++)
                                     cin >> grid[i][j];
                     int sum = 0;
                     for(int i = 0; i < n; i++)
                             for(int j = 0; j < n; j++)
                                     if(grid[i][j]=='.'){
                                         sum+=1;
                                         bool blocked = 0;
                                         int k = i+1;
                                         while(k<n&&blocked==0){
                                                               if(grid[k][j]=='X') blocked = 1;
                                                               else
                                                                   dis[i][j]++, dis[k][j]++, nonco[i][j][k][j] = nonco[k][j][i][j] = 1;
                                                               k++;
                                         }
                                         k = j+1, blocked = 0;
                                         while(k<n&&blocked==0){
                                                                if(grid[i][k]=='X') blocked = 1;
                                                                else
                                                                    dis[i][j]++, dis[i][k]++, nonco[i][j][i][k] = nonco[i][k][i][j] = 1;
                                                                k++;
                                         }
                             }
                     int m = 0, mx = -1, my = -1;
                     for(int i = 0; i < n; i++)
                             for(int j = 0; j < n; j++)
                                     if(grid[i][j]=='.'&&dis[i][j]>=m)
                                                    m = dis[i][j], mx = i, my = j;
                     int res = sum;
                     while(dis[mx][my]>0){
                                          //cout << mx << " " << my << endl;
                                          res--;
                                          dis[mx][my] = 0;
                                          grid[mx][my] = 'X';
                                          for(int i = 0; i < n; i++){
                                                  if(grid[i][my]=='.'&&nonco[mx][my][i][my])
                                                                                            dis[i][my]--;
                                                  if(grid[mx][i]=='.'&&nonco[mx][my][mx][i])
                                                                                            dis[mx][i]--;
                                          }
                                          m = 0;
                                          for(int i = 0; i < n; i++)
                                                  for(int j = 0; j < n; j++)
                                                          if(grid[i][j]=='.'&&dis[i][j]>=m)
                                                                         m = dis[i][j], mx = i, my = j;
                     }
                     cout << res << endl;
    }
}
                     
