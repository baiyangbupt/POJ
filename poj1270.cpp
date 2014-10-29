#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool adj[30][30],visit[30];
int id[256],n,antiid[20];

bool test(int p){
     for(int i = 0; i < n; i++)
             if(adj[i][p])
                          return 0;
     return 1;
}

void reduce(int p){
     for(int i = 0; i < n; i++)
             adj[p][i] = 0;
}

vector<string> res;

void dfs(string s){
     if(s.size()==n){
                     res.push_back(s);
                     return;
     }
     
     for(int i = 0; i < n; i++)
             if(visit[i]==0&&test(i)){
                         string t = s;
                         visit[i] = 1;
                         bool tadj[30][30];
                         for(int ii = 0; ii < n; ii++)
                                 for(int j = 0; j < n; j++)
                                         tadj[ii][j] = adj[ii][j];
                         reduce(i);
                         t.push_back(antiid[i]);
                         dfs(t);
                         visit[i] = 0;
                         for(int ii = 0; ii < n; ii++)
                                 for(int j = 0; j < n; j++)
                                         adj[ii][j] = tadj[ii][j];
             }
}
                         

int main(){
    string s;
    while(getline(cin,s)){
                          memset(adj,0,sizeof(adj));
                          memset(visit,0,sizeof(visit));
                          int p = 0;
                          for(int i = 0; i < s.size(); i++)
                                  if(s[i]!=' ')
                                             id[s[i]] = p, antiid[p] = s[i], p++;
                          n = p;
                          
                          getline(cin,s);
                          int u,v;
                          p = 0;
                          for(int i = 0; i < s.size(); i++)
                                  if(s[i]!=' '){
                                             if(p%2)
                                                    v = id[s[i]], adj[u][v] = 1;
                                             else
                                                 u = id[s[i]];
                                             p++;
                                  }
                          string t;
                          res.clear();
                          dfs(t);
                          sort(res.begin(), res.end());
                          for(int i = 0; i< res.size(); i++)
                                  cout << res[i] << endl;
                          cout << endl;
    }
}
                          
                          
