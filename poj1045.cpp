#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;


int main(){
    double r,c,w,vs;
    int n;
    cin >> vs >> r >> c >> n;
    while(n--){
               cin >> w;
               cout << setprecision(3) <<std::fixed << vs*r*c*w/sqrt(r*r*c*c*w*w+1) << endl;
    }
}
