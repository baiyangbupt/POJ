#include<iostream> 
#include<queue>
#include<vector>
#include<iomanip>
using namespace std;

int adj[500][500],n,m,ft[500];
double f[500];
const int MAX = 100000;
vector<int> v(2);

struct node{
       int id, d;
       node(int a, int b): id(a), d(b){}
};

bool operator<(const node &a, const node &b){
     return a.d > b.d;
}

void spfa(){              
     for(int i = 1; i <= n; i++) ft[i] = -1;
     priority_queue<node> q;
     q.push(node(1,0));
     while(!q.empty()){
                       node t = q.top();
                       q.pop();
                       if(ft[t.id]>=0) continue;
                       ft[t.id] = t.d;
                        
                       for(int i = 1; i <= n; i++)
                               if(adj[t.id][i]>=0&&ft[i]<0)
                                                        q.push(node(i,t.d+adj[t.id][i]));
     }
}

double solve(){
       double res = 0;
       int i1 = 1, i2 = -1;
       for(int i = 1; i <= n; i++)
               for(int j = i+1; j <= n; j++)
                       if(adj[i][j]>=0){
                                        int m1 = max(ft[i],ft[j]), m2 = min(ft[i],ft[j]);
                                        if(m1>m2+adj[i][j]){
                                                             if(double(m2+adj[i][j])>res){
                                                                                          res = double(m2+adj[i][j]);
                                                                                          i1 = i, i2 = j;
                                                             }
                                        }
                                        else if(m1==m2+adj[i][j]){
                                             if(double(m1)>res){
                                                        res = double(m1);
                                                        i1 = ft[i]>ft[j]?i:j, i2 = -1;
                                             }
                                        }
                                        else{
                                             if(m1+((m2+adj[i][j]-m1))/2.>res){
                                                                               res = m1+((m2+adj[i][j]-m1))/2.;
                                                                               i1 = i, i2 = j;
                                             }
                                        }
                       }
       v[0] = i1, v[1] = i2;
       return res;
}

int main(){
    int ii = 1;
    while(cin >> n >> m&&n){
              memset(adj,-1,sizeof(adj));
              for(int i = 0; i < m; i++){
                      int a,b,c;
                      cin >> a >> b >> c;
                      adj[a][b] = adj[b][a] = c;
              }
              spfa();
              double res = solve();
              cout <<"System #" << ii++ <<endl;
              if(v[1] == -1)
                      cout << "The last domino falls after " <<setiosflags(ios::fixed) << setprecision(1) << res<<" seconds, at key domino " << v[0] << "." << endl;
              else 
                   cout << "The last domino falls after " << setiosflags(ios::fixed) << setprecision(1) <<res << " seconds, between key dominoes " << v[0] << " and " << v[1] << "." << endl;
              cout << endl;          
    }
}
