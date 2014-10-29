#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int Max = 1005;
const double PI = 3.141592653;
 
struct Point{
    double x, y;
}p[Max];
int n, res[Max], top;
 
bool operator < (const Point &a, const Point &b){
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}
 
double mult(Point sp, Point ep, Point op){
    return (sp.x-op.x)*(ep.y-op.y) - (ep.x-op.x)*(sp.y-op.y);
}
 
double mydis(int i, int j){
    double a = p[i].x - p[j].x;
    double b = p[i].y - p[j].y;
    return sqrt(a*a + b*b);
}
 
void Graham(){
    int i, len;
    top = 1;
    sort(p, p+n);
    for(i = 0; i < 3; i ++) res[i] = i;
    for(i = 2; i < n; i ++){
        while(top && mult(p[i], p[res[top]], p[res[top-1]]) >= 0) top --;
        res[++ top] = i;
    }
    len = top;
    res[++ top] = n-2;
    for(i = n - 3; i >= 0; i --){
        while(top != len && mult(p[i], p[res[top]], p[res[top-1]]) >= 0) top --;
        res[++ top] = i;
    }
}
 
int main(){
    int i;
    double r, ans;
    scanf("%d%lf", &n, &r);
    for(i = 0; i < n; i ++)
        scanf("%lf%lf", &p[i].x, &p[i].y);
    Graham();
    ans = 2 * PI * r;
    for(i = 0; i < top-1; i ++)
        ans += mydis(res[i], res[i+1]);
    ans += mydis(res[0], res[top-1]);
    printf("%.lf\n", ans);
    system("pause");
    return 0;
}
