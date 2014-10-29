#include<iostream>
#include<vector>
using namespace std;

int w,h,t,n,times;

struct point{
       int t,r,c;
};

bool grid[101][101][101], timeknown[101], unknown;
void notin(int a, int b, int c, int d, int e){
     for(int i = c; i <= e; i++)
             for(int j = b; j <= d; j++)
                     grid[a][i][j] = 1;
}

int dis(const point &a, const point &b){
    return (a.r-b.r>0?a.r-b.r:b.r-a.r)+(a.c-b.c>0?a.c-b.c:b.c-a.c);
}

point path[101];
int cnt;

bool dfs(vector<vector<point> > &h, int p, point pre){
     if(cnt>=2) return 1;
     if(p==times){
                cnt++;
                return 1;
     }
     
     bool reach = 0;
     if(p==0){
              for(int i = 0; i < h[0].size()&&unknown==0; i++){
                      if(dfs(h,p+1,h[0][i]))
                                            reach = 1, path[1] = h[0][i]; 
              }
     }
     else{
          for(int i = 0; i < h[p].size()&&unknown==0; i++){
                  point cur = h[p][i];
                  int d = dis(pre,cur);
                  if(d>cur.t-pre.t)
                                               continue;
                  else if(d<cur.t-pre.t){
                                         if(dfs(h,p+1,cur)){
                                                           cnt = 2;
                                                           return 1;
                                         }
                  }
                  else{
                       if(cur.c==pre.c){
                                        if(dfs(h,p+1,cur)){
                                                           reach = 1;
                                                           int dr = (cur.r>pre.r?1:-1);
                                                           for(int i = pre.t; i <= cur.t; i++)
                                                                   path[i].t = i, path[i].r = pre.r+(i-pre.t)*dr, path[i].c = pre.c;
                                        }
                       }
                       else if(cur.r==pre.r){
                            if(dfs(h,p+1,cur)){
                                               reach = 1;
                                               int dc = (cur.c>pre.c?1:-1);
                                               for(int i = pre.t; i <= cur.t; i++)
                                                       path[i].t = i, path[i].c = pre.c+(i-pre.t)*dc, path[i].r=  pre.r;
                            }
                       }
                       else{
                            cnt = 2;
                            reach = 1;
                       }
                  }
          }
     }
     
     if(reach) return 1;
     return 0;
}
     

int main(){
    int nc = 1;
    while(cin>>w>>h>>t&&(w||h||t)){
                                   cout << "Robbery #"<<nc++<<":"<<endl;
                                   cnt = 0;
                                   vector<vector<point> > here;
                                   memset(grid,0,sizeof(grid));
                                   memset(timeknown,0,sizeof(timeknown));
                                   cin >> n;
                                   int a,b,c,d,e;
                                   for(int i = 0; i < n; i++){
                                         cin >> a >> b >> c >> d >> e;
                                         notin(a,b,c,d,e);
                                         timeknown[a] = 1;
                                   }
                                   
                                   times = 0;
                                   unknown = 0;
                                   bool in = 1;
                                   for(int time = 1; time <= t&&in; time++)
                                           if(timeknown[time]){
                                                   vector<point> v;
                                                   for(int i = 1; i <= h&&in; i++)
                                                           for(int j = 1; j <= w&&in; j++)
                                                                   if(grid[time][i][j]==0){
                                                                                           point p;
                                                                                           p.t = time, p.r = i, p.c = j;
                                                                                           v.push_back(p);
                                                                   }
                                                   if(v.size()==0) in = 0;
                                                   else{
                                                        //for(int i = 0; i < v.size(); i++)
                                                        //        cout << v[i].r << " " << v[i].c << endl;
                                                       here.push_back(v);
                                                   }
                                                   times++;
                                           }
                                   
                                   if(in==0) cout << "The robber has escaped." << endl;
                                   else{
                                        point p;
                                        if(dfs(here,0,p)==0) cout << "The robber has escaped." << endl;
                                        else if(cnt>=2) cout << "Nothing known." << endl;
                                        else{
                                             for(int i = 1; i<t;i++)
                                                     cout << "Time step " << i << ": The robber has been at "<< " " 
                                                          << path[i].c << "," << path[i].r <<"." << endl;
                                        }
                                   }
                                   cout << endl;
    }
}
