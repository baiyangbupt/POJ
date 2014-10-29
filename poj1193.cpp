#include<iostream>
#include<queue>
using namespace std;

struct node{
       int t, runtime, memneed, id;
       node(int a, int b, int c, int d = 0):t(a),runtime(b),memneed(c),id(d){}
};

int n;
const int MAX = 0x7fffffff;

bool operator<(const node &a, const node &b){
     if(a.t==b.t)
                 return a.id>b.id;
     return a.t>b.t;
}

int main(){
    while(cin>>n){
                  int x,y,z,time,blocked = 0;
                  priority_queue<node> q;
                  int i = 0;
                  while(cin>>x>>y>>z&&x!=0){
                                      node nn(x,z,y);
                                      nn.id = i++;
                                      q.push(nn);
                  }
                  
                  while(!q.empty()){
                                    node nn = q.top();
                                    int t = nn.t, runtime = nn.runtime, memneed = nn.memneed, id = nn.id;
                                    q.pop();
                                    
                                    time = t;
                                    if(runtime==MAX){
                                                     n+=memneed;
                                                     continue;
                                    }
                                    if(n>=memneed){
                                                   n-=memneed;
                                                   q.push(node(t+runtime+1, MAX, memneed));
                                    }
                                    else
                                        blocked++, q.push(node(t+1,runtime,memneed,id));
                  }
                  
                  cout << time << " " << blocked<< endl;
    }
}      

