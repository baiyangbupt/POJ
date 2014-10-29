#include<iostream>
#include<iomanip>
using namespace std;

double dp[101][101];
int n;

void solve(){
     dp[1][1] = 1;
     for(int i = 2; i <= 100; i++){
             dp[i][1] = 1;
             for(int j = 2; j <= i; j++){
                     dp[i][j] = dp[i-1][j]*j+dp[i-1][j-1];
             }
     }
}

int main(){
    solve();
    while(cin>>n,n){
                    double res = 0;
                    for(int i = 1; i <= n; i++)
                            res+=dp[n][i];
                    printf("%d %.0f\n",n,res);
    }
}
