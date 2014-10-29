#include<iostream>
#include<string>
using namespace std;

bool adj[22][22],getmsg[22][101],reach[22][22];
int t1[101],t2[101],p[101],n,m,d[22];
string mark[101][3],name[22];

void dfs(int r, int msgnum){
     if(getmsg[r][msgnum]) return;
     
     getmsg[r][msgnum] = 1;
     for(int i = 1; i <= n; i++)
             if(adj[r][i])
                          dfs(i,msgnum);
}

int main(){
    while(cin >> n && n){
              memset(adj,0,sizeof(adj));
              memset(getmsg,0,sizeof(getmsg));
              memset(d,0,sizeof(d));
              for(int i = 1; i <= n; i++){
                      int t;
                      while(cin>>t&&t)
                                      adj[i][t] = 1;
              }
              m = 0;
              int tp;
              while(cin >> tp&&tp){
                        p[m] = tp;
                        cin >> t1[m] >> t2[m] >> mark[m][0] >> mark[m][1] >> mark[m][2];
                        m++;
              }
              for(int i = 1; i <= n; i++)
                      cin >> name[i];
              
              for(int i = 1; i <= n; i++){
                      int t = 0;
                      for(int j = 1; j <= n; j++)
                              t+=adj[i][j];
                      d[i] = t;
              }
              
              for(int i = 0; i < m; i++)
                      dfs(p[i],i);
              
              for(int i = 1; i <= n; i++){
                      cout << name[i] << ":";
                      for(int j = 0; j < m; j++)
                              if(getmsg[i][j]){
                                               string str;
                                               if(d[i]<t1[j]) str = mark[j][0];
                                               else if(d[i]<t2[j]) str = mark[j][1];
                                               else str = mark[j][2];
                                               cout << " " << str;
                              }
                              else
                                  cout << " " << mark[j][0];
                      cout << endl;
              }
    }
}
              
              
                              
