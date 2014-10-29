#include<iostream>
using namespace std;

struct vnode{
       int firstedge;
}vv[10001];

struct enode{
       int v,next;
}ee[10001];

int n,fa[10001],a,b,res;
bool visit[10001],getans;

int find(int x){
    if(fa[x]==x)
                return x;
    return fa[x] = find(fa[x]);
}

void Union(int x, int y){
     int m = find(x), n = find(y);
     fa[n] = m;
}

void lca(int p){
     if(getans) return;
     //cout << p << endl;
     fa[p] = p;
     
     for(int i = vv[p].firstedge; i!=-1; i = ee[i].next){
             int son = ee[i].v;
             lca(son);
             Union(p,son);
     }
     visit[p] = 1;
     if(a==p&&visit[b]){
                        res = find(b);
                        getans = 1;
     }
     else if(b==p&&visit[a]){
          res = find(a);
          getans = 1;
     }
}


int main(){
    int nc;
    cin >> nc;
    while(nc--){
                cin >> n;
                for(int i = 1; i <= n; i++)
                        vv[i].firstedge = ee[i].next = -1;
                
                memset(visit,0,sizeof(visit));
                for(int i = 1; i <= n; i++)
                        fa[i] = i;
                int cnt = 0;
                for(int i = 0; i <n-1; i++){
                        int u,v;
                        cin >> u >> v;
                        fa[v] = u;
                        ee[cnt].v = v;
                        ee[cnt].next = vv[u].firstedge;
                        vv[u].firstedge = cnt;
                        cnt++;
                }
                
                int rt;
                for(int i = 1; i <= n; i++)
                        if(fa[i]==i){
                                     rt = i;
                                     break;
                        }
                //cout << rt << endl;
                cin >> a >> b;
                getans = 0;
                lca(rt);
                cout << res << endl;
    }
}
                
 
