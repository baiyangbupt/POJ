#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int cnt = 1;
    int a1 = 1,b1 = 1,a2 = 6, b2 = 8, na,nb;
    //printf ("%10d%10d\n", a1, b1);
    printf ("%10d%10d\n", a2, b2);
    while(cnt<10){
                  int x1 = 2*b1+1, y1 = 2*a1, x2 = 2*b2+1, y2 = 2*a2;
                  int p = x1*x2+2*y1*y2, q = x2*y1+x1*y2;
                  na = q/2, nb = (p-1)/2;
                  a2 = na, b2 = nb;
                  printf ("%10d%10d\n", a2, b2);
                  cnt++;
    }
    system("pause");
}
