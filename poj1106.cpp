#include<iostream>
#include<vector>
#include<cmath>
#define eps 1e-5
using namespace std;

struct point{
       int x, y;
       point(int a, int b):x(a), y(b){}
};

int sx, sy, n;
double r;

double dis(int x, int y, int a, int b){
       return sqrt(1.0*(x-a)*(x-a)+1.0*(y-b)*(y-b));
}

double xmulti(point a, point b, point c){
       return (a.x-c.x)*(b.y-c.y)*1.0-(b.x-c.x)*(a.y-c.y)*1.0;
}

int main(){
    while(cin >> sx >> sy >> r&&r>0){
              point s(sx,sy);
              vector<point> v;
              cin >> n;
              for(int i = 0; i < n; i++){
                      int x, y;
                      cin >> x >> y;
                      if(dis(x,y,sx,sy)<=r+eps)
                                          v.push_back(point(x,y));
              }
              
              //cout << v.size() << endl;
              
              int res=0;
              for(int i = 0; i < v.size(); i++){
                      int pc = 1, nc = 1;
                      for(int j = 0; j < v.size(); j++)
                              if(j!=i){
                                       double t = xmulti(v[i],v[j],s);
                                       //cout << t << endl;
                                       if(t>0) pc++;
                                       else if(t<0) nc++;
                                       else
                                           pc++, nc++;
                              }
                      res = max(res,max(pc,nc));
              }
              cout << res << endl;
    }
}
                                       
              
              
                                              
