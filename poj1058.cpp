#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

bool adj[16][16], visit[16];
vector<vector<int> > res;
string s[16];

void init(){
     for(int i = 0; i < 16; i++)
             for(int j = 0; j < 16; j++)
                     adj[i][j] = 1;
     for(int i = 0; i < 16; i++) adj[i][i] = 0;
     for(int i = 0; i < 12; i++){
             cin >> s[i];
             for(int k = 0; k < s[i].size(); k++)
                     for(int j = i+1; j < s[i].size(); j++)
                             adj[s[i][k]-'A'][s[i][j]-'A'] = adj[s[i][j]-'A'][s[i][k]-'A'] = 0;
     }
}


bool dfs(int p){
     if(p==16) return 1;
     if(visit[p]) return dfs(p+1);
     
     visit[p] = 1;
     for(int i = 0; i < 16; i++)
             if(adj[p][i]){
                           int count = 0, candi[2];
                           for(int j = 0; j < 16 && count<3; j++)
                                   if(adj[p][j]&&adj[i][j])
                                                           candi[count++] = j;
                           if(count!=2) return 0;
                           vector<int> temp;
                           temp.push_back(i), temp.push_back(p), temp.push_back(candi[0]), temp.push_back(candi[1]);
                           res.push_back(temp);
                           for(int k1 = 0; k1 < 4; k1++)
                                   for(int k2 = 0; k2 < 4; k2++)
                                           adj[temp[k1]][temp[k2]] = adj[temp[k2]][temp[k1]] = 0;
                           for(int k = 0; k < 4; k++) visit[temp[k]] = 1;
                           return dfs(p+1);
             }
}
                           
     
int main(){
    init();
    if(dfs(0)==0) cout << "It is not possible to complete this schedule." << endl;
    else{
         for(int i = 0; i < res.size(); i++){
                 vector<int> v = res[i];
                 sort(v.begin(),v.end());
                 for(int j = 0; j < 4; j++)
                         s[12+i].push_back('A'+v[j]);
         }
         memset(visit,0,sizeof(visit));
         if(dfs(0)==0) cout << "It is not possible to complete this schedule." << endl;
         else{
              for(int i = 0; i < res.size(); i++){
                 vector<int> v = res[i];
                 sort(v.begin(),v.end());
                 for(int j = 0; j < 4; j++)
                         s[16+i].push_back('A'+v[j]);
              }
              for(int i = 0; i < 12; i++){
                      if(i%4==0){
                                 cout << endl;
                                 cout << s[i];
                      }
                      else cout << " " << s[i];
              }
              cout << endl;
              
              for(int i = 12; i < 20; i++){
                      if(i%4==0){
                                 cout << endl;
                                 cout << s[i];
                      }
                      else cout << " " << s[i];
              }
         }
    }
}
              
