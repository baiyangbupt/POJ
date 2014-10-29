#include<iostream>
#include<cmath>
#include<iomanip>
#define eps 1e-6
using namespace std;

struct point{
       double x,y;
}pp[3];

void solve(){
     bool getx = 0;
     double x,y;
     double a1 = pp[1].x-pp[0].x, b1 = (pp[0].x+pp[1].x)/2, c1 = pp[1].y-pp[0].y, d1 = (pp[0].y+pp[1].y)/2;
     if(abs(c1)<eps)
                   x = b1, getx = 1;
     double a2 = pp[2].x-pp[0].x, b2 = (pp[0].x+pp[2].x)/2, c2 = pp[2].y-pp[0].y, d2 = (pp[0].y+pp[2].y)/2;
     if(getx)
             y = -1*a2*(x-b2)/c2+d2;
     else if(abs(c2)<eps){
          x = b2;
          y = -1*a1*(x-b1)/c1+d1;
     }
     else{
          a1/=c1, a2/=c2;
          x = (d1-d2+a1*b1-a2*b2)/(a1-a2);
          y = d1 - a1*(x-b1);
     }
     double r = sqrt((pp[0].x-x)*(pp[0].x-x)+(pp[0].y-y)*(pp[0].y-y)), re = x*x+y*y-r*r;
     cout << setiosflags(ios::fixed) << setprecision(3) << "(x " << (x>0?"- ":"+ ") << abs(x) << ")^2 + (y " << (y>0?"- ":"+ ")\
     << abs(y)<< ")^2 = " << r << "^2" << endl;
     cout << "x^2 + y^2 " <<(x>0?"- ":"+ ") << 2*abs(x) << "x " << (y>0?"- ":"+ ") << 2*abs(y) << "y " <<(re>0?"+ ":"- ") << abs(re) << " = 0"<< endl;
     cout << endl;
}
          

int main(){
    while(cin>>pp[0].x>>pp[0].y>>pp[1].x>>pp[1].y>>pp[2].x>>pp[2].y)
                                                                     solve();
}
