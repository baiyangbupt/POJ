#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

const double PI = 3.141592653589793238;
       
int main(){
    double x,y;
    int nc;
    cin >> nc;
    while(nc--){
                //cout << PI << endl;
                double x1,y1,x2,y2,theta1,theta2;
                cin >> x1 >> y1 >> theta1 >> x2 >> y2 >> theta2;
                
                if(theta1==180||theta1==0){
                                           theta2 = 450-theta2;
                                           x = x1;
                                           y = y2+(x-x2)*tan(theta2/180*PI);
                }
                else if(theta2==180||theta2==0){
                     theta1 = 450-theta1;
                     x = x2;
                     y = y1+(x-x1)*tan(theta1/180*PI);
                }
                else{
                     theta2 = 450-theta2, theta1 = 450-theta1;
                     double k1 = tan(theta1/180*PI), k2 = tan(theta2/180*PI);
                     x = (y2-y1+k1*x1-k2*x2)/(k1-k2);
                     y = y1+(x-x1)*k1;
                }
                //x += 0.00005, y+=0.00005;
                cout << setiosflags(ios::fixed) << setprecision(4) << x <<" " << y << endl;
    }
}
