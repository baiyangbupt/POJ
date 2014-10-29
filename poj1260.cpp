#include<iostream>
using namespace std;

int price[101],dp[101],need[101];

int main(){
    int nc,n;
    cin >> nc;
    while(nc--){
                cin >> n;
                for(int i = 1; i <= n; i++)
                        cin >> need[i] >> price[i];
                
                dp[0] = 0;
                
                for(int i = 1; i <= n; i++){
                        int m = 0x7fffffff, t = 10*price[i];
                        for(int j = i; j >= 1; j--){
                                t+=need[j]*price[i];
                                m = min(m,t+dp[j-1]);
                        }
                        dp[i] = m;
                }
                cout << dp[n] << endl;
    }
}
