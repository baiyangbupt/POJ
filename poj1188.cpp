#include<iostream>
using namespace std;

struct point{
       int x, y;
};

struct cube{
       int x[2], y[2], z[2];
       void getcube(int a, int b, int c, int len){
                x[0] = a, y[0] = b, z[0] = c;
                x[1] = a+len, y[1] = b+len, z[1] = c+len;
       }
}cc[1001];

int n;

int intersect(cube a, cube b, cube &c){
     if(a.x[0]>=b.x[1]||a.x[1]<=b.x[0]||a.y[0]>=b.y[1]||a.y[1]<=b.y[0]||a.z[0]>=b.z[1]||a.z[1]<=b.z[0])
                                                                                                       return 0;
     
     c.x[0] = max(a.x[0],b.x[0]), c.x[1] = min(a.x[1],b.x[1]);
     c.y[0] = max(a.y[0],b.y[0]), c.y[1] = min(a.y[1],b.y[1]);
     c.z[0] = max(a.z[0],b.z[0]), c.z[1] = min(a.z[1],b.z[1]);
     return 1;
}

int vol(cube c){
    return (c.x[1]-c.x[0])*(c.y[1]-c.y[0])*(c.z[1]-c.z[0]);
}

int main(){
    while(cin>>n&&n){
                     int x,y,z,l;
                     for(int i = 0; i < n; i++){
                             cin >> x >> y >> z >> l;
                             cc[i].getcube(x,y,z,l);
                     }
                     
                     cube t = cc[0];
                     int res = 0, i;
                     for(i = 1; i < n; i++){
                             cube temp = t;
                             if(intersect(temp,cc[i],t)==0)
                                                           break;
                     }
                     
                     if(i<n) res = 0;
                     else res = vol(t);
                     cout << res <<  endl;
    }
}
