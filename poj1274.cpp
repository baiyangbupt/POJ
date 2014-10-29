#include<iostream>
using namespace std;

int adj[201][201], n, m, match[201], postmatch[201];
bool visit[201];

bool dfs(int p){
     for(int i = 1; i <= m; i++)
             if(adj[p][i]&&visit[i]==0){
                                        visit[i] = 1;
                                        if(match[i]==-1||dfs(match[i])){
                                                                        match[i] = p;
                                                                        postmatch[p] = i;
                                                                        return 1;
                                        }
             }
     return 0;
}

int main(){
    while(cin>>n>>m){
                     memset(adj,0,sizeof(adj));
                     memset(postmatch,-1,sizeof(postmatch));
                     memset(match,-1,sizeof(match));
                     for(int i = 1; i <= n; i++){
                             int t,y;
                             cin >> t;
                             for(int j = 0; j < t; j++){
                                     cin >> y;
                                     adj[i][y] = 1;
                             }
                     }
                     int res = 0;
                     for(int i = 1; i <= n; i++)
                             if(postmatch[i]==-1){
                                                  memset(visit,0,sizeof(visit));
                                                  if(dfs(i))
                                                           res++;
                             }
                     cout << res << endl;
    }
}
     
