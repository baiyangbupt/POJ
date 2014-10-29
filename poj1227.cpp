#include<iostream>
#include<map>
#include<vector>
using namespace std;

int T,N,K,M,d[101][101],robot[101];

map<int,int> mm;
 
int main(){
    cin >> T;
    for(int ii = 0; ii < T; ii++){
            memset(d,-1,sizeof(d));
            vector<vector<int> > tempv;
            int vertex;
            cin >> N >> K;
            for(int i = 0; i < N; i++)
                    d[i][i] = 2;
            for(int j = 0; j < N; j++){
                    cin >> vertex;
                    mm[vertex] = j;
                    cin >> M;
                    vector<int> v;
                    for(int k = 0; k < M; k++){
                            int tt;
                            cin >> tt;
                            v.push_back(tt);
                    }
                    tempv.push_back(v);
            }
            int tt;
            for(int i = 0; i < K; i++){
                    cin >> tt;
                    robot[i] = mm[tt];
            }
            
            for(int i = 0; i < tempv.size(); i++)
                    for(int j = 0; j < tempv[i].size(); j++)
                            d[mm[tempv[i][j]]][i] = d[i][mm[tempv[i][j]]] = 1;
            
            for(int k = 0; k < N; k++)
                    for(int i = 0; i < N; i++)    
                            for(int j = 0; j < N; j++)
                                    if(d[i][k]>=0&&d[k][j]>=0&&d[i][j]!=3){
                                                               if(d[i][k]==3||d[k][j]==3)
                                                                                         d[i][j] = d[j][i] = 3;
                                                               else if(d[i][k]==d[k][j]){
                                                                    if(d[i][j]==1)
                                                                                  d[i][j] = d[j][i] = 3;
                                                                    else d[i][j] = d[j][i] = 2;
                                                               }
                                                               else{
                                                                    if(d[i][j]==2)
                                                                                  d[i][j] = d[j][i] = 3;
                                                                    else
                                                                        d[i][j] = d[j][i] = 1;
                                                               }
                                    }
            
            /*for(int i = 0; i < N; i++){
                    for(int j = 0; j < N; j++)
                            cout << d[i][j] << " " ;
                    cout << endl;
            }*/
            bool undo = 1,exist = 0;
            int i;
            for(i = 0; i < N&&undo; i++){
                    int j = 0, odd = -1, valid = 1;
                    for(; j < K; j++){
                          int tend = robot[j];
                          if(d[i][tend]==3) continue;
                          if(d[i][tend]<0){
                                           valid = 0;
                                           break;
                          }
                          if(d[i][tend]==1){
                                         if(odd==0)
                                                   break;
                                         else if(odd==-1)
                                              odd = 1;
                          }
                          else{
                               if(odd==1)
                                         break;
                               else if(odd==-1)
                                    odd = 0;
                          }
                    }
                    if(valid==0) continue;
                    if(j==K) undo = 0, exist = 1;
            }
            if(exist)
                 cout << "YES" << endl;
            else
                cout << "NO" << endl;
    }
}
            
