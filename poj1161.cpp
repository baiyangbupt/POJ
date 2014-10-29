#include<iostream>
using namespace std;

bool adjpreg[300][300];

int m,n,l,twoends[300][300],adjreg[300][300],d[40][300],a[40];
const int MAX = 1000000;
 

int main(){
    while(cin >> m){
              memset(twoends,0,sizeof(twoends));
              memset(adjpreg,0,sizeof(adjpreg));
                cin >> n >> l;
                for(int i = 1; i <= l; i++)
                        cin >> a[i];
                
                for(int i = 1; i <= m; i++)
                        for(int j = 1; j <= m; j++)
                                adjreg[i][j] = MAX;
                                
                for(int i = 1; i <= m; i++){
                        int x,y,pre = 0, st;
                        cin >> x;
                        for(int j = 0; j < x; j++){
                                cin >> y;
                                adjpreg[y][i] = 1;
                                if(pre==0)
                                          st = y;
                                else{
                                     if(twoends[pre][y]>0)
                                                          adjreg[i][twoends[pre][y]] = adjreg[twoends[pre][y]][i] = 1;
                                     else
                                         twoends[pre][y] = twoends[y][pre] = i;
                                }
                                pre = y;
                        }
                        if(twoends[st][y]>0)
                                            adjreg[i][twoends[st][y]] = adjreg[twoends[pre][y]][i] = 1;
                        else
                            twoends[st][y] = twoends[y][st] = i;
                }
                
                for(int k = 1; k <= m; k++)
                        for(int i = 1; i <= m; i++)
                                for(int j = 1; j <= m; j++)
                                        if(adjreg[i][k]+ adjreg[k][j]<adjreg[i][j])
                                                         adjreg[i][j] = adjreg[i][k]+ adjreg[k][j];
                
                for(int i = 1; i <= l; i++)
                        for(int j = 1; j <= m; j++)
                                d[i][j] = MAX;
                for(int i = 1; i <= l; i++){
                        int p = a[i];
                        for(int j = 1; j <= m; j++)
                                if(adjpreg[p][j]){
                                                  d[i][j] = 0;
                                                  for(int k = 1; k <= m; k++)
                                                          d[i][k] = min(d[i][k],adjreg[j][k]);
                                }
                }
                
                //for(int i = 1; i <= l; i++)
                  //      cout << d[i][10] << endl;
                
                int res = MAX;
                for(int i = 1; i <= m; i++){
                        int t = 0;
                        for(int j = 1; j <= l; j++)
                                t+=d[j][i];
                        res = min(res,t);
                }
                cout << res << endl;
    }
    system("pause");
}
            
