#include<iostream>
#include<queue>
using namespace std;

bool grid[21][21], visit[21][21][1<<14];
int n,m,l,hx,hy,initdir,k;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
struct node{
       short x,y;
       int dir, l;
       node(short a, short b, int c, int d):x(a),y(b),dir(c),l(d){}
};


int bfs(){
     memset(visit,0,sizeof(visit));
     queue<node> q;
     q.push(node(hx,hy,initdir,0));
     while(!q.empty()){
                       node t = q.front();
                       q.pop();
                       int x = t.x, y = t.y, d = t.dir, len = t.l;
                       //cout << x << " " << y << " " << d <<  endl;
                       
                       if(x==1&&y==1)
                                     return len;
                       if(visit[x][y][d])
                                         continue;
                       
                       visit[x][y][d] = 1;
                       
                       int path[8][2];
                       int base = 1, bit = 0, nnd = 0, px = x, py = y;
                         for(int i = 0; i < l-1; i++){
                                 int dd = ((d&base)+(d&(base<<1)));
                                 if(i<l-2)
                                          nnd+=(dd<<2);
                                 dd>>=bit;
                                 px+=dx[dd], py+=dy[dd];
                                 path[i][0] = px, path[i][1] = py;
                                 base<<=2;
                                 bit+=2;
                         }
                       for(int i = 0; i < 4; i++){
                               int newx = x+dx[i], newy = y+dy[i], nd = nnd+ (i<2?1-i:5-i);
                               bool valid = 1;
                               if(newx<1||newx>n||newy<1||newy>m||grid[newx][newy]) continue;
                               for(int i = 0; i < l-1; i++)
                                       if(newx==path[i][0]&&newy==path[i][1]){
                                                                              valid = 0;
                                                                              break;
                                       }
                               if(valid==0) continue;
                               else{
                                    q.push(node(newx,newy,nd,len+1));
                               }
                       }
     }
     return -1;
}


int main(){
    int nc = 1;
    while(cin>>n>>m>>l&&n){
                           int px, py, cx, cy, base = 1;
                           initdir = 0;
                           cin >> hx >> hy;
                           px = hx, py = hy;
                           for(int i = 1; i < l; i++){
                                   cin >> cx >> cy;
                                   for(int i = 0; i < 4; i++)
                                           if(cx==px+dx[i]&&cy==py+dy[i]){
                                                                          initdir+=base*i;
                                                                          break;
                                           }
                                   base<<=2;
                                   px = cx, py = cy;
                           }
                           memset(grid,0,sizeof(grid));
                           cin >> k;
                           for(int i  =0; i < k; i++){
                                   int a,b;
                                   cin >> a >> b;
                                   grid[a][b] = 1;
                           }
                           cout << "Case " << nc++ << ": " << bfs() << endl;
    }
}
                                                                          
