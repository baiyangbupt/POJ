#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct node{
       int u,v,w;
       node(int a, int b, int c):u(a), v(b), w(c){}
};

bool operator<(const node &a, const node &b){
     return a.w<b.w;
}

int n, fa[256];
int find(int x){
    if(fa[x]==x)
                return x;
    return fa[x] = find(fa[x]);
}

void Union(int x, int y){
     int m = find(x), n = find(y);
     if(m<n) fa[n] = m;
     else if(m>n)
          fa[m] = n;
}


int main(){
    while(cin>>n&&n){
                     vector<node> vv;
                     char x,y;
                     int c;
                     for(int i = 0; i < 256; i++)
                             fa[i] = i;
                     for(int i = 0; i < n-1; i++){
                             cin >> x;
                             int m;
                             cin >> m;
                             for(int j = 0; j < m; j++){
                                     cin >> y >> c;
                                     vv.push_back(node(x-'A',y-'A',c));
                             }
                     }
                     sort(vv.begin(), vv.end());
                     int cnt = 0, res = 0, i = 0;
                     while(cnt<n-1){
                                    int u = vv[i].u, v = vv[i].v, w = vv[i].w;
                                    
                                    if(find(u)==find(v)){
                                                     i++;
                                                     continue;
                                    }
                                    //cout << w << endl;
                                    res+=w;
                                    Union(u,v);
                                    cnt++;
                                    i++;
                     }
                     cout << res << endl;
    }
}
    
