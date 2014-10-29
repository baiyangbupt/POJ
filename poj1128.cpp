#include<iostream>
#include<string>
using namespace std;

bool adj[27][27];
int n, color[27];

int mincolor(){
    memset(color,-1,sizeof(color));
    color[0] = 1;
    for(int i = 1; i < n; i++){
            bool used[27];
            memset(used,0,sizeof(used));
            for(int j = 0; j < i; j++)
                    if(adj[i][j])
                                 used[color[j]] = 1;
            int j = 1;
            while(used[j]) j++;
            color[i] = j;
    }
    int res = 0;
    for(int i = 0; i < n; i++)
            res = max(res,color[i]);
    return res;
}

int main(){
    while(cin >> n && n){
              memset(adj,0,sizeof(adj));
              string s;
              for(int i = 0; i < n; i++){
                      cin >> s;
                      int j = 0;
                      while(s[j]!=':') j++;
                      j++;
                      while(j<s.size())
                                       adj[i][s[j]-'A'] = 1, j++;
              }
              int res = mincolor();
              cout << res << " channel";
              cout << (res >1?"s needed.":" needed.") << endl;
    }
}
