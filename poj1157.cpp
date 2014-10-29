#include<iostream>

using namespace std;

int a[101][101], dp[101][101], f,v;

int main(){
    cin >> f >> v;
    for(int i = 1; i <= f; i++)
            for(int j = 1; j <= v; j++)
                    cin >> a[i][j];
            
    memset(dp,0,sizeof(dp));
    dp[1][1] = a[1][1];
    
    for(int i = 2; i <= v; i++)
            for(int j = 1; j <= i; j++){
                    int t = -100000;
                    for(int k = j-1; k < i; k++)
                            t = max(dp[k][j-1],t);
                    
                    dp[i][j] = t+a[j][i];
    }
    
    int res = 0;
    for(int i = f;  i<= v; i++)
            res = max(dp[i][f], res);
    
    cout << res << endl;
    system("pause");
}
