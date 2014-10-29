#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int num[26][2];
bool adj[26][26],visit[26];

int dfs(int p){
    if(visit[p])
                return 0;
    visit[p] = 1;
    int res =0;
    for(int i = 0; i< 26; i++)
            if(adj[p][i])
                         res+=dfs(i);
    return res+1;
}

int main(){
    int nc;
    cin >> nc;
    while(nc--){
                int n,cnt = 0;
                cin >> n;
                memset(num,0,sizeof(num));
                memset(adj,0,sizeof(adj));
                memset(visit,0,sizeof(visit));
                for(int i = 0; i < n; i++){
                        string s;
                        cin >> s;
                        int u = s[0]-'a', v = s[s.size()-1]-'a';
                        num[s[0]-'a'][0]++, num[s[s.size()-1]-'a'][1]++;
                        adj[u][v] = 1;
                        if(visit[u]==0)
                                       visit[u] = 1, cnt++;
                        if(visit[v]==0)
                                       visit[v] = 1, cnt++;
                }
                bool headget = 0, tailget = 0, valid = 1;
                for(int i = 0; i<26; i++)
                        if(num[i][0]==num[i][1])
                                                continue;
                        else if(abs(num[i][0]-num[i][1])>1||headget&&num[i][0]>num[i][1]||tailget&&num[i][1]>num[i][0]){
                             valid = 0;
                             break;
                        }
                        else if(num[i][0]>num[i][1])
                            headget = 1;
                        else
                            tailget = 1;
                int st  = -1;
                for(int i = 0; i < 26; i++)
                        if(visit[i]){
                                     st = i;
                                     break;
                        }
                if(st==-1){
                           cout << "Ordering is possible." << endl;
                           continue;
                }
                memset(visit,0,sizeof(visit));
                //cout << dfs(st) << endl;
                if(dfs(st)!=cnt)
                                valid = 0;
                if(valid)
                         cout << "Ordering is possible." << endl;
                else
                    cout << "The door cannot be opened." << endl;
    }
}
