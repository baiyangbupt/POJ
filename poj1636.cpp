#include<iostream>
using namespace std;

int n,m,r,fa[500],rank[500], first[500], second[500];
bool dp[201][201];

int find(int x){
    if(fa[x]==x)
                return x;
    
    return fa[x] = find(fa[x]);
}

void Union(int x, int y){
     int m = find(x), n = find(y);
     
     if(m==n)
             return;
             
     if(rank[m]>=rank[n])
            fa[n] = m, rank[m] += rank[n], first[m] += first[n], second[m] += second[n];
     else 
          fa[m] = n, rank[n] += rank[m], first[n] += first[m], second[n] += second[m];
}


int main(){
    int nc;
    cin >> nc;
    while(nc--){
                cin >> m >> r;
                for(int i = 1; i <= 2*m; i++)
                        fa[i] = i, rank[i] = 1, first[i] = i<=m, second[i] = i>m;
                
                for(int i = 0; i < r; i++){
                        int x,y;
                        cin >> x >> y;
                        y += m;
                        Union(x,y);
                }
                
                memset(dp,0,sizeof(dp));
                dp[0][0] = 1;
                int M = 0;
                for(int i = 1; i <= 2*m; i++)
                        if(find(i)==i){
                                     for(int j = min(M,m/2-first[i]); j>=0; j--)
                                             for(int k = min(M,m/2-second[i]); k>=0; k--)
                                                     if(dp[j][k]){
                                                                  //cout << first[i] << ' ' << second[i] << endl;
                                                                  dp[j+first[i]][k+second[i]] = 1;
                                                                  M = max(M, j+first[i]), M = max(M, k+second[i]);
                                                                  M = min(M,m/2);
                                                     }
                        }
                
                int res = 0;
                for(int i = m/2; i >= 0; i--)
                        if(dp[i][i]){
                                     res = i;
                                     break;
                        }
                cout << res << endl;
    }
}
 
