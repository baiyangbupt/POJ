#include<iostream>
#include <vector>
using namespace std;

int main(){
    int n,s;
    cin >> n >> s;
    vector<int> v(n);
    bool dp[200000];
    for(int i = 0; i < n; i++) cin >> v[i];
    
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    int res = 0x7fffffff;
    for(int i = 0; i < n; i++){
            for(int j = s; j >= 0; j--)
                    if(dp[j]){
                             if(j+v[i]>=s)
                                           res = min(j+v[i],res);
                             dp[j+v[i]] = 1;
                    }
    }
    
    cout << res-s << endl;
    system("pause");
} 
