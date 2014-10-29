#include<iostream>
#include<algorithm>
using namespace std;

struct node{
       int t,p,s;
};

bool cmp(const node &a, const node &b){
     return a.t < b.t;
}

int n,k,t;
int dp[101],in[101];
node nn[101];

int main(){
    cin >> n >> k >> t;
    for(int i = 1; i <= n; i++) cin >> nn[i].t;
    for(int i = 1; i <= n; i++) cin >> nn[i].p;
    for(int i = 1; i <= n; i++) cin >> nn[i].s;
    memset(dp,0,sizeof(dp));
    memset(in,0,sizeof(in));
    sort(nn+1,nn+n+1,cmp);
    
    if(nn[1].t>=nn[1].s) dp[1] = nn[1].p, in[1] = 1;
    int i;
    for(i = 2; i <= n; i++){
          int m = 0;
          for(int j = 1; j < i; j++){
                  int ds = nn[i].s>nn[j].s?nn[i].s-nn[j].s:nn[j].s-nn[i].s;
                  if(nn[i].t-nn[j].t>=ds&&in[j])
                                                m = max(m,dp[j]);
          }
          if(nn[i].s<=nn[i].t) dp[i] = nn[i].p, in[i] = 1;
          if(m>0)
                 dp[i]+=m;
                 
    }
    
    int res = 0;
    for(int j = 1; j <= n; j++)
            res = max(res,dp[j]);
    cout << res << endl;
    system("pause");
}
