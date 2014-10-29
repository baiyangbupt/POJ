#include<iostream>
#include<queue>
using namespace std;

struct node{
       int u,v,w;
       node(int a, int b, int c):u(a), v(b), w(c){}
};

bool operator < (const node &a, const node &b){
     return a.w > b.w;
}

int p,r,fa[55];

int find(int x){
    if(fa[x]==x)
                return x;
    
    return fa[x] = find(fa[x]);
}

void Union(int x, int y){
     int m = find(x), n = find(y);
     if(m<n)
            fa[n] = m;
     else if(n<m)
          fa[m] = n;
}

int main(){
    while(cin>>p&&p){
                     cin >> r;
                     for(int i = 1; i <= p; i++)
                             fa[i] = i;
                     priority_queue<node> q;
                     for(int i = 0; i < r; i++){
                             int x,y,z;
                             cin >> x >> y >> z;
                             q.push(node(x,y,z));
                     }
                     
                     int cnt = 0, res = 0;
                     while(cnt<p-1){
                                    node t = q.top();
                                    q.pop();
                                    int u = t.u, v = t.v, w = t.w;
                                    if(find(u)==find(v))
                                                        continue;
                                    
                                    Union(u,v);
                                    res+=w;
                                    cnt++;
                     }
                     cout << res << endl;
    }
}
