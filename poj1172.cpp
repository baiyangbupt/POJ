#include<iostream>
#include<vector>
using namespace std;

bool adj[55][55],tadj[55][55],visit[55],pvisit[55];
int n,st,ed;

void remv(int p){
     memset(tadj,0,sizeof(tadj));
     for(int i = 0; i <= n; i++)
             for(int j = 0; j <= n; j++)
                     if(i!=p&&j!=p)
                                   tadj[i][j] = adj[i][j];
     
}

bool dfs(int p){
     //cout << p << endl;
     if(p==ed)
              return 1;
     
     if(visit[p]) return 0;
     
     visit[p] = 1;
     for(int i = 0; i <= n; i++)
             if(tadj[p][i]){
                           if(dfs(i))
                                     return 1;
             }
     
     return 0;
}

bool dfs2(int p){
     if(visit[p]) return 0;
     if(pvisit[p])
                  return 1;
     
     pvisit[p] = 1;
     for(int i  =0; i <= n; i++)
             if(adj[p][i]){
                            if(dfs2(i)==0)
                                          return 0;
             }
     return 1;
}

int main(){
    int x;
    n = 0;
    vector<int> unavoid,split;
    memset(adj,0,sizeof(adj));
    while(cin>>x&&x!=-1){
                         adj[n][x] = 1;
                         while(cin>>x&&x!=-2)
                                             adj[n][x] = 1;
                         n++;
    }
    st = 0, ed = n;
    for(int i = 1; i < n; i++){
            remv(i);
            memset(visit,0,sizeof(visit));
            memset(pvisit,0,sizeof(pvisit));
            if(dfs(st)==0){
                           bool cansplit = 1;
                          unavoid.push_back(i);
                          for(int ii = 1; ii < n && cansplit; ii++)
                                  if(visit[ii]==0&&pvisit[ii]==0){
                                               if(dfs2(ii)==0)
                                                             cansplit = 0;
                                  }
                          if(cansplit)
                                      split.push_back(i);
            }    
    }
    cout << unavoid.size();
    for(int i = 0; i < unavoid.size(); i++)
            cout << " " <<unavoid[i];
    cout << endl;
    cout << split.size();
    for(int i = 0; i < split.size(); i++)
            cout << " " << split[i];
    cout << endl;
    system("pause");
}
