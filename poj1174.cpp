#include<iostream>
#include<string>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

struct node{
       node *next[2], *fail;
       string s;
       int count;
       bool ed;
       node(){
              memset(next,0,sizeof(next));
              fail = NULL;
              ed = count = 0;
       }
};

struct word{
       string s;
       int count;
       word(int a, string b): count(a), s(b){}
};

bool operator<(const word &a, const word &b){
     return a.count>b.count;
}

bool cmp(const string &a, const string &b){
     if(a.size()==b.size())
                           return a>b;
     return a.size()>b.size();
}

vector<word> res;
int A,B,N;
map<string, int> mp;

void inst(string s, node *rt){
     int i = 0;
     node *p = rt;
     while(i < s.size()){
             if(p->next[s[i]-'0']==NULL) p->next[s[i]-'0'] = new node;
             p = p->next[s[i]-'0'];
             i++;
     }
     p->ed = 1;
     p->s = s;
}

void build(node *rt){
     queue<node*> q;
     q.push(rt);
     while(!q.empty()){
                       node *p = q.front();
                       q.pop();
                       for(int i = 0; i < 2; i++)
                               if(p->next[i]!=NULL){
                                                    if(p==rt) p->next[i]->fail = rt;
                                                    else{
                                                         node *t = p->fail;
                                                         while(t!=NULL){
                                                                        if(t->next[i]!=NULL){
                                                                                            p->next[i]->fail = t->next[i];
                                                                                            break;
                                                                        }
                                                                        t = t->fail;
                                                         }
                                                         if(t==NULL) p->next[i]->fail = rt;
                                                    }
                                                    q.push(p->next[i]);
                               }
     }
}

void query(string s, node *rt){
     int i = 0;
     node *p = rt;
     while(i<s.size()-1){
                       while(p->next[s[i]-'0']==NULL&&p!=rt) p = p->fail;
                       p = p->next[s[i]-'0'];
                       p = p==NULL?rt:p;
                       node *t = p;
                       while(t!=rt){
                                    if(t->ed){
                                             t->count++;
                                             if(mp.find(t->s)==mp.end())
                                                                        mp[t->s] = t->count;
                                             else mp[t->s]++;
                                    }
                                    t = t->fail;
                       }
                       i++;
     }
}

void insert(int p, int len, string &s, node *rt){
     if(p==len){
                inst(s,rt);
                return;
     }
     
     s.push_back('0');
     insert(p+1,len,s,rt);
     s.erase(s.end()-1);
     s.push_back('1');
     insert(p+1,len,s,rt);
     s.erase(s.end()-1);
}

void print(){
     for(map<string,int>::iterator it = mp.begin(); it!=mp.end(); it++)
                                  res.push_back(word(it->second, it->first));
     sort(res.begin(),res.end());
     
     int i = 0, cnt = 0, count = 1000000;
     while(i<res.size()&&cnt<N){
                                vector<string> temp;
                                count = res[i].count;
                                while(i<res.size()&&res[i].count==count) temp.push_back(res[i].s), i++;
                                sort(temp.begin(), temp.end(),cmp);
                                cout << count;
                                for(int j = 0; j < temp.size(); j++)
                                        cout << " " << temp[j];
                                cout << endl;
                                cnt++;
     }
}
                                  
     

int main(){
    while(cin>>A>>B>>N){
            node *rt = new node;
            string s;
            for(int i = A; i <= B; i++){
                    insert(0,i,s,rt);
            }
            build(rt);
            cin >> s;
            query(s,rt);
            print();
    }
}
    
