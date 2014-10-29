#include<iostream>
#include<string>

using namespace std;

struct node{
       node *next[2];
       int count;
       node(){
              memset(next,0,sizeof(next));
              count = 0;
       }
};

int insert(node *rt, string s){
    int i = 0;
    while(i<s.size()){
                      if(rt->next[s[i]-'0']==NULL) rt->next[s[i]-'0'] = new node;
                      else if(rt->next[s[i]-'0']->count) return 0;
                      
                      rt = rt->next[s[i]-'0'];
                      i++;
    }
    rt->count = 1;
    return 1;
}

int main(){
    string s;
    bool valid = 1;
    int i = 1;
    node * rt = new node;
    while(cin>>s){
                  if(s=="9"){
                             if(valid) cout << "Set " << i <<" is immediately decodable"<<endl;
                             else cout << "Set " << i << " is not immediately decodable" << endl;
                             rt = new node;
                             i++;
                             valid = 1;
                  }
                  else if(valid==0) continue;
                  else{
                       if(insert(rt,s)==0) valid = 0;
                  }
    }
}
                             
