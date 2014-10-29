#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<vector>
using namespace std;

struct wall{
       int x,y,l;
}w[1000];

float dis(int x1, int y1, int x2, int y2){
       return sqrt((float)((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
}

int n,st,ed,fa[1000]; 
struct node{
       int u,v;
       float d;
       node(int a, int b, double c):u(a), v(b), d(c) {}
};

bool operator<(const node &a, const node &b){
     return a.d < b.d;
}

float walldis(int a, int b){
       if(w[a].l==0&&w[b].l==0) return dis(w[a].x,w[a].y,w[b].x,w[b].y);
       if(w[a].l>=0) swap(a,b);
       int x1 = w[a].x, y1 = w[a].y, x2 = x1, y2 = y1, x3 = w[b].x, y3 = w[b].y, x4 = x3, y4 = y3;
       
       if(w[b].l>=0){
                    x4 += w[b].l;
                    if(w[a].l>=0){
                                  x2 += w[a].l;
                                  if(x2>=x3&&x1<=x4)
                                                    return max(y1-y3,y3-y1);
                                  else
                                      return min(dis(x2,y2,x3,y3),dis(x4,y4,x1,y1));
                    }
                    else{
                         y2 += -w[a].l;
                         if(x1>=x3&&x1<=x4){
                                            if(y3>=y1&&y3<=y2) return 0;
                                            return min(y1-y3>0?y1-y3:y3-y1,y2-y3>0?y2-y3:y3-y2);
                         }
                         else if(y3>=y1&&y3<=y2)
                              return min(x1-x3>0?x1-x3:x3-x1,x1-x4>0?x1-x4:x4-x1);
                         else if(y3<y1)
                              return min(dis(x3,y3,x1,y1),dis(x4,y4,x1,y1));
                         else
                             return min(dis(x3,y3,x2,y2),dis(x4,y4,x2,y2));
                    }
       }
       else{
            y4 -=w[b].l, y2 -= w[a].l;
            if(y2>=y3&&y4>=y1)
                              return max(x1-x3,x3-x1);
            else if(y2<y3)
                 return dis(x2,y2,x3,y3);
            else
                return dis(x1,y1,x4,y4);
       }
}

int find(int x){
    if(fa[x]==x)
                return x;
    return fa[x] = find(fa[x]);
}

void Union(int x, int y){
     int m = find(x), n = find(y);
     if(m<n)
            fa[n] = m;
     else if(n<m)
          fa[m] = n;
}

int main(){
    while(cin>>n&&n){
                     for(int i = 0; i < n; i++)
                             cin >> w[i].x >> w[i].y >> w[i].l;
                     
                     vector<node> vv;
                     float dd = walldis(0,1);
                     for(int i = 0; i < n; i++)
                             for(int j = i+1; j < n; j++){
                                     float newd = walldis(i,j);
                                     if(newd<=dd)
                                                 vv.push_back(node(i,j,newd));
                             }
                     for(int i = 0; i < n; i++) fa[i] = i;
                     sort(vv.begin(),vv.end());
                     st = 0, ed = 1;
                     float res = 0;
                     int i = 0;
                     while(find(st)!=find(ed)){
                                               int u = vv[i].u, v= vv[i].v;
                                               float d = vv[i].d;
                                               res = d;
                                               Union(u,v);
                                               i++;
                     }
                     cout << setiosflags(ios::fixed) << setprecision(2) << res << endl;
    }
}
