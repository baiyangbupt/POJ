#include<iostream>
#include<algorithm>
using namespace std;


int dp[10001][2], aa[10001], n, a, b;

int dfs(int p, int person){
    if(p==n)
            return 0;
    
    if(dp[p][person]>-100000)
                             return dp[p][person];
                             
    int score = aa[p], res = -100000;
    
    int i = p+1;
    while(i<n&&aa[i]<score+a)
                             i++;
    if(i==n)
            return dp[p][person] = score;
    
    while(i<n&&aa[i]<=score+b)
                              res = max(res,dfs(i,1-person)), i++;
    
    return dp[p][person] = score-res;
}

int main(){
    int nc;
    cin >> nc;
    while(nc--){
                cin >> n >> a >> b;
                for(int i = 0; i < n; i++)
                        cin >> aa[i];
                sort(aa,aa+n);
                
                for(int i = 0; i < n; i++)
                        dp[i][0] = dp[i][1] = -100000;
                
                int i = 0;
                while(i<n&&aa[i]<a)
                                   i++;
                int res = -100000;
                while(i<n&&aa[i]<=b)  
                                      res = max(res,dfs(i,0)), i++;
                if(res==-100000)
                                cout << 0 << endl;
                else
                    cout << res << endl;
    }
}
