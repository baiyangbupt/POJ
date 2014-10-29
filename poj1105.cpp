#include<iostream>
#include<string>
using namespace std;

struct node{
       node *left, *right;
       string v;
};

int mp[8],n,m;

int main(){
    string s,table;
    int nc=1;
    while(cin >> n && n){
              cout << "S-Tree #" << nc++ << ":" <<endl;
        string res;
        for(int i = 0; i < n; i++){
                cin >> s;
                mp[i] = s[1]-'0'-1;
        }
        cin >> table;
        cin >> m;
        for(int i = 0; i < m; i++){
                cin >> s;
                int idx = 0;
                for(int i = 0; i < n; i++){
                        idx <<= 1;
                        idx += s[mp[i]]-'0';
                }
                
                res.push_back(table[idx]);
        }
        cout << res << endl;
        cout << endl;
    }
}
    
    
