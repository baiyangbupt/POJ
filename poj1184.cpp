#include<iostream>
#include<queue>
#include<string>
using namespace std;

int st,ed;
bool visit[6000000];
int d[6000000],base[7] = {100000,10000,1000,100,10,1,1000000},p[6];

int bfs(){
     queue<int> q;
     q.push(st);
     while(!q.empty()){
                       int t = q.front();
                       //cout << t << endl;
                       q.pop();
                       
                       int pos = t/base[6], v = t- pos*base[6];;
                       if(v==ed) 
                                 return d[t];
                       
                       
                       int s0 = v/base[0], s5 = v%10, cur = v/base[pos],newstate;
                       cur = cur%10;
                       
                       if(cur!=p[pos]){
                           newstate = t-s0*base[0]+cur*base[0]-cur*base[pos]+s0*base[pos];
                           if(newstate!=t&&visit[newstate]==0){
                                                  visit[newstate] = 1;
                                                  d[newstate] = d[t]+1;
                                                  q.push(newstate);
                           }
                           newstate = t-s5+cur-cur*base[pos]+s5*base[pos];
                           if(newstate!=t&&visit[newstate]==0){
                                                  visit[newstate] = 1;
                                                  d[newstate] = d[t]+1;
                                                  q.push(newstate);
                           }
                           
                           if(cur>0){
                                     newstate = t-base[pos];
                                     if(visit[newstate]==0){
                                                  visit[newstate] = 1;
                                                  d[newstate] = d[t]+1;
                                                  q.push(newstate);
                                     }
                           }
                           if(cur<9){
                                     newstate = t+base[pos];
                                     if(visit[newstate]==0){
                                                  visit[newstate] = 1;
                                                  d[newstate] = d[t]+1;
                                                  q.push(newstate);
                                     }
                           }
                       }
                       
                       if(pos>0){
                                 newstate = t-base[6];
                                 if(visit[newstate]==0){
                                              visit[newstate] = 1;
                                              d[newstate] = d[t]+1;
                                              q.push(newstate);
                                 }
                       }
                       if(pos<5){
                                 newstate = t+base[6];
                                 if(visit[newstate]==0){
                                              visit[newstate] = 1;
                                              d[newstate] = d[t]+1;
                                              q.push(newstate);
                                 }
                       }                 
     }
     return -1;
     }
     
     

int main(){ 
    string sst,sed;
    while(cin>>sst>>sed){
                       memset(visit,0,sizeof(visit));
                       st = ed = 0;
                       for(int i = 0; i< sst.size(); i++)
                               st*=10, st+=sst[i]-'0',ed*=10,ed+=sed[i]-'0',p[i] = sed[i]-'0';
                       visit[st] = 1;
                       d[st] = 0;
                       cout << bfs() << endl;
    }
}
