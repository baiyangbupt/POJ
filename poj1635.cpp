#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

string s1,s2;
vector<int> v1,v2;
struct node{
       int s,e,l;
       node(int a, int b, int c) :s(a), e(b), l(c){}
};

void handle(string &str, vector<int> &v){
     v.clear();
     int len = str.size();
     
     queue<node> q;
     q.push(node(-1,len,0));
     int level = -1;
     vector<int> temp;
     
     while(!q.empty()){
                       node t = q.front();
                       q.pop();
                       
                       int s = t.s+1, e = t.e-1, l = t.l, sons=0;
                       if(s==e-1)
                                 sons = 0;
                       else{
                            int i = s;
                            int zeros = 0;
    
                            while(i<=e){
                                         zeros+=str[i]=='0'?1:-1;
                                         if(zeros==0){
                                                      q.push(node(s,i,l+1));
                                                      s = i+1;
                                                      sons++;
                                         }
                                         i++;
                            }
                       }
                       
                       //cout << sons << endl;
                       if(l==level+1){
                                      sort(temp.begin(),temp.end());
                                      for(int i = 0; i < temp.size(); i++)
                                              v.push_back(temp[i]);
                                      temp.clear();
                                      temp.push_back(sons);
                                      level += 1;
                       }
                       else
                           temp.push_back(sons);
    }
    
    if(temp.size()>0){
                      sort(temp.begin(),temp.end());
                      for(int i = 0; i < temp.size(); i++)
                              v.push_back(temp[i]);
    }
}

void build(){
     v1.clear(), v2.clear();
     handle(s1,v1);
     handle(s2,v2);
}
                       
int main(){
    int nc;
    cin >> nc;
    while(nc--){
                cin >> s1 >> s2;
                build();
                bool valid = v1.size()==v2.size();
                for(int i = 0; i < v1.size()&&valid; i++)
                        if(v1[i]!=v2[i])
                                        valid = 0;
                cout << (valid?"same":"different") << endl;
    }
}
