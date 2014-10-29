#include<iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;

struct node{
       node *next[26], *fail;
       int count,id;
       node(){
              memset(next,0,sizeof(next));
              fail = NULL;
              count = 0;
              id = 0;
       }
};

void insert(string s, node *rt, int dir, int id){
     int i = 0;
     node *p = rt;
     while(i<s.size()){
                       if(p->next[s[i]-'A']==NULL) p->next[s[i]-'A'] = new node;
                       p = p->next[s[i]-'A'];
                       i++;
     }
     p->count = dir;
     p->id = id;
}

void build(node *rt){
     queue<node*> q;
     q.push(rt);
     while(!q.empty()){
                       node *t = q.front();
                       q.pop();
                       for(int i = 0; i < 26; i++)
                               if(t->next[i]!=NULL){
                                                    if(t==rt) t->next[i]->fail = t;
                                                    else{
                                                         node *p = t->fail;
                                                         while(p!=NULL){
                                                                   if(p->next[i]!=NULL){
                                                                                        t->next[i]->fail = p->next[i];
                                                                                        break;
                                                                   }
                                                                   p = p->fail;
                                                         }
                                                         if(p==NULL) t->next[i]->fail = rt;
                                                    }
                               q.push(t->next[i]);                     
                               }
     }
}

char grid[1024][1024],dd[8] = {'D','C','B','E','H','G','F','A'};
int L,C,W,st[1024][2],direction[1024],cnt,len[1024];
void query(node *rt, int x, int y, int dx, int dy, int dir){
     node *p = rt;
     while(x<L&&y<C&&x>=0&&y>=0){
                     while(p->next[grid[x][y]-'A']==NULL&&p!=rt) p = p->fail;
                     p = p->next[grid[x][y]-'A'];
                     p = p==NULL?rt:p;
                     node *t = p;
                     while(t!=rt){
                                  if(t->count!=0&&st[t->id][0]<0){
                                                               if(t->count>0)
                                                                             st[t->id][0] = x - (len[t->id]-1)*dx, st[t->id][1] = y-(len[t->id]-1)*dy, direction[t->id] = dir;
                                                               else
                                                                   st[t->id][0] = x, st[t->id][1] = y, direction[t->id] = 4+dir;
                                                               cnt++;
                                  }
                                  t = t->fail;
                     }
                     x+=dx, y+=dy;
     }
}

void reverse(string &s){
     int i = 0, j = s.size()-1;
     while(i<j){
                swap(s[i],s[j]);
                i++,j--;
     }
}

int main(){
    while(cin>>L>>C>>W){
                        memset(st,-1,sizeof(st));
                        cnt = 0;
                        for(int i = 0; i < L; i++)
                                for(int j = 0; j < C; j++)
                                        cin >> grid[i][j];
                                        
                        node *rt = new node;
                        string s;
                        for(int i = 0; i < W; i++){
                                cin >> s;
                                len[i] = s.size();
                                insert(s,rt,1,i);
                        }
                        build(rt);
                        for(int i = 0; i < L&&cnt<W;i++){
                                query(rt,i,0,1,1,0);
                                query(rt,i,0,0,1,1);
                                query(rt,i,0,-1,1,2);
                                query(rt,i,C-1,0,-1,5);
                                query(rt,i,C-1,-1,-1,4);
                                query(rt,i,C-1,1,-1,6);
                        }
                        for(int i = 0; i < C&&cnt<W;i++){
                                query(rt,0,i,1,0,3);
                                query(rt,0,i,1,1,0);
                                query(rt,0,i,1,-1,6);
                                query(rt,L-1,i,-1,0,7);
                                query(rt,L-1,i,-1,1,2);
                                query(rt,L-1,i,-1,-1,4);
                        }
                                
                        for(int i = 0; i < W; i++)
                                cout << st[i][0] << " " << st[i][1] <<" " << dd[direction[i]] << endl;
                                                
    }
}
