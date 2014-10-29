#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct node{
       int id, d;
       node(int a, int b):id(a), d(b){}
};

bool operator<(const node &a, const node &b){
     return a.d>b.d;
}

const int MAX = 1000000;
int n,ed,adj[100][100],d[100],can[100],tadj[100][100];
bool visit[100];

void canreach(){
     memset(visit,0,sizeof(visit));
     queue<int> q;
     q.push(ed);
     while(!q.empty()){
                       int t = q.front();
                       q.pop();
                       if(visit[t]) continue;
                       visit[t] = 1;
                       for(int i = 0; i < n; i++)
                               if(tadj[t][i])
                                             q.push(i);
     }
}

void reverseG(){
     for(int i = 0; i < n; i++)
             for(int j = i+1; j < n; j++)
                     swap(adj[i][j],adj[j][i]);
}
  
void dijk(){
     for(int i = 0; i < n; i++) d[i] = MAX;
     d[ed] = 0;
     priority_queue<node> q;
     q.push(node(ed,0));
     while(!q.empty()){
                       node t = q.top();
                       q.pop();
                       //cout << t.id << " " << t.d << endl;
                       
                       d[t.id] = t.d;
                       for(int i = 0; i < n; i++)
                               if(adj[t.id][i]&&d[i]==MAX)
                                               q.push(node(i,d[t.id]+1));
     }
}

void paint(int p){
     memset(can,-1,sizeof(can));
     memset(tadj,0,sizeof(tadj));
     for(int i = 0; i < n; i++)
             for(int j = 0; j < n; j++)
                     if(i!=p&&j!=p)
                                   tadj[i][j] = adj[i][j];
}

int main(){
    cin >> n >> ed;
    int a,b;
    for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                    adj[i][j] = 0;
    while(cin >> a >> b&&(a||b)) adj[b][a] = 1;
    dijk();
    vector<node> v;
    for(int i = 0; i < n; i++)
            if(i!=ed){
                      //cout << d[i] << endl;
                     v.push_back(node(i,d[i]));
            }
    sort(v.begin(), v.end());
    int res;
    for(int i = v.size()-1; i>=0;i++){
            if(v[i].id==0){
                           res = 0;
                           break;
            }
            paint(v[i].id);
            canreach();
            if(visit[0]==0){
                          res = v[i].id;
                          break;
            }
    }
    cout << "Put guards in room " << res<< "." << endl;
    system("pause");
}
