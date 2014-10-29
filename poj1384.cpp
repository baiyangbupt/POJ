#include<iostream>
using namespace std;

int dp[10001], n, w[501], p[501];
const int inf = 1000000000;

int main(){
    int nc;
    cin >> nc;
    while(nc--){
                int st, ed, weight;
                cin >> st >> ed;
                weight = ed-st;
                cin >> n;
                for(int i = 0; i < n; i++)
                        cin >> p[i] >> w[i];
                
                for(int i = 1; i <= weight; i++)
                        dp[i] = inf;
                dp[0] = 0;
                for(int i = 0; i < n; i++){
                        for(int j = w[i]; j <= weight; j++)
                                dp[j] = min(dp[j-w[i]]+p[i],dp[j]);
                }
                
                if(dp[weight]==inf)
                                   cout << "This is impossible." << endl;
                else
                    cout << "The minimum amount of money in the piggy-bank is " << dp[weight]<< '.' << endl;
    }
}
    
