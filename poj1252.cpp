#include<iostream>
#include<iomanip>
using namespace std;

int dp[20001], a[13];

int main() {
    int nc;
    cin >> nc;
    while(nc--){
            for(int j = 1; j < 7; j++){
                    cin >> a[j];
                    //a[j]+=100;
            }
            for(int j = 7; j < 13; j++)
                    a[j] = -a[j-6];
            
            for(int i = 0; i < 20001; i++)
                    dp[i] = 100000;
            dp[10000] = 0;
            
            for(int i = 1; i < 7; i++)
                    for(int j = a[i]; j < 20001; j++)
                            dp[j] = min(dp[j],dp[j-a[i]]+1);
            for(int i = 7; i < 13; i++)
                    for(int j = 20000+a[i]; j >= 0; j--)
                            dp[j] = min(dp[j],dp[j-a[i]]+1);
            
            int total = 0, mm = 0;
            for(int i = 10001; i <= 10100; i++)
                    total+=dp[i], mm = max(mm,dp[i]);
            cout <<setiosflags(ios::fixed) << setprecision(2)<< total/100. << " " << mm << endl;
    }
}
