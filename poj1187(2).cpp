#include<iostream>
using namespace std;

int dp[11][11][11][33];
int ll1, ll2, ll3, dd, m = 11380;

int dfs(int l1, int l2, int l3, int d){
    if(dp[l1][l2][l3][d]>=0) return dp[l1][l2][l3][d];
    
    if(l1==0&&l2==0&&l3==0) return dp[l1][l2][l3][d] = 1;
    
    if(d==0)
            return dp[l1][l2][l3][d] = 0;
    
    int res = 0;
    for(int i1 = 0; i1 <= l3; i1++){
           if(i1){
                  res += (dfs(0,0,i1-1,d-1)*dfs(l1,l2,l3-i1,d))%m;
                  res %= m;
           }
                  
           for(int i2 = 0; i2 <= l2; i2++){
                   if(i2){
                         res += (dfs(0,i2-1,i1,d-1)*dfs(l1,l2-i2,l3-i1,d))%m;
                         res %= m;
                   }
                   
                   for(int i3 = 1; i3 <= l1; i3++){
                           res += (dfs(i3-1,i2,i1,d-1)*dfs(l1-i3,l2-i2,l3-i1,d))%m;
                           res %= m;
                   }
           }
    }
    
    return dp[l1][l2][l3][d] = res;
}
                           
                                 
                                 

int main(){
    memset(dp,-1,sizeof(dp));
    cout << -1%12 << endl;

    while(cin>>ll1>>ll2>>ll3>>dd){
                              if(dd==0){
                                       if(ll1+ll2+ll3>0) cout << 0 << endl;
                                       else cout << 1 << endl;
                                       continue;
                              } 
                              dfs(ll1,ll2,ll3,dd);
                              dfs(ll1,ll2,ll3,dd-1);
                              cout<<(((dp[ll1][ll2][ll3][dd] - dp[ll1][ll2][ll3][dd-1])%m+m)%m) << endl;
    }
}
