#include<iostream>
#include<string>
using namespace std;

int n,m;
bool adj[101][101], visit[101];

bool dfs(int p, int src){
     if(visit[p]&&p==src)
                         return 0;
     if(visit[p])
                 return 1;
     visit[p] = 1;
     for(int i = 0; i <= n; i++)
             if(adj[p][i]){
                           if(dfs(i,src)==0)
                                            return 0;
             }
     return 1;
}
                          

int main(){
    while(cin>>n&&n){
                     int s,nn,k;
                     string o;
                     cin >> m;
                     memset(adj,0,sizeof(adj));
                     for(int i = 0; i < m; i++){
                             string t;
                             cin >> s >> nn >> o>>k;
                             if(o=="gt")
                                        adj[s+nn][s-1] = 1;
                             else
                                 adj[s-1][s+nn] = 1;
                     }
                     
                     bool valid = 1;
                     for(int i = 0; i <= n; i++){
                             memset(visit,0,sizeof(visit));
                             if(dfs(i,i)==0){
                                           valid = 0;
                                           break;
                             }
                     }
                     if(valid==0)
                                 cout << "successful conspiracy" << endl;
                     else
                         cout << "lamentable kingdom" << endl;
    }
}
                             
