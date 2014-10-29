#include<iostream>
using namespace std;

int n,dis[100][100],tdis[100][100];
bool adj[100][100],tadj[100][100];

int main(){
    while(cin>>n&&n){
                     for(int i = 0; i< n; i++)
                             for(int j = 0; j < n; j++){
                                     char c;
                                     cin >> c;
                                     adj[i][j] = c=='1';
                             }
                     for(int i = 0; i < n; i++)
                             for(int j = 0; j < n; j++)
                                     if(adj[i][j])
                                                  dis[i][j] = 1;
                                     else if(i==j)
                                          dis[i][j] = 0;
                                     else
                                         dis[i][j] = 10000;
                     
                     for(int k = 0; k < n; k++)
                             for(int i = 0; i < n; i++)
                                     for(int j = 0; j < n; j++)
                                             if(dis[i][k]+dis[k][j]<dis[i][j])
                                                                              dis[i][j] = dis[i][k]+dis[k][j];
                     
                     int res = 0;
                     for(int i = 0; i < n; i ++){
                             bool tadj[100][100];
                             for(int ii = 0; ii < n; ii++)
                                     for(int j = 0; j <n; j++)
                                             tadj[ii][j] = adj[ii][j];
                             for(int j = 0; j < n; j++)
                                     tadj[i][j] = 0, tadj[j][i] = 0;
                             
                             for(int j = 0; j < n; j++)
                                     for(int k = 0; k < n; k++)
                                             if(tadj[j][k])
                                                           tdis[j][k] = 1;
                                             else if(k==j)
                                                  tdis[j][k] = 0;
                                             else
                                                 tdis[j][k] = 10000;
                             
                                     for(int k = 0; k < n; k++)
                                             for(int ii = 0; ii < n; ii++)
                                                     for(int j = 0; j < n; j++)
                                                             if(ii!=i&&k!=i&&j!=i&&tdis[ii][k]+tdis[k][j]<tdis[ii][j])
                                                                              tdis[ii][j] = tdis[ii][k]+tdis[k][j];
                             
                             bool undo = 1;
                             for(int j = 0; j < n&&undo; j++)
                                     for(int k = 0; k < n&&undo; k++)
                                             if(j!=i&&k!=i&&tdis[j][k]>dis[j][k]){
                                                                      //cout << j <<' ' << k << endl;
                                                                      undo = 0;
                                                                      break;
                                             }
                             if(undo==0)
                                        res++;
                     }
                     cout << res << endl;
    }
}
