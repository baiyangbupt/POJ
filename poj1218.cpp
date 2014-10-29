#include<iostream>
using namespace std;

int fac[101];

void init(){
     memset(fac,0,sizeof(fac));
     for(int i = 1; i <= 100; i++){
             int t = i;
             while(t<=100)
                          fac[t]++, t+=i;
     }
}

int main(){
    int nc;
    init();
    cin >> nc;
    for(int i = 0; i< nc; i++){
            int n,res = 0;
            cin >> n;
            for(int i = 1; i <= n; i++)
                    if(fac[i]%2)
                                res++;
            cout << res << endl;
    }
}
