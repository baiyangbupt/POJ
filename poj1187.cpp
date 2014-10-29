#include<iostream>
using namespace std;

int dp[11][11][11][31][31],combin[31][31];

void init(){
     int i,j;
     for(i = 1;  i < 31; i++){
             combin[i][0] = 1;
             for(j = 1; j <= i; j++)
                     combin[i][j] = combin[i][j-1]*(i-j+1)/j;
             //cout << i << " " << j-1 << " " << combin[i][j-1] << endl;
     }
}

int dfs(int l1, int l2, int l3, int d, int b){
    if(dp[l1][l2][l3][d][b]>=0) return dp[l1][l2][l3][d][b];
    
    int total = l1+l2+l3;
    if(b==0){
             if(total>0||d>0) return dp[l1][l2][l3][d][b] = 0;
             return dp[l1][l2][l3][d][b] = 1;
    }
    
    if(d==0){
             if(total>0) return dp[l1][l2][l3][d][b] = 0;
             return dp[l1][l2][l3][d][b] = 1;
    }
    
    if(total==0){
                 if(d>0) return dp[l1][l2][l3][d][b] = 0;
                 return dp[l1][l2][l3][d][b] = 1;
    }
    
    if(l1+l2+l3<d||b>l1+l2+l3-d+1) return dp[l1][l2][l3][d][b] = 0;
    
    if(b==1){
             int res = 0,tl1 = l1,tl2 = l2,tl3 = l3,td = d,tb = b;
             td = td-1;
             if(l1>0) tl1 = tl1-1;
             else if(l2>0) tl2 = tl2-1;
             else
                 tl3 = tl3-1;
             for(int blks = 0; blks <= total-1; blks++)
                     res += dfs(tl1,tl2,tl3,td,blks);
             
             return dp[l1][l2][l3][d][b] = res;
    }
    
    if(d==1){
             return dp[l1][l2][l3][1][b] = combin[total][l1]*combin[total-l1][l2];
    }
    
    int t = 0;
    for(int dep = 1; dep < d; dep++){
            for(int i1 = 0; i1 <= l1; i1++)
                    for(int i2 = 0; i2 <= l2; i2++)
                            for(int i3 = 0; i3 <= l3 && i1+i2+i3<=total-d; i3++){
                                    int t1 = dfs(i1,i2,i3,dep,1);
                                    int t2 = dfs(l1-i1,l2-i2,l3-i3,d,b-1);
                                    t += t1*t2;
                                    //cout << i1 << " " << i2 << " " << i3 <<" " << dep <<" " << 1 << " " << dp[i1][i2][i3][dep][1] << endl;
                                    //cout << l1-i1 << " " << l2-i2 << " " << l3-i3 << " " << d << " " << b-1 << " " << dp[l1-i1][l2-i2][l3-i3][d][b-1] << endl;
                            }
    }
    
    //cout << endl;
    for(int i1 = 0; i1 <= l1; i1++)
           for(int i2 = 0; i2<=l2; i2++)
                   for(int i3 = 0; i1+i2+i3>=d && i3 <= l3 ;i3++)
                           for(int dep = 0; dep <= d; dep++){
                                   int t1 = dfs(i1,i2,i3,d,1);
                                   int t2 = dfs(l1-i1, l2-i2, l3-i3, dep, b-1);
                                   t += t1*t2;
                                   //cout << i1 << " " << i2 << " " << i3 << " " << d << " " << 1 << " " << dp[i1][i2][i3][d][1] << endl;
                                    //cout << l1-i1 << " " << l2-i2 << " " << l3-i3 << " " <<dep << " " << b-1 << " " << dp[l1-i1][l2-i2][l3-i3][dep][b-1] << endl;
                           }
    
    return dp[l1][l2][l3][d][b] = t;
}
    
    
    
int main(){
    init();
    int l1,l2,l3,d;
    while(cin>>l1>>l2>>l3>>d){
                              
                              memset(dp,-1,sizeof(dp));
                             int res = 0;
                              for(int b = 1; b <= l1+l2+l3; b++){
                                      res += dfs(l1,l2,l3,d,b);
                                      //cout << b << " " << res << endl;
                              }
                              cout << res << endl;
    }
}
