#include<iostream>
using namespace std;

long long dpp[20][2], dp[20];


int main(){
    dpp[3][0]=8,dpp[3][1]=8;
    for(int i = 4; i < 18; i++){
            dpp[i][0] = 2*(dpp[i-1][0]+dpp[i-1][1]);
            dpp[i][1] = dpp[i-1][0]*2+dpp[i-1][1];
    }
    dp[3] = 8;
    int der = 1<<5;
    for(int i = 4; i < 18; i++,der<<=1)
            dp[i] = 4*dp[i-1]+der-8+dpp[i-1][1];
    int n;
    while(cin>>n&&n!=-1){
                         cout << n << ": ";
                         if(n<3){
                                 cout << 0 << endl;
                                 continue;
                         }
                         cout << dp[n] << endl;
    }
}
    
