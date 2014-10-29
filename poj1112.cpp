#include<iostream>
using namespace std;

bool adj[105][105],over;
int n,team[102],dif,finalteam[102],cnt[3],finalcnt1,finalcnt2;


void dfs(int p){
     if(cnt[1]>cnt[2]&&dif<=2*cnt[1]-n||cnt[2]>cnt[1]&&dif<=2*cnt[2]-n) return;
     
     if(p==n+1){
                if(dif>max(cnt[1]-cnt[2],cnt[2]-cnt[1])){
                                                 for(int i = 1; i <= n; i++)
                                                         finalteam[i] = team[i];
                                                 dif = max(cnt[1]-cnt[2],cnt[2]-cnt[1]);
                                                 finalcnt1 = cnt[1], finalcnt2 = cnt[2];
                }
                
                return;
     }
     
     for(int group = 1; group <= 2; group++){
             bool valid = 1;
             for(int i = 1; i < p && valid; i++)
                     if(team[i]==group&&(adj[i][p]==0||adj[p][i]==0))
                                                                     valid = 0;
             for(int i = 1; i <= n && valid; i++)
                     if(i!=p&&(adj[i][p]==0||adj[p][i]==0)){
                                                    for(int j = 1; j < p && valid; j++)
                                                            if(i!=j&&team[j]==3-group&&(adj[i][j]==0||adj[j][i]==0))
                                                                                                              valid = 0;
                     }
             if(valid){
                       cnt[group]++;
                       team[p] = group;
                       dfs(p+1);
                       cnt[group]--;
                       team[p] = 0;
             }
     }
}

int main(){
    cin >> n;
    dif = 10000000;
    over = 0;
    cnt[1] = cnt[2] = 0;
    memset(adj,0,sizeof(adj));
    memset(team,0,sizeof(team));
    for(int i = 1; i <= n; i++){
            int t;
            while(cin>>t&&t){
                             adj[i][t] = 1;
            }
    }
    dfs(1);

    if(dif<10000000){
        cout << finalcnt1;
        for(int i = 1; i <= n; i++)
                if(finalteam[i]==1) cout << " " << i;
        cout << endl;
        cout << finalcnt2;
        for(int i = 1; i <= n; i++)
                if(finalteam[i]==2) cout << " " << i;
        cout << endl;
    }
    else cout << "No solution" << endl;
    system("pause");
}
            
    
    
    
    
    
    
