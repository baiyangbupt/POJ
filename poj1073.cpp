#include<iostream>
#include<string>
#include<vector>
using namespace std;

int dicnum,ln[25],cnt;
string dic[25][50005],res;

void init(){
     int d;
     memset(ln,0,sizeof(ln));
     cin >> d;
     for(int i = 0; i < d; i++){
             string s;
             cin >> s;
             int len = s.size();
             dic[len][ln[len]++] = s;
     }
}


void dfs(int p, int l, vector<string> &v, string table, string revtable){
     //cout << table << endl;
     if(cnt>1) return;
     if(p==l){
              res = table;
              cnt++;
              return;
     }
     
     string s = v[p];
     int len = s.size();
     for(int i = 0; i < ln[len]; i++){
             bool valid = 1;
             string t = dic[len][i], newtable = table, newinv = revtable;
             for(int i = 0; i < t.size(); i++)
                     if(table[t[i]-'A']!='*'&&table[t[i]-'A']!=s[i]||revtable[s[i]-'A']!='*'&&revtable[s[i]-'A']!=t[i]){
                                                                     valid = 0;
                                                                     break;
                     }
                     else if(table[t[i]-'A']=='*')
                          newtable[t[i]-'A'] = s[i], newinv[s[i]-'A'] = t[i];
             if(valid==1)
                         dfs(p+1,l,v,newtable,newinv);
     }
}
             

int main(){
    init();
    int nc;
    cin >> nc;
    cin.get();
    cin.get();
    string s;
    while(nc--){
                cnt = 0;
                vector<string> inp;
                while(getline(cin,s)&&s!=""){
                                             string temp;
                                             for(int i = 0; i < s.size(); i++)
                                                     if(s[i]==' '&&temp.size()>0)
                                                                                inp.push_back(temp), temp.clear();
                                                     else if(s[i]!=' ')
                                                          temp.push_back(s[i]);
                                             if(temp.size()>0) inp.push_back(temp);
                }
                int inputlen = inp.size();
                string ini(26,'*'),inv(26,'*');
                dfs(0,inputlen,inp,ini,inv);
                if(cnt>1){
                          cout << "#More than one solution#" << endl;
                }
                else if(cnt==0)
                     cout << "#No solution#" << endl;
                else 
                     cout << res << endl;
    }
    system("pause");
}
                
                         
             
