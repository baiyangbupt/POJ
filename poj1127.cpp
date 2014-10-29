#include<iostream>

using namespace std;

int n;
bool adj[20][20];
struct point{
       int x,y;
};

struct line{
       point a,b;
}L[20];

int xmulti(const point &p1, const point &p2, const point &p3){
    return (p1.x-p3.x)*(p2.y-p3.y)-(p1.y-p3.y)*(p2.x-p3.x);
}

bool lsinterls(line u, line v){
    return ((max(u.a.x,u.b.x)>=min(v.a.x,v.b.x))&&(max(v.a.x,v.b.x)>=min(u.a.x,u.b.x))&&(max(u.a.y,u.b.y)>=min(v.a.y,v.b.y))&&
           (max(v.a.y,v.b.y)>=min(u.a.y,u.b.y))&&(xmulti(v.a,u.b,u.a)*xmulti(u.b,v.b,u.a)>=0)&&(xmulti(u.a,v.b,v.a)*xmulti(v.b,u.b,v.a)>=0));
}

int main(){
    while(cin >> n &&n){
              for(int i = 1; i <= n; i++)
                      cin >> L[i].a.x >> L[i].a.y >> L[i].b.x >> L[i].b.y;
              memset(adj,0,sizeof(adj));
              for(int i = 1; i <= n; i++){
                      adj[i][i] = 1;
                      for(int j = i+1; j <= n; j++)
                              adj[i][j] = adj[j][i] = lsinterls(L[i],L[j]);
              }
              
              for(int k = 1; k <= n; k++)
                      for(int i = 1; i <= n; i++)
                              for(int j = 1; j <= n; j++)
                                      if(adj[i][k]&&adj[k][j])
                                                              adj[i][j] = 1;
              
              int a,b;
              while(cin>>a>>b&&a){
                                  if(adj[a][b])
                                               cout << "CONNECTED" << endl;
                                  else cout << "NOT CONNECTED" << endl;
              }
    }
}
