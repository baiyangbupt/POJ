#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int T,p,k;
struct node{
       int x,y;
}nn[30][11];

struct rec{
       int a,b,c,d;
}rr[30];

struct interval{
       int l,r;
       interval(int a, int b): l(a), r(b){}
};

bool operator <(const interval &a, const interval &b){
     return a.l<b.l;
}

bool inrange(int a, int b, int c, int d, node p){
     return p.x<=b&&p.x>=a&&p.y>=c&&p.y<=d;
}

bool inter(int i, int j){
     if(rr[i].a>rr[j].b||rr[i].b<rr[j].a||rr[i].c>rr[j].d||rr[i].d<rr[j].c)
                                                                               return 0;
     return 1;
}

bool fulcover(int l, int r, vector<interval> x){
     int len = x.size()-1;
     if(x[0].l>=r||x[l].r<=l)
                              return 0;
     int i = 0;
     while(x[i].r<=l) i++;
     if(x[i].l>l||(i>0&&x[i-1].r<=x[i].l))
                   return 0;
     while(i<len&&x[i].r<r){
                     if(x[i].r<=x[i+1].l)
                                         return 0;
                     i++;
     }
     if(x[i].r<r) return 0;
     return 1;
}

bool chk(int i, int j, vector<interval> &x, vector<interval> &y){
     bool override = 0;
     if(rr[i].a>rr[j].b){
                          if(fulcover(rr[j].b,rr[i].a,x)==0)
                                                            return 1;
     }
     if(rr[i].b<rr[j].a){
                         if(fulcover(rr[i].b,rr[j].a,x)==0)
                                                           return 1;
     }
     if(rr[i].c>rr[j].d){
                         if(fulcover(rr[j].d,rr[i].c,y)==0)
                                                 return 1;
     }
     if(rr[i].d<rr[j].c){
                         if(fulcover(rr[i].d,rr[j].c,y)==0)
                                              return 1;
     }
     return 0;
}

int main(){
    cin >> T;
    while(T--){
               vector<interval> x,y;
               cin >> k >> p;
               
               if(p==1){
                        cout << "YES" << endl;
                        continue;
               }
               for(int i = 0; i < k; i++){
                       for(int j = 0; j < p; j++)
                               cin >> nn[i][j].x >> nn[i][j].y;
                       int a = min(nn[i][0].x,nn[i][1].x),b = max(nn[i][0].x,nn[i][1].x),c = min(nn[i][0].y,nn[i][1].y),d = max(nn[i][0].y,nn[i][1].y);
                       for(int j = 2; j < p; j++)
                               a = min(a,nn[i][j].x), b = max(b,nn[i][j].x), c = min(c,nn[i][j].y), d = max(d,nn[i][j].y);
                       rr[i].a = a, rr[i].b = b, rr[i].c = c, rr[i].d = d;
                       x.push_back(interval(a,b)), y.push_back(interval(c,d));
               }
               sort(x.begin(),x.end());
               sort(y.begin(),y.end());
               bool valid = 1;
               for(int i = 0; i < k&&valid; i++)
                       for(int j = i+1; j < k&&valid; j++)
                               if(inter(i,j))
                                             valid = 0;
                               else{
                                    if(chk(i,j,x,y)==0)
                                                   valid = 0;
                               }
                       
               if(valid) cout << "YES" << endl;
               else cout << "NO" << endl;
    }
}
