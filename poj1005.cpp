#include<iostream>
#include<cmath>
using namespace std; 

const float PI = acos(-1.0);

int main(){
    int n, count = 1, res;
    cin >> n;
    float x, y;
    while(n--){
               cin >> x >> y;
               res = PI*(x*x+y*y)/100+0.9999;
               cout << "Property "<<count<<": This property will begin eroding in year "<<res <<"." << endl;
               count++;
    }
    cout <<"END OF OUTPUT." << endl;
}
