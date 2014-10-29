#include<iostream>
#include<cmath>
using namespace std;
const int Max = 1005;
const double PI = 3.141592653;

struct point{
       double x, y;
};

int n, res[Max], t;
point pp[Max];

bool operator<(const point &a, const point &b){
     if(a.y==b.y) return a.x < b.x;
     return a.y < b.y;
}

double dis(point a, point b){
       double t = 1.0*(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
       return sqrt(t);
}

double multi(point p1, point p2, point p3){
    return (p1.x-p3.x)*(p2.y-p3.y)-(p1.y-p3.y)*(p2.x-p3.x);
}

void graham(){
     t = 1;
     if(n<3) return;
     
     sort(pp,pp+n);
     res[0] = 0, res[1] = 1, res[2] = 2;
     
     for(int i = 2; i < n; i++){
             while(t&&multi(pp[i],pp[res[t]],pp[res[t-1]])>=0) t--;
             res[++t] = i;
     }
     
     int len = t;
     res[++t] = n-2;
     for(int i = n-3; i>=0; i--){
             while(t!=len&&multi(pp[i],pp[res[t]],pp[res[t-1]])>=0) t--;
             res[++t] = i;
     }
}

int main(){
    double l;
    cin >> n >> l;
    double ans = 2*PI*l;
    for(int i = 0; i < n; i++)
            cin >> pp[i].x >> pp[i].y;
    
    graham();
    for(int i = 0; i < t-1; i++)
            ans+=dis(pp[res[i]],pp[res[i+1]]);
    ans+=dis(pp[res[0]],pp[res[t-1]]);
    printf("%.lf\n", ans);
    system("pause");
}
     
