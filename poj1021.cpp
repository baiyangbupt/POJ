#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct point{
       int x,y;
};


int n, h, w;
point origin[10000], test[10000];
bool visit[10000];
int grid[101][101];
vector<vector<int> > clustero, clustert;

bool cmp(const point &a, const point &b){
     if(a.x==b.x)
                 return a.y<b.y;
     return a.x<b.x;
}

bool shiftable(vector<point> v1, vector<point> v2){
             sort(v1.begin(),v1.end(),cmp);
             sort(v2.begin(),v2.end(),cmp);
             int dx = v2[0].x-v1[0].x, dy = v2[0].y-v1[0].y;
             for(int i = 1; i < v1.size(); i++)
                     if(v1[i].x+dx!=v2[i].x||v1[i].y+dy!=v2[i].y)
                                                                 return 0;
             
             return 1;
}

void rotate(vector<point> &v){
     int bx = v[0].x, by = v[0].y;
     for(int i = 1; i < v.size(); i++){
             int tx = v[i].x, ty = v[i].y;
             v[i].x = bx+ty-by;
             v[i].y = by+bx-tx;
     }
}

void turnover(vector<point> &v){
     for(int i = 0; i < v.size(); i++)
             v[i].x = -1*v[i].x;
}

void dfs(int x, int y, int grid[101][101], vector<int> &tmp){
     if(grid[x][y]==0||visit[grid[x][y]]) return;
     
     visit[grid[x][y]] = 1;
     tmp.push_back(grid[x][y]);
     if(x+1<h) dfs(x+1,y,grid,tmp);
     if(x-1>=0) dfs(x-1,y,grid,tmp);
     if(y+1<w) dfs(x,y+1,grid,tmp);
     if(y-1>-1) dfs(x,y-1,grid,tmp);
}
     

int main(){
    int t;
    cin >> t;
    while(t--){
               cin >> h >> w >> n;
               memset(grid,0,sizeof(grid));
               memset(visit,0,sizeof(visit));
               for(int i = 1; i <= n; i++){
                       cin >> origin[i].x >> origin[i].y;
                       grid[origin[i].x][origin[i].y] = i;
               }
               for(int i = 1; i <= n; i++){
                       vector<int> v;
                       dfs(origin[i].x,origin[i].y, grid, v);
                       if(v.size()>0) clustero.push_back(v);
               }
               /*for(int i = 0;  i< clustero.size(); i++){
                       for(int j = 0; j < clustero[i].size(); j++)
                               cout << clustero[i][j] << " ";
                       cout << endl;
               }*/
               memset(grid,0,sizeof(grid));
               memset(visit,0,sizeof(visit));
               for(int i = 1; i <= n; i++){
                       cin >> test[i].x >> test[i].y;
                       grid[test[i].x][test[i].y] = i;
               }
               for(int i = 1; i <= n; i++){
                       vector<int> v;
                       dfs(test[i].x,test[i].y,grid,v);
                       if(v.size()>0) clustert.push_back(v);
               } 
               
               /*for(int i = 0;  i< clustert.size(); i++){
                       for(int j = 0; j < clustert[i].size(); j++)
                               cout << clustert[i][j] << " ";
                       cout << endl;
               }*/
               if(clustero.size()!=clustert.size()){
                                                    cout  << "NO" << endl;
                                                    continue;
               }
               memset(visit,0,sizeof(visit));
               int len = clustero.size(),i;
               for(i = 0; i < len; i++){
                       vector<int> v = clustero[i];
                       vector<point> vp;
                       int j;
                       for(j = 0; j < v.size(); j++) vp.push_back(origin[v[j]]);
                       
                       for(j = 0; j < len; j++)
                               if(visit[j]==0&&clustert[j].size()==v.size()){
                                                                             v = clustert[j];
                                                                             vector<point> vpp;
                                                                             for(int k = 0; k < v.size(); k++) vpp.push_back(test[v[k]]);
                                                                             int i = 0;
                                                                             bool matched = 0;
                                                                             while(i<4){
                                                                                        if(shiftable(vp,vpp)){
                                                                                                              matched = 1;
                                                                                                              break;
                                                                                        }
                                                                                        rotate(vp);
                                                                                        i++;
                                                                             }
                                                                             if(matched){
                                                                                         visit[j] = 1;
                                                                                         break;
                                                                             }
                                                                             turnover(vp);
                                                                             i = 0;
                                                                             while(i<4){
                                                                                        if(shiftable(vp,vpp)){
                                                                                                              matched = 1;
                                                                                                              break;
                                                                                        }
                                                                                        rotate(vp);
                                                                                        i++;
                                                                             }
                                                                             if(matched){
                                                                                         visit[j] = 1;
                                                                                         break;
                                                                             }
                               }
                       if(j==len){
                                  cout << "NO" << endl;
                                  break;
                       }
               }
                         
               if(i==len)
                         cout << "YES" << endl;
    }
}
                                               
