#include<iostream>
#include<sstream>
#include<queue>
#include<string>
#include<stack>
using namespace std;


struct node{
       int room, state;
       node(int a, int b): room(a), state(b){}
};

bool adj[11][11], lighton[11], control[11][11], visit[11];
int r,d,s,dist[11][1<<10],pre[11][1<<10][2];
const int MAX = 1000000;

void print(){
     int rm = r-1, st = 1<<(r-1);
     cout << "The problem can be solved in " << dist[rm][st] << " steps:" << endl;
     stack<string> res;
     while(rm!=-1&&pre[rm][st][0]!=-1){
                               stringstream ss;
                               string temp,room;
                               if(pre[rm][st][0]!=rm){
                                                      temp.append("- Move to room ");
                                                      ss<<rm+1;
                                                      ss>>room;
                                                      temp.append(room), temp.append(".\n");
                                                      res.push(temp);
                               }
                               else{
                                    temp.append(st&(1<<pre[rm][st][1])?"- Switch on light in room " : "- Switch off light in room ");
                                    ss<<pre[rm][st][1]+1;
                                    ss>>room;
                                    temp.append(room);
                                    temp.append(".\n");
                                    res.push(temp);
                               }
                               int t = st;
                               if(rm==pre[rm][st][0]) st = st^(1<<pre[rm][st][1]);
                               rm = pre[rm][t][0];
     }
     
     while(!res.empty()){
                         string t = res.top();
                         cout << t;
                         res.pop();
     }
}
                                                      

bool bfs(){
     for(int i = 0; i < r; i++)
             for(int j = 0; j <= 1<<r; j++)
                     dist[i][j] = MAX;
     queue<node> q;
     dist[0][1] = 0;
     pre[0][1][0] = -1;
     q.push(node(0,1));
     
     while(!q.empty()){
                       node t = q.front();
                       q.pop();
                       int dis = dist[t.room][t.state], ss = t.state;
                       
                       //cout << t.room << " " << ss << endl;
                       if(t.room==r-1&&t.state==1<<(r-1)){
                                                      print();
                                                      return 1;
                       }
                       
                       for(int i = 0; i < r; i++)
                               if(adj[t.room][i]&&(ss&(1<<i))&&dist[i][ss]>dis+1){
                                                       dist[i][ss] = dis+1;
                                                       pre[i][ss][0] = t.room;
                                                       pre[i][ss][1] = 0;
                                                       q.push(node(i,ss));
                               }
                       
                       for(int i = 0; i < r; i++)
                               if(control[t.room][i]){
                                                      int ts = ss^(1<<i);
                                                      if(dist[t.room][ts]>dis+1){
                                                                            dist[t.room][ts] = dis+1;
                                                                            pre[t.room][ts][0] = t.room;
                                                                            pre[t.room][ts][1] = i;
                                                                            q.push(node(t.room,ts));
                                                      }
                               }
     }
     return 0;
}

int main(){
    int nc = 1;
    while(cin>>r>>d>>s&&r){
                           cout<< "Villa #" << nc++ << endl;
                        memset(adj,0,sizeof(adj));
                        memset(lighton,0,sizeof(lighton));
                        memset(control,0,sizeof(control));
                        memset(visit,0,sizeof(visit));
                        int x,y;
                        for(int i = 0; i < d; i++){
                                cin >> x >> y;
                                adj[x-1][y-1] = adj[y-1][x-1] = 1;
                        }
                        for(int i = 0; i < s; i++){
                                cin >> x >> y;
                                if(x!=y) control[x-1][y-1] = 1;
                        }
                        if(bfs()==0)
                                    cout << "The problem cannot be solved." << endl;
                        cout << endl;
                                    
    }
}
                        
