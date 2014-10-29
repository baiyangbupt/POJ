#include<iostream>
#include<string>

using namespace std;

string s;
int dp[300][300];

int dfs(int i, int j){
     if(dp[i][j]>0) return dp[i][j];
     if(i==j) return dp[i][j] = s[i]<='z'&&s[i]>='p';
     
     if(s[i]=='N')
                  return dp[i][j] = dfs(i+1,j);
     
     if(s[i]=='C'||s[i]=='D'||s[i]=='E'||s[i]=='I'){
                                                    for(int k = i+1; k < j; k++)
                                                            if(dfs(i+1,k)&&dfs(k+1,j))
                                                                                     return dp[i][j] = 1;
     }
     return dp[i][j] = 0;
}
     
     

int main(){
    while(cin>>s){
                  memset(dp,-1,sizeof(dp));
                  if(dfs(0,s.size()-1)) cout << "YES" << endl;
                  else cout << "NO" << endl;
    }
}
