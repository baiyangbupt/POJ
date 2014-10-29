#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int fa[5001],n;
int res;

int find(int x){
    if(fa[x]==x)
                return x;
    return fa[x] = find(fa[x]);
}

void Union(int x, int y){
     int m = find(x), n = find(y);
     if(m<n)
            fa[n] = m;
     else if(m>n)
          fa[m] = n;
}

struct point{
       int x, y;
       point(int a = 0, int b = 0):x(a), y(b){}
};

bool operator<(const point &a, const point &b){
     return a.y<b.y||(a.y==b.y&&a.x<b.x);
}

struct rect{
       point p[4];
       rect(point a, point b){
                  p[0] = a;
                  p[1] = b;
                  p[2].x = p[0].x, p[2].y = p[1].y;
                  p[3].x = p[1].x, p[3].y = p[0].y;
       }
       rect(){}
};

vector<rect> r;
int dis(point a, point b){
    return abs(a.x-b.x)+abs(a.y-b.y);
}

int xmulti(point a, point b, point c){
       return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}

int graham(vector<point> &v){
    int i, len, k = 0, top = 1, n = v.size();
    
    sort(v.begin(), v.end());
    vector<point> temp = v;
    
    for(i = 2; i < n; i++){
          while(top&&xmulti(v[i],temp[top],temp[top-1])>=0) top--;
          temp[++top] = v[i];
    }
    
    len = top, temp[++top] = v[n-2];
    for(i = n-3; i >= 0; i--){
          while(top!=len&&xmulti(v[i],temp[top],temp[top-1])>=0) top--;
          temp[++top] = v[i];
    }
    
    int res = 0;
    for(int i = 0; i <= top; i++)
            cout << temp[i].x << " " <<temp[i].y << endl;
    for(int i = 0; i < top; i++){
            res += dis(temp[i],temp[i+1]);
            cout << dis(temp[i],temp[i+1]) << endl;
    }
    //res += dis(temp[0],temp[top]);
    return res;
}
    
    

bool adj(rect a, rect b){
     if(a.p[0].y>b.p[1].y||a.p[0].x>b.p[1].x||a.p[1].x<b.p[0].x||a.p[1].y<b.p[0].y)
                                                                                   return 0;
     return 1;
}

int main(){
    while(cin>>n){
                  point a,b;
                  for(int i = 0; i < n; i++){
                          cin >> a.x >> a.y >> b.x >> b.y;
                          r.push_back(rect(a,b));
                  }
                  for(int i = 0; i < n; i++) fa[i] = i;
                  for(int i = 0; i< n; i++)
                          for(int j = i+1; j < n; j++)
                                  if(adj(r[i],r[j]))
                                              Union(i,j);
                  
                  int res = 0;
                  for(int i = 0; i < n; i++)
                          if(fa[i]==i){
                                       vector<point> v;
                                       v.push_back(r[i].p[0]), v.push_back(r[i].p[1]), v.push_back(r[i].p[2]), v.push_back(r[i].p[3]);
                                       int p = 1;
                                       for(int j = i+1; j < n; j++)
                                               if(fa[j]==i)                                  
                                                   v.push_back(r[j].p[0]), v.push_back(r[j].p[1]), v.push_back(r[j].p[2]), v.push_back(r[j].p[3]);
                                       
                                       cout << "i " << i<<endl;
                                       res += graham(v);
                          }
                  cout << res << endl;
    }
}
