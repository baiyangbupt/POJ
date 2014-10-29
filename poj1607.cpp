#include<iostream>
using namespace std;


double dp[100000];

void solve(){
     dp[0] = 0.;
     dp[1] = 0.5;
     for(int i = 2; i <= 99999; i++){
             double t = 0.5+dp[i-1]/i;
             dp[i] = dp[i-1]+t;
             //cout << i << ' ' << dp[i]-dp[i-1] << endl;
     }
}

int main(){
    solve();
    int n;
    cout << "Cards  Overhang" << endl;
    while(cin>>n)
                  printf("%5d %9.3lf\n", n, dp[n]-dp[n-1]);
    //system("pause");
}
     
