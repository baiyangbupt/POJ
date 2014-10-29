#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

int st,d[25], adj[25][25], pathnum[25], n, pre[25], tobeset, allset;
bool toset[25];

struct node{
       int id,pre,d;
       node(int a, int b, int c):id(a), d(b), pre(c){}
};

struct tnode{
       int id,d;
       tnode(int a, int b):id(a), d(b){}
};

bool operator <(const node &a, const node &b){
     return a.d>b.d;
}

bool operator <(const tnode &a, const tnode &b){
     return a.d < b.d;
}

void dijk(){
     memset(d,-1,sizeof(d));
     d[st] = 0;
     pre[st] = -1;
     priority_queue<node> q;
     q.push(node(st,0, -1));
     allset = 0;
     
     while(!q.empty()){
                       node t = q.top();
                       q.pop();
                       d[t.id] = t.d;
                       pre[t.id] = t.pre;
                       if(toset[t.id]) allset++, toset[t.id] = 0;
                       if(allset==tobeset) break;
                       
                       for(int i = 1; i <= n; i++)
                               if(adj[t.id][i]!=-1){
                                                    if(d[i]==-1) pre[i] = t.id, q.push(node(i,t.d+adj[t.id][i], t.id));
                                                   /* else{
                                                         if(t.d+adj[t.id][i]==d[i]) pathnum[i]++;
                                                    }*/
                       }
     }           
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                    cin >> adj[j][i];
    cin >> st;
    int ed;
    tobeset = 0;
    vector<int> des;
    while(cin>>ed&&ed) des.push_back(ed), toset[ed] = 1, tobeset++; 
    dijk();
    vector<tnode> t;
    for(int i = 0; i < des.size(); i++)
            t.push_back(tnode(des[i],d[des[i]]));
    
    sort(t.begin(),t.end());
    cout << "Org	Dest	Time	Path" << endl;
    cout << setiosflags(ios::left);
    for(int i = 0; i < t.size(); i++){
            int id = t[i].id;
            cout << id << " " << st << " " << d[id];
            while(id!=-1){
                              cout << " " << id;
                              id = pre[id];
            }
            cout << endl;
    }
    system("pause");
}
