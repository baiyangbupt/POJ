#include<iostream>
#include<stack>
#include<set>
#include<algorithm>
#include<string>
using namespace std;

struct node{
       string name;
       node *dir[100];
       string files[100];
       int dirnum,filenum,level;
       node(string s, int l){
                   name = s;
                   memset(dir,0,sizeof(dir));
                   dirnum = filenum = 0;
                   level = l;
       }
};

set<node*> visit;
node *rt,*p;
stack<node*> st;
int i = 1;

bool operator<(const string &a, const string &b){
     return a<b;
}

void dfs(node *p){
     if(visit.find(p)!=visit.end()) return;
     visit.insert(p);
     for(int i = 0; i < p->level; i++) cout << "|     ";
     cout << p->name << endl;
     
    
     for(int i = 0; i < p->dirnum; i++)
             dfs(p->dir[i]);
              sort(p->files, p->files+p->filenum);
     for(int i = 0; i < p->filenum; i++){
             for(int j = 0; j < p->level; j++) cout << "|     ";
             cout << p->files[i] << endl;
     }
}

void solve(){
     cout << "DATA SET "<<i++<<":"<<endl;
     visit.clear();
     dfs(rt);
     cout << endl;
     rt = new node("ROOT", 0);
     while(!st.empty()) st.pop();
     st.push(rt);
     p = rt;
}
     

int main(){
    rt = new node ("ROOT",0);
    p = rt;
    st.push(rt);
    string s;
    while(cin >> s){
              if(s=="#") break;
              else if(s=="*")
                        solve();
              else if(s=="]"){
                   st.pop();
                   p = st.top();
              }
              else{
                   if(s[0]=='d'){
                                 p->dir[p->dirnum++] = new node(s,p->level+1);
                                 p = p->dir[p->dirnum-1];
                                 st.push(p);
                   }
                   else{
                        p->files[p->filenum++] = s;
                   }
              }
    }
                                 
                   
                   
}
