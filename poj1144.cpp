#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int adj[101][101],n,tadj[101][101];
bool visit[101];

void delt(int p){
     memset(tadj,0,sizeof(tadj));
     for(int i = 1; i<= n; i++)
             for(int j = 1; j <= n; j++)
                     if(i!=p&&j!=p)
                                   tadj[i][j] = adj[i][j];
}

int atoi(string s){
    stringstream ss;
    ss<<s;
    int res;
    ss>>res;
    return res;
}

int dfs(int p){
    if(visit[p]) return 0;
    
    visit[p] = 1;
    int res = 1;
    for(int i = 1; i <= n; i++)
            if(tadj[p][i])
                          res+=dfs(i);
    return res;
}

int main(){
    while(cin >> n &&n){
              memset(adj,0,sizeof(adj));
              string s,temp;
              while(getline(cin,s)&&s!="0"){
                                            int i = 0,a,b;
                                            while(i<s.size()&&s[i]!=' ') temp.push_back(s[i]), i++;
                                            a = atoi(temp);
                                            temp.clear();
                                            while(i<s.size()){
                                                             if(s[i]==' '&&temp.size()>0)
                                                                        b = atoi(temp), adj[a][b] = adj[b][a] = 1, temp.clear();
                                                             else if(s[i]!=' ') temp.push_back(s[i]);
                                                             i++;
                                            }
                                            if(temp.size()>0) 
                                                              b = atoi(temp), adj[a][b] = adj[b][a] = 1, temp.clear();
                                            
              }
              int res = 0;
              for(int i = 1; i <= n; i++){
                    delt(i);
                    memset(visit,0,sizeof(visit));
                    if(dfs((i+1)%n==0?n:(i+1)%n)<n-1)
                                                     res++;
              }
              cout << res << endl;
    }
                                                                              
                                            
}         
