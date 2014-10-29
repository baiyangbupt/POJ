#include<iostream>
using namespace std;

int n,num, adj[101][101];
const int MAX = 10000;

void floyd(){
     for(int k = 1; k <= n; k++)
             for(int i = 1; i <= n; i++)
                     for(int j = 1; j <= n; j++)
                             if(adj[i][k]+adj[k][j]<adj[i][j])
                                                              adj[i][j] = adj[i][k]+adj[k][j];
     return;
}


int main(){
    while(cin>>n&&n){
                  for(int i = 1; i <= n; i++)
                          for(int j = 1; j <= n; j++)
                                  if(i!=j)
                                          adj[i][j] = MAX;
                                  else 
                                       adj[i][j] = 0;
                  for(int i = 1; i <= n; i++){
                          int m,a,b;
                          cin >> m;
                          for(int j = 0; j < m; j++){
                                  cin >> a >> b;
                                  adj[i][a] = b;
                          }
                  }
                  floyd();
                  int mintime = MAX,mi = 1;
                  for(int i = 1; i <= n; i++){
                          int t = 0;
                          for(int j = 1; j <= n; j++)
                                  t = max(t,adj[i][j]);
                          if(t<MAX&&t<mintime)
                                              mintime = t, mi = i;
                  }
                  
                  if(mintime!=MAX) cout << mi << " " << mintime << endl;
                  else cout << "disjoint" << endl;
    }
}
