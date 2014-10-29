#include<iostream>
#include<queue>

using namespace std;

const int MAX = 100000;
int adj[101][101],st,ed,n,d[101];

void init(){
     cin >> n >> st >> ed;
     for(int i = 1; i <= n; i++)
             for(int j = 1; j <= n; j++)
                     if(i!=j)
                             adj[i][j] = MAX;
     for(int i = 1; i <= n; i++){
             int num,t;
             cin >> num;
             cin >> t;
             adj[i][t] = 0;
             for(int j = 1; j < num; j++){
                     cin >> t;
                     adj[i][t] = 1;
             }
     }
}

struct node{
       int id,d;
       node(int a, int b): id(a), d(b){}
};

void spfa(){
    for(int i = 1; i <= n; i++) d[i] = MAX;
    d[st] = 0;
    queue<node> q;
    q.push(node(st,0));
    while(!q.empty()){
                      node t = q.front();
                      q.pop();
                      for(int i = 1; i <= n; i++)
                              if(d[i]>d[t.id]+adj[t.id][i]){
                                                            d[i] = d[t.id]+adj[t.id][i];
                                                            q.push(node(i,d[i]));
                              }
    }
}

int main(){
    init();
    spfa();
    if(d[ed]==MAX) cout << "-1" <<endl;
    else cout << d[ed] << endl;
    system("pause");
}
