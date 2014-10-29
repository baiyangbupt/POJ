#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int num[26][2],fa[26];
bool adj[26][26],visit[26];

int find(int x){
    if(fa[x]==x)
                return x;
    return fa[x] = find(fa[x]);
}

void Union(int x, int y){
     int m = find(x), n = find(y);
     fa[m] = n;
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
                for(int i = 0; i< 26; i++)
                        fa[i] = i;
                int st;
                for(int i = 0; i < n; i++){
                        string s;
                        cin >> s;
                        int u = s[0]-'a', v = s[s.size()-1]-'a';
                        num[s[0]-'a'][0]++, num[s[s.size()-1]-'a'][1]++;
                        Union(u,v);
                        if(visit[u]==0)
                                       visit[u] = 1, cnt++;
                        if(visit[v]==0)
                                       visit[v] = 1, cnt++;
                        st = u;
                }
                bool headget = 0, tailget = 0, valid = 1;
                for(int i = 0; i<26; i++){
                        if(visit[i]&&find(i)!=find(st)){
                                                        valid = 0;
                                                        break;
                        }
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
                }
                if(valid)
                         cout << "Ordering is possible." << endl;
                else
                    cout << "The door cannot be opened." << endl;
    }
}
