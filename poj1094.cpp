#include<iostream>
#include<string>
using namespace std;

int n,m,fa[30],d[30][30];
bool adj[30][30],reach[30][30], visit[30], findbad;
string sorted;

bool dfs(int p, int len, string s){
    if(len==n){
               sorted = s;
               return 1;
    }
    
    for(int i = 0; i < n; i++)
            if(adj[p][i]){
                          string t = s;
                          t.push_back('A'+i);
                          if(dfs(i,len+1,t))
                                          return 1;
            }
                          
    return 0;
}

int main(){
    while(cin>>n>>m&&(m||n)){
                             findbad = 0;
                             memset(reach,0,sizeof(reach));
                             memset(adj,0,sizeof(adj));
                             memset(d,0,sizeof(d));
                             int inconsist = 0, determin = 0;
                             for(int i = 0; i < m; i++){
                                     char s[4];
                                     cin >> s;
                                     int a = s[0]-'A', b = s[2]-'A';
                                     if(determin>0||findbad||reach[a][b]>0) continue;
                                     else if(reach[b][a]){
                                                                               findbad = 1;
                                                                               inconsist = i+1;
                                     }
                                     else if(determin==0){
                                          adj[a][b] = 1;
                                          reach[a][b] = 1;
                                          d[a][b] = max(d[a][b],1);
                                          for(int k = 0; k < n; k++)
                                          for(int ii = 0; ii < n; ii++)
                                                  for(int j = 0; j < n; j++)
                                                          if(reach[ii][k]&&reach[k][j]){
                                                                                        reach[ii][j] = 1;
                                                                                        d[ii][j] = max(d[ii][k]+d[k][j],d[ii][j]);
                                                          }
                                         int sr = -1;
                                         for(int ii = 0; ii < n; ii++)
                                                 for(int jj = 0; jj < n; jj++)
                                                 if(d[ii][jj]==n-1){
                                                                sr = ii;
                                                                break;
                                                 }
                                         //cout << sr << " " << num << endl;
                                         string s;
                                         s.push_back(sr+'A');
                                         if(sr>=0){
                                              dfs(sr,1,s);
                                              determin = i+1;
                                         }
                                     }
                             }
                             if(findbad)
                                        cout << "Inconsistency found after " << inconsist<<" relations." << endl;
                             else if(determin==0)
                                  cout << "Sorted sequence cannot be determined." << endl;
                             else
                                 cout << "Sorted sequence determined after " << determin << " relations: " << sorted<<'.' << endl;
    }
}
