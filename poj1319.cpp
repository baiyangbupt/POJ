#include<iostream>
using namespace std;

char grid[8][8];
int n,res,map[8][8],k;

void paint(int x, int y, int num){
         int tobe;
         if(map[x][y] == num)
                      map[x][y] = 0, tobe = 0;
         else
             map[x][y] = num, tobe = num, num = 0;
         int k = x+1;
         while(k<n){
                                     if(map[k][y]==num)
                                                       map[k][y] = tobe;
                                     k++;
         }
         k = y+1;
         while(k<n){
                                     if(map[x][k]==num)
                                                       map[x][k] = tobe;
                                     k++;
         }
         k = x-1;
         while(k>=0){
                                      if(map[k][y]==num)
                                                        map[k][y] = tobe;
                                      k--;
         }
         k = y-1;
         while(k>=0){
                                      if(map[x][k]==num)
                                                        grid[x][k] = tobe;
                                      k--;
         }
}
     

void dfs(int x, int y, int flag, int fillin){
     //cout << fillin << " " << k << endl;
     if(fillin==k){
                   res++;
                   return;
     }
     if(y==n){
              dfs(x+1,0,flag,fillin);
              return;
     }
    if(x==n){
                     return;
    }
    
    if(map[x][y]>0){
                                         dfs(x,y+1,flag,fillin);
    }
    else{
         //cout << x  << " " << y << " " << fillin << endl;
         paint(x,y,flag);
         dfs(x,y+1,flag+1,fillin+1);
         paint(x,y,flag);
         dfs(x,y+1,flag,fillin);
    }
}
         

int main(){
    while(cin>>n>>k&&n!=-1){
                     memset(map,0,sizeof(map));
                     for(int i = 0; i < n; i++)
                             for(int j = 0; j < n; j++)
                                     cin >> grid[i][j];
                     for(int i = 0; i < n; i++)
                             for(int j = 0; j < n; j++)
                                     if(grid[i][j]=='.')
                                                        map[i][j] = 1;
                     res = 0;
                     dfs(0,0,2,0);
                     cout << res << endl;
    }
}
