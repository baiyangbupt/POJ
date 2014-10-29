#include<iostream>
#include<queue>
using namespace std;

int st,ed,n,d[50001],edgnum;
struct vnode{
       int head;
       vnode(){
               head = -1;
       }
}vv[50001];

struct enode{
       int to,next,v;
       enode(){
               next = -1;
       }
}ee[100001];    

void add(int from, int to, int w){
     ee[edgnum].to = to;
     ee[edgnum].next =vv[from].head;
     ee[edgnum].v = w;
     vv[from].head = edgnum;
     edgnum++;
}

void spfa(){
     queue<int> q;
     q.push(st);
     while(!q.empty()){
                       int t = q.front();
                       q.pop();
                       
                       //cout << "t " << t << endl;
                       int edge = vv[t].head;
                       while(edge!=-1){
                                    int to = ee[edge].to;
                                    if(d[to]<max(0,d[t])+ee[edge].v){
                                                           d[to] = max(0,d[t])+ee[edge].v;
                                                           q.push(to);
                                    }
                                    //cout << to << " " << d[to] << " " << ee[edge].v << endl;
                                    edge = ee[edge].next;
                       }
                       //cout << endl;
     }
}
                                    

int main(){
    while(cin>>n){
                  st = 50001,ed = 0, edgnum = 0;
                  int a,b,c;
                  for(int i = 0; i < n; i++){
                          cin >> a >> b >> c;
                          st = min(st,a);
                          ed = max(ed,b+1);
                          add(a,b+1,c);
                  }
                  
                  for(int i = st; i < ed; i++){
                          add(i,i+1,0);
                          add(i+1,i,-1);
                  }
                  memset(d,-1,sizeof(d));
                  d[st] = 0;
                  spfa();
                  //cout << d[ed] << " " << d[st] << endl;
                  cout <<d[ed]-d[st] << endl;
    }
}
