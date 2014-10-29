#include<iostream>
#include<map>
using namespace std;

int adj[101][101],n,a[101][3],fault[101],id[101];
bool yes[101][2];
map<int, int> mp;

int main(){
    int nc;
    cin >> nc;
    while(nc--){
                cin >> n;
                memset(adj,-1,sizeof(adj));
                mp.clear();
                for(int i = 0; i < n; i++){
                        cin >> a[i][0] >> a[i][1];
                        char c;
                        cin >> c;
                        yes[i][0] = c=='Y';
                        cin >> a[i][2];
                        cin >> c;
                        yes[i][1] = c=='Y';
                        mp[a[i][0]] = i;
                        id[i] = a[i][0];
                }
                for(int i = 0; i < n; i++){
                        adj[mp[a[i][0]]][mp[a[i][1]]] = yes[i][0]==1;
                        adj[mp[a[i][0]]][mp[a[i][2]]] = yes[i][1]==1;
                }
                int res = -1;
                bool imp = 0;
                for(int i = 0; i < n; i++){
                        memset(fault,0,sizeof(fault));
                        fault[i] = 1;
                        bool valid = 1;
                        for(int j = 0; j < n&&valid; j++)
                                if(j!=i){
                                         for(int k = 0; k < n&&valid; k++)
                                                 if(adj[j][k]==0&&k!=i||adj[j][k]==1&&k==i){
                                                                                            valid = 0;
                                                                                            break;
                                                 }
                                }
                        if(valid==1){
                                     if(res>=0){
                                                imp = 1;
                                                break;
                                     }
                                     res = i;
                        }
                }
                if(imp||res==-1)
                       cout << "impossible" << endl;
                else
                    cout << id[res] << endl;
    }
}
                    
                
                
