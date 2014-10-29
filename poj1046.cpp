#include<iostream>
#include<string>
#include<cmath>

using namespace std;

struct node{
       int x,y,z;
};
node nn[17];

double dis(const node &a, const node &b){
       return sqrt((a.x-b.x)*1.*(a.x-b.x)+(a.y-b.y)*1.*(a.y-b.y)+(a.z-b.z)*1.*(a.z-b.z));
}

int main(){
    int x,y,z;
    for(int i = 1; i <= 16; i++)
            cin>> nn[i].x>> nn[i].y >> nn[i].z;
            
    while(cin>>x>>y>>z&&x!=-1){
                               double d = 10000;
                               int res = 0;
                               node n;
                               n.x = x, n.y = y, n.z = z;
                               for(int i = 1; i <= 16; i++)
                                       if(dis(nn[i],n)<d)
                                                         res = i, d = dis(nn[i],n);
                               
                               cout << "("<<x<<","<<y<<","<<z<<") maps to (" << nn[res].x << "," << nn[res].y << "," << nn[res].z <<")" <<endl;
    }
}
