#include<iostream>
#include<map>
using namespace std;

int x1[101][2], x2[101][2], x3[101][2], x4[101][2];
int l1,l2,l3,l4,c;
bool visit[101],inconsist;

void dfs(int p){
     if(inconsist) return;
     if(visit[p]) return;
     
     c++;
     visit[p] = 1;
     if(x1[p][0]!=0){
                     if(x1[x1[p][0]][1]!=p){
                                            inconsist=1;
                                            return;
                     }
                     if(!visit[x1[p][0]]) l1++;
                     dfs(x1[p][0]);
     }
     if(x1[p][1]!=0){
                     if(x1[x1[p][1]][0]!=p){
                                            inconsist=1;
                                            return;
                     }
                     if(!visit[x1[p][1]]) l1++;
                     dfs(x1[p][1]);
     }
     if(x2[p][0]!=0){
                     if(x2[x2[p][0]][1]!=p){
                                            inconsist=1;
                                            return;
                     }
                     if(!visit[x2[p][0]]) l2++;
                     dfs(x2[p][0]);
     }
     if(x2[p][1]!=0){
                     if(x2[x2[p][1]][0]!=p){
                                            inconsist=1;
                                            return;
                     }
                     if(!visit[x2[p][1]])l2++;
                     dfs(x2[p][1]);
     }
     if(x3[p][0]!=0){
                     if(x3[x3[p][0]][1]!=p){
                                            inconsist=1;
                                            return;
                     }
                     if(!visit[x3[p][0]])l3++;
                     dfs(x3[p][0]);
     }
     if(x3[p][1]!=0){
                     if(x3[x3[p][1]][0]!=p){
                                            inconsist=1;
                                            return;
                     }
                     if(!visit[x3[p][1]])l3++;
                     dfs(x3[p][1]);
     }
     if(x4[p][0]!=0){
                     if(x4[x4[p][0]][1]!=p){
                                            inconsist=1;
                                            return;
                     }
                     if(!visit[x4[p][0]])l4++;
                     dfs(x4[p][0]);
     }
     if(x4[p][1]!=0){
                     if(x4[x4[p][1]][0]!=p){
                                            inconsist=1;
                                            return;
                     }
                     if(!visit[x4[p][1]])l4++;
                     dfs(x4[p][1]);
     }
}

int main(){
    int t,n,id,res,i[8];
    int raw[101][9];
    map<int,int> mp;
    cin >> t;
    while(t--){
               memset(visit,0,sizeof(visit));
               memset(x1,0,sizeof(x1));
               memset(x1,0,sizeof(x2));
               memset(x1,0,sizeof(x3));
               memset(x1,0,sizeof(x4));
               inconsist = c = 0;
               l1 = l2 = l3 = l4 = 1;
               cin >> n;
               for(int i = 0; i < n; i++)
                       for(int j = 0; j < 9; j++) cin >> raw[i][j];
               for(int i = 0; i < n; i++) mp[raw[i][0]] = i+1;
               for(int i = 0; i < n; i++){
                       x1[i+1][0] = mp[raw[i][1]];
                       x1[i+1][1] = mp[raw[i][2]];
               }
               for(int i = 0; i < n; i++){
                       x2[i+1][0] = mp[raw[i][3]];
                       x2[i+1][1] = mp[raw[i][4]];
               }
               for(int i = 0; i < n; i++){
                       x3[i+1][0] = mp[raw[i][5]];
                       x3[i+1][1] = mp[raw[i][6]];
               }
               for(int i = 0; i < n; i++){
                       x4[i+1][0] = mp[raw[i][7]];
                       x4[i+1][1] = mp[raw[i][8]];
               }
               
               dfs(1);
               if(c<n||inconsist) cout << "Inconsistent" << endl;
               else{
                    res = l1*l2*l3*l4;
                    cout << res << endl;
               }
    }
}
