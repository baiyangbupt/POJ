#include<iostream>
using namespace std;

int col,row,str,stc,edr,edc;
int grid[15][15];
int path[15][15];
bool visit[15][15];

bool dfs(int r, int c, int id){
     //cout << r << " " << c << endl;
     if(visit[r][c]) return 0;
     if(r==edr-1&&c==edc-1){
                        path[r][c] = id;
                        return 1;
     }
     
     //cout << grid[r][c] << endl;
     visit[r][c] = 1;
     if(c>0&&(grid[r][c-1]%2==0)){
                                  if(dfs(r,c-1,id+1)){
                                                      path[r][c] = id;
                                                      return 1;
                                  }
     }
     if(r>0&&(grid[r-1][c]<2)){
                               if(dfs(r-1,c,id+1)){
                                                   path[r][c] = id;
                                                   return 1;
                               }
     }
     if(c<col-1&&grid[r][c]%2==0){
                                  if(dfs(r,c+1,id+1)){
                                                     path[r][c] = id;
                                                     return 1;
                                  }
     }
     if(r<row-1&&grid[r][c]<2){
                             if(dfs(r+1,c,id+1)){
                                                path[r][c] = id;
                                                return 1;
                             }
     }
     path[r][c] = 0;
     return 0;
}
     
void print(int nc){
     cout << "Maze " << nc << endl;
     cout << endl;
     cout << "+";
     for(int i = 0; i < col; i++)
             cout << "---+";
     cout << endl;
     for(int i = 1; i < 2*row; i++)
             if(i%2){
                     cout << "|";
                     for(int j = 0; j < col; j++){
                             if(path[i/2][j]==0)
                                                cout << "???";
                             else if(path[i/2][j]==-1)
                                  cout<<"   ";
                             else if(path[i/2][j]<10)
                                  cout << "  " << path[i/2][j];
                             else if(path[i/2][j]<100)
                                  cout << " " << path[i/2][j];
                             else
                                 cout << path[i/2][j];
                             if(grid[i/2][j]%2||j==col-1) cout << "|";
                             else cout << " ";
                     }
                     cout << endl;
             }
             else{
                  cout << "+";
                  for(int j = 0; j < col; j++){
                          //cout << i/2-1 << " " << col << " " <<grid[i/2-1][col];
                          if(grid[i/2-1][j]>=2)
                                                cout << "---";
                          else
                              cout << "   ";
                          cout << "+";
                  }
                  cout << endl;
             }
     cout << "+";
     for(int j = 0; j < col; j++)
             cout << "---+";
     cout << endl;
}

int main(){
    int nc = 1;
    while(cin>>row>>col>>str>>stc>>edr>>edc&&(col)){
                                                    memset(visit,0,sizeof(visit));
                                                    memset(path,-1,sizeof(path));
                                                    for(int i = 0; i < row; i++)
                                                            for(int j = 0; j < col; j++)
                                                                    cin >> grid[i][j];
                                                    dfs(str-1,stc-1,1);
                                                    print(nc);
                                                    nc++;
                                                    cout << endl;
                                                    cout << endl;
    }
}
                                                    
