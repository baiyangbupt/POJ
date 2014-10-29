#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

struct node{
       double x,y;
};

int n;

double area(node p1, node p2, node p3){
       double res = 0;
       res = p1.x*p2.y+p2.x*p3.y+p3.x*p1.y-p2.x*p1.y-p3.x*p2.y-p1.x*p3.y;
       return res/2;
}

int main(){
    int nc;
    cin >> nc;
    while(nc--){
                cin >> n;
                node p1, p2 ,p3;
                cin >> p1.x >> p1.y >> p2.x >> p2.y;
                double sumarea = 0, resx = 0, resy = 0;
                
                for(int i = 2; i < n; i++){
                        cin >> p3.x >> p3.y;
                        double a = area(p1,p2,p3);
                        sumarea+=a;
                        resx+=(p1.x+p2.x+p3.x)*a;
                        resy+=(p1.y+p2.y+p3.y)*a;
                        p2 = p3;
                }
                resx /= sumarea*3, resy /= sumarea*3;
                cout << setiosflags(ios::fixed) << setprecision(2) << resx << ' ' << resy << endl;
    }
}
