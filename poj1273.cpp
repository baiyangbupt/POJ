#include<iostream>
#include<queue>
using namespace std;

int map[201][201], m, n, path[201];

int bfs(){
    int st = 1, ed = m, flow = 100000000;
    memset(path,-1,sizeof(path));
    queue<int> q;
    q.push(st);
    while(!q.empty()){
                      int t = q.front();
                      q.pop();
                      
                      if(t==ed)
                                return flow;
                                   
                      for(int i = 1; i <= m; i++)
                              if(path[i]==-1&&i!=st&&map[t][i]>0){
                                                           flow = min(flow,map[t][i]);
                                                           path[i] = t;
                                                           q.push(i);
                              }
    }
    if(path[ed]==-1)
                    return -1;
    return flow;
}

int em(){
    int res = 0, t;
    while((t=bfs())!=-1){
                         res+=t;
                         int cur = m, pre = path[m];
                         while(pre!=-1){
                                        map[pre][cur]-=t;
                                        map[cur][pre]+=t;
                                        cur = pre;
                                        pre = path[pre];
                         }
    }
    return res;
}
                         
                         
int main(){
    while(cin>>n>>m){
                     memset(map,0,sizeof(map));
                     for(int i = 1; i <= n; i++){
                             int x,y,c;
                             cin >> x >> y >> c;
                             map[x][y] += c;
                     }
                     cout << em() << endl;
    }
}
