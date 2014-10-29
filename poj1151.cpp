#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double area(double x1, double y1, double x2, double y2){
       return abs(x1-x2)*abs(y1-y2);
}

double intersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){
       if(min(x1,x2)>=max(x3,x4)||max(x1,x2)<=min(x3,x4)||min(y1,y2)>=max(y3,y4)||min(y3,y4)>=max(y1,y2))
                                                                                                         return 0;
       
       double a1 = min(x1,x2), b1 = max(x1,x2), c1 = min(y1,y2), d1 = max(y1,y2), a2 = min(x3,x4), b2 = max(x3,x4), c2 = min(y3,y4), d2 = max(y3,y4);
       double l1 = min(b1,b2) - max(a1,a2), l2 = min(d1,d2) - max(c1,c2);
       
       return l1*l2;
}


double x[105][2], y[105][2];
int main(){
       int n,ca = 1;
       while(cin>>n && n){
                    double res = 0;
                    for(int i = 0; i < n; i++){
                            cin >> x[i][0] >> y[i][0] >> x[i][1] >> y[i][1];
                            res += area(x[i][0], y[i][0], x[i][1], y[i][1]);
                    }
                    
                    for(int i = 0; i < n; i++)
                            for(int j = i+1; j < n; j++)
                                    res -= intersect(x[i][0], y[i][0], x[i][1], y[i][1], x[j][0], y[j][0], x[j][1], y[j][1]);
                    cout << "Test case #" << ca++ << endl;
                    cout << "Total explored area: " <<setiosflags(ios::fixed) << setprecision(2) <<res << endl;
                    cout << endl;
       }
                            
                    
                    }
