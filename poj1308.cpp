#include<iostream>
#include<map>
using namespace std;

bool adj[1000][1000],visit[1000];
int edges[1000][2],fa[1000],nn;
map<int,int> mp;

bool dfs(int p){
     //cout << p << endl;
     if(visit[p])
                 return 0;
     
     visit[p] = 1;
     for(int i = 0; i < nn; i++)
             if(adj[p][i]){
                           if(dfs(i)==0)
                                        return 0;
             }
     return 1;
}

int main(){
    int m,n,nc=1;
    while(cin>>m>>n&&m!=-1){
                            if(m==n&&m==0){
                                           cout << "Case " << nc++ << " is a tree." << endl;
                                           continue;
                            }
                            mp.clear();
                            int cnt = 0;
                            edges[cnt][0] = m, edges[cnt][1] = n, cnt++;
                            mp[m] = 0, mp[n] = 0;
                            memset(adj,0,sizeof(adj));
                            memset(visit,0,sizeof(visit));
                            while(cin>>m>>n&&(m||n))
                                                    edges[cnt][0] = m, edges[cnt][1] = n, cnt++, mp[m] = mp[n] = 0;
                            nn = 0;
                            for(map<int,int>::iterator it = mp.begin(); it !=mp.end(); it++)
                                                       it->second = nn++;
                            for(int i = 0; i < nn; i++) fa[i] = i;
                            bool valid = 1;
                            for(int i = 0; i < cnt; i++){
                                    int u = mp[edges[i][0]], v = mp[edges[i][1]];
                                    fa[v] = u;
                                    //cout << u << " " << v << endl;
                                    if(adj[u][v]){
                                                 valid = 0;
                                                 break;
                                    }
                                    adj[u][v] = 1;
                            }
                            if(valid==0){
                                         cout << "Case " << nc++ << " is not a tree." << endl;
                                         continue;
                            }
                            int rt = -1;
                            for(int i = 0; i < nn; i++)
                                    if(fa[i]==i){
                                                 rt = i;
                                                 break;
                                    }
                            cout << "Case " << nc++ << " is " ;
                            if(rt==-1){
                                      cout <<"not a tree." << endl;
                                      continue;
                            }
                            if(dfs(rt)){
                                        int i = 0;
                                        for(i = 0; i < nn; i++)
                                              if(visit[i]==0)
                                                             break;
                                        if(i==nn)
                                                 cout << "a tree." << endl;
                                        else
                                            cout << "not a tree." << endl;
                            }
                            else
                                cout << "not a tree." << endl;
    }
}
                                                
                            
                            
                            
