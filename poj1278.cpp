#include<iostream>
#include<algorithm>
using namespace std;

struct node{
       int id,money,deadline;
}nn[10010];

bool operator<(const node &a, const node &b){
     return a.id<b.id;
}

int n,d[100],m,dp[10010],t[10010];

int main(){
    while(cin>>n){
            memset(dp,0,sizeof(dp));
            for(int i = 1; i <= n; i++)
                    cin >> d[i];
            
            cin >> m;
            for(int i = 1; i <= m; i++)
                    cin >> nn[i].id >> nn[i].deadline >> nn[i].money;
            
            nn[0].id = nn[0].money = nn[0].deadline = 0;
            
            sort(nn,nn+m);
            memset(dp,0,sizeof(dp));
            
            int res = 0,st = 1, p = 1;
            for(int i = 1; i < m; i++){
                    if(nn[i].id>p){
                                   st = i;
                                   p = nn[i].id;
                    }
                    
                    int id = nn[i].id, deadline = nn[i].deadline, money = nn[i].money;
                    for(int j = 0; j < st; j++){
                            if(t[j]+d[id]<=nn[i].deadline&&dp[i]<dp[j]+money){
                                                                                 dp[i] = dp[j]+money;
                                                                                 t[i] = t[j]+d[id];
                            }
                    }
                    res = max(res,dp[i]);
            }
            cout << res << endl;
            cout << endl;
    }
}
    
