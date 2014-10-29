#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

struct point{
       int x, y;
}pp[1001];

struct interval{
       double l,r;
}nn[1001];

bool operator<(const interval &a, const interval &b){
     return a.l<b.l;
}

int n,d;

int main(){
    int nc = 1;
    while(cin>>n>>d&&n){
                        bool valid = 1;
                        for(int i = 0; i < n; i++)
                                cin >> pp[i].x >> pp[i].y;
                        for(int i = 0; i < n; i++){
                                if(d<=0||pp[i].y<0||d*d<pp[i].y*pp[i].y){
                                                        valid = 0;
                                                        break;
                                }
                                double dx = sqrt(d*d*1.0-pp[i].y*pp[i].y*1.0);
                                nn[i].l = pp[i].x-dx, nn[i].r = pp[i].x+dx;
                        }
                        
                        if(valid==0){
                                     cout << "Case " << nc++ << ": " << -1 << endl;
                                     continue;
                        }
                        sort(nn,nn+n);
                        double l = nn[0].l, r = nn[0].r;
                        int res = 1;
                        for(int i = 1; i < n; i++)
                                if(nn[i].l>r){
                                              res++;
                                              l = nn[i].l, r = nn[i].r;
                                }
                                else
                                    l = max(l,nn[i].l), r = min(r,nn[i].r);
                        cout << "Case " << nc++ << ": " <<res << endl;
    }
}
