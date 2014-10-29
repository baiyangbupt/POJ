#include<iostream>
#include<queue>

using namespace std;

const int MAX = 100000;
int adj[101][101],st,ed,n,d[101];

struct node{
       int id, d;
       node(int a, int b):id(a),d(b){}
};

bool operator<(const node &a, const node &b){
     return a.d > b.d;
}

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


void dijk(){
     memset(d,-1,sizeof(d));
     priority_queue<node> q;
     node nn(st,0);
     q.push(nn);
     while(!q.empty()){
                       node t = q.top();
                       q.pop();
                       d[t.id] = t.d;
                       if(t.id==ed) break;
                       for(int i = 1; i <= n; i++)
                               if(adj[t.id][i]<MAX&&d[i]<0)
                                                           q.push(node(i,t.d+adj[t.id][i]));
     }
}

int main(){
    init();
    dijk();
    if(d[ed]<0) cout << "-1" <<endl;
    else cout << d[ed] << endl;
    system("pause");
}

