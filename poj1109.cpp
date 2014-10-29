#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<set>

using namespace std;

struct node{
       string s;
       vector<int> pages;
       map<string, vector<int> > mp;
       bool operator<(const node &b){
            return s<b.s;
       }
       bool operator>(const node &b){
            return s>b.s;
       }
       bool operator==(const node &b){
            return s==b.s;
       }
       node(string a):s(a){}
};

set<node> ss;

string s, contxt;
bool issep(char c){
     return c=='$'||c=='%';
}

void solve(){
     int page = 1;
     bool inp = 0;
     int i = 0;
     while(i<contxt.size()){
                            if(contxt[i]=='{'){
                                               string p[3];
                                               int st = i+1;
                                               int num = 0, j = 0, sep = 0;
                                               string res;
                                               for(int j = st; contxt[j]!='}'; j++)
                                                     if(contxt[j]==' '&&(contxt[j-1]=='{'||contxt[j+1]=='}'||contxt[j
                                                     -1]=='$'||contxt[j+1]=='$'||contxt[j-1]=='%'||contxt[j+1]=='%'))
                                                                                                                     continue;
                                                     else res.push_back(contxt[j]);
                                               i = j+1;
                                               j = 0;
                                               while(j<res.size()){
                                                                   while(j<res.size()&&!issep(res[j]))
                                                                                     p[num].push_back(res[j]), j++;
                                                                   if(i<res.size())
                                                                                   sep = res[j]=='$'?1:2;
                                                                   if(p[num].size()>0)
                                                                                      num++;
                                                                   j++;
                                               }
                                               switch(num){
                                                           case 0:break;
                                                            case 1:{
                                                                 node t(p[0]);
                                                                  if(ss.find(t)==ss.end()){
                                                                                              vector<int> v(1,page);
                                                                                              t.pages = v;
                                                                                              ss.insert(t);
                                                                  }
                                                                  else {
                                                                       set<node>::iterator it = ss.find(t);
                                                                       int s = it->pages.size();
                                                                       if(page> it->pages[s-1]) it->pages.push_back(page);
                                                                  }
                                                                  break;
                                                                 }
                                                           case 2:{
                                                                  if(sep==1){
                                                                             node t(p[0]);
                                                                             if(ss.find(t)==ss.end()){
                                                                                                      vector<int> v(1,page);
                                                                                                      t.mp[p[1]] = v;
                                                                                                      ss.insert(t);
                                                                             }
                                                                             else{
                                                                                  set<node>::iterator it = ss.find(t);
                                                                                  if(it->mp.find(p[1])==it->mp.end()){
                                                                                                                      vector<int> v(1,page);
                                                                                                                      it->mp[p[1]] = v;
                                                                                  }
                                                                                  else{
                                                                                       int s = it->mp[p[1]].size();
                                                                                       if(page>it->mp[p[1]][s-1]) mp[p[1]][s-1].push_back(page);
                                                                                  }
                                                                             }
                                                                  }
                                                                  else{
                                                                       node t(p[1]);
                                                                       if(ss.find(t)==ss.end()){
                                                                                              vector<int> v(1,page);
                                                                                              t.pages = v;
                                                                                              ss.insert(t);
                                                                       }
                                                                       else {
                                                                            node *it = ss.find(t);
                                                                            int s = it->pages.size();
                                                                            if(page>it->pages[s-1]) it->pages.push_back(page);
                                                                       }
                                                                  }
                                                                  break;
                                                                  }
                                                           case 3:{
                                                                 node t(p[1]);
                                                                 if(ss.find(t)==ss.end()){
                                                                                          vector<int> v(1,page);
                                                                                          t.mp[p[2]] = v;
                                                                                          ss.insert(t);
                                                                 }
                                                                 else{
                                                                      node *it = ss.find(t);
                                                                      if(it->mp.find(p[2])==it->mp.end()){
                                                                                                          vector<int> v(1,page);
                                                                                                          it->mp[p[2]] = v;
                                                                      }
                                                                      else{
                                                                           int s = it->mp[p[2]].size();
                                                                           if(page>it->mp[p[2]][s-1]) mp[p[2]][s-1].push_back(page);
                                                                      }
                                                                 }
                                                                 break;
                                                                 }
                                               }
                            }
                            else if(contxt[i]=='&'){
                                 page++;
                            }
                            i++;
     }
     ss.clear();
}
                                               
                                               

int main(){
    int nc = 1;
    while(getline(cin,s)&&s!="**"){
                                   if(s=="*")
                                             solve();
                                   contxt.append(s);
    } 
}
