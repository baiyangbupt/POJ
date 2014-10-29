#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

map<char,int> dict;
void init(){
     dict['A'] = 0; dict['C'] = 1;
     dict['G'] = 2; dict['T'] = 3;
}

struct node{
       string s;
       int invs;
       bool operator<(const node &b)const{
            return invs<b.invs;
       }
       node(int a, string b):invs(a),s(b){}
};

int main(){
    init();
    int h[4];
    int n,m;
    cin >> n >> m;
    vector<node> v;
    string s;
    for(int i = 0; i < m; i++){
          cin >> s;
          memset(h,0,sizeof(h));
          int invs = 0;
          for(int i = 0; i < s.size(); i++){
                    int cur = dict[s[i]];
                    for(int j = 3;  j>cur; j--){
                            invs += h[j];
                    }
                    h[cur]++;
          }
          v.push_back(node(invs,s));
    }
    sort(v.begin(),v.end());
    for(int i = 0; i < v.size(); i++)
            cout << v[i].s << endl;
    system("pause");
          
}
