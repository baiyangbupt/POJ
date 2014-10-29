#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int k,n,rt[150],fa[101],sonnum[150][101],visit[150];
bool adj[150][101][101];

struct node{
       int id, l;
       node(int a, int b):id(a), l(b){}
};

void getsonnum(int tree, int r){
     queue<node> q;
     q.push(node(r,1));
     int level = 1, st = 0, tail = 0;
     while(!q.empty()){
                       node t = q.front();
                       q.pop();
                       int l = t.l, id = t.id;
                       
                       if(t.l>level){
                                     sort(sonnum[tree]+st, sonnum[tree]+tail);
                                     st = tail;
                                     level = t.l;
                       }
                       int num = 0;
                       for(int i = 1; i <= n; i++)
                               if(adj[tree][id][i]){
                                                    num++;
                                                    q.push(node(i,l+1));
                               }
                       sonnum[tree][tail++] = num;
     }
}

int main(){
    cin >> k >> n;
    for(int i = 0; i < k; i++){
            for(int j = 1; j <= n; j++)
                    fa[j] = j;
            for(int j = 0; j < n-1; j++){
                    int u,v;
                    cin >> u >> v;
                    fa[v] = u;
                    adj[i][u][v] = 1;
            }
            for(int j = 1; j <= n; j++)
                    if(fa[j]==j){
                                 rt[i] = j;
                                 break;
                    }
    }
    for(int i = 0; i < k; i++){
            //cout << rt[i] << endl;
            getsonnum(i,rt[i]);
    }
    memset(visit,-1,sizeof(visit));
    for(int i = 0; i < k; i++)
            if(visit[i]<0){
                           for(int j = i+1; j < k; j++)
                                   if(visit[j]<0){
                                                  int nd = 1;
                                                  while(nd<=n&&sonnum[i][nd]==sonnum[j][nd]) nd++;
                                                  if(nd>n)
                                                          visit[j] = i;
                                   }
            }
    for(int i = 0; i < k; i++)
            if(visit[i]<0){
                           cout << i+1 << " ";
                for(int j = 0; j < k; j++)
                        if(visit[j]==i)
                                       cout << "= " << j+1 << " ";
                cout << ';' << endl;
    }
    system("pause");
}
                    
    
