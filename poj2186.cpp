#include<iostream>
#include<vector>
using namespace std;

struct enode{
       int next,v;
}ee[500050],re[500050];

int firstedge[100010],n,flag[100010],m,rfirstedge[100010];
vector<int> allover;
bool visit[100010];

void dfs(int p){
      if(visit[p])
                  return ;
      
      allover.push_back(p);
      visit[p] = 1;
      for(int i = firstedge[p]; i!= -1; i = ee[i].next){
              int v = ee[i].v;
              dfs(v);
      }
      
      //allover.push_back(p);
}

void puredfs(int p, int k){
     if(visit[p])
                 return ;
                 
     visit[p] = 1;
     flag[p] = k;
     for(int i = rfirstedge[p]; i != -1; i = re[i].next)
             puredfs(re[i].v,k);
}

int scc(){
    memset(visit,0,sizeof(visit));
    
    allover.clear();
    for(int i = 1; i <= n; i++)
            if(visit[i]==0)
                           dfs(i);
            
    memset(visit,0,sizeof(visit));
    
    int k = 0;
    for(int i = 0; i < allover.size(); i++)
            if(visit[allover[i]]==0)
                                    puredfs(allover[i],k++);
    
    return k;
}

int main(){
    //while(cin>>n>>m)
    cin >> n >> m; 
                     int ecnt = 0;
                     memset(firstedge,-1,sizeof(firstedge));
                     memset(rfirstedge,-1,sizeof(rfirstedge));
                     for(int i = 0; i < m; i++){
                             int u,v;
                             cin >> u >> v;
                             ee[ecnt].next = firstedge[u];
                             ee[ecnt].v = v;
                             firstedge[u] = ecnt;
                             
                             re[ecnt].next = rfirstedge[v];
                             re[ecnt].v = u;
                             rfirstedge[v] = ecnt;
                             ecnt++;
                     }
                     
                     int f = scc()-1;
                     int res = 0, vv;
                     for(int i = 1; i <= n; i++)
                             if(flag[i]==f){
                                            res++;
                                            vv = i;
                             }
                     
                     memset(visit,0,sizeof(visit));
                     puredfs(vv,0);
                     
                     for(int i = 1; i<= n; i++)
                             if(visit[i]==0){
                                             res = 0;
                                             break;
                             }
                     cout << res << endl;
                     system("pause");
    //}
}
