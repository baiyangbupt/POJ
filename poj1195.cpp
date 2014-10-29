#include<iostream>
using namespace std;

const int MAX = 1025;
int n, c[MAX][MAX];

int lowbit(int x){
    return x&(-x);
}

void update(int x, int y, int inc){
      while(x<=n)
                  c[x][y]+=inc, x+=lowbit(x);
}

void query(int x1, int x2, int y1, int y2){
     int res = 0;
     for(int y = y1; y <= y2; y++){
             int t1 = x2;
             while(t1>0)
                         res += c[t1][y], t1-=lowbit(t1);
             int t2 = x1-1;
             while(t2>0)
                        res -= c[t2][y], t2-=lowbit(t2);
     }
     cout << res << endl;
}

int main(){
    int cmd,x,y,a,xx,yy;
    while(cin>>cmd&&cmd!=3){
                            if(cmd==0){
                                       cin >> n;
                                       n = n+1;
                                       continue;
                            }
                            if(cmd==1){
                                       cin >> x >> y >> a;
                                       x = x+1;
                                       update(x,y,a);
                                       continue;
                            }
                            cin >> x >> y >> xx >> yy;
                            query(x+1,xx+1,y,yy);
    }
}
