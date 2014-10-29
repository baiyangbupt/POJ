#include<iostream>
using namespace std;

int need[24], nonzero[24], m, supply[24];

int main(){
    int nc;
    cin >> nc;
    while(nc--){
                for(int i = 0; i < 24; i++)
                        cin >> need[i];
                memset(nonzero,0,sizeof(nonzero));
                memset(supply,0,sizeof(supply));
                for(int i = 0; i < 8; i++)
                        nonzero[0]+=need[i]!=0;
                for(int i = 1; i < 24; i++)
                        nonzero[i] = nonzero[i-1]-(need[i-1]!=0)+(need[(i+7)%24]!=0);
                
                cin >> m;
                for(int i = 0; i < m; i++){
                        int t;
                        cin >> t;
                        supply[t]++;
                }
                
                int remain = 0;
                for(int i = 0; i < 24; i++)
                        if(need[i]>0)
                                     remain++;
                int res = 0;
                while(remain>0){
                                int mm = 0, mi = -1;
                                for(int i = 0; i < 24; i++)
                                        if(supply[i]>0&&nonzero[i]>mm)
                                                                      mm = nonzero[i], mi = i;
                                if(mi==-1)
                                          break;
                                res++;
                                int st = mi;
                                supply[mi]--;
                                for(int i = 0; i < 8; i++){
                                        int t = (st+i)%24;
                                        if(need[t]==0) continue;
                                        if(need[t]>1)
                                                      need[t]--; 
                                        else{
                                             need[t]--;
                                             remain--;
                                             for(int j = t-7; j <= t; j++)
                                                     nonzero[(j+24)%24]--;
                                        }
                                }
                }
                if(remain>0)
                            cout << "No Solution" << endl;
                else
                    cout << res << endl;
    }
}
                        
