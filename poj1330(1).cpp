#include<iostream>
using namespace std;

struct vnode{
       int firstedge;
}vv[10001];

struct enode{
       int v,next;
}ee[10001];

int rt,n,a,b,fa[10001];

int findlca(int p){
    if(p==a||p==b)
                  return p;
    if(vv[p].firstedge==-1)
                           return 0;
    
    bool afind =0, bfind = 0;
    for(int i = vv[p].firstedge; i!=-1; i = ee[i].next){
            int son = ee[i].v, t = findlca(son);
            if(t==a)
                    afind = 1;
            else if(t==b)
                 bfind = 1;
            else if(t>0)
                 return t;
    }
    
    if(afind&&bfind)
                    return p;
    return afind?a:(bfind?b:0);
}
                     

int main(){
    int nc;
    cin>> nc;
    while(nc--){
                cin >> n;
                for(int i = 1; i <= n; i++)
                        vv[i].firstedge = -1, ee[i].next = -1;
                
                for(int i = 1; i <= n; i++)
                        fa[i] = i;
                int cnt = 0;
                for(int i = 0; i < n-1; i++){
                        int u,v;
                        cin >> u>> v;
                        fa[v] = u;
                        ee[cnt].v = v;
                        ee[cnt].next = vv[u].firstedge;
                        vv[u].firstedge = cnt;
                        cnt++;
                }
                
                for(int i = 1; i <= n; i++)
                        if(fa[i]==i){
                                     rt = i;
                                     break;
                        }
                cin >> a >> b;
                cout << findlca(rt) << endl;
    }
}
