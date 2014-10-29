#include<iostream>
#include<string>
#include<queue>
using namespace std;

int deg[26],d[26][26];
struct node{
       int id,d;
       node(int a, int b):id(a),d(b){}
};

bool operator<(const node &a, const node &b){
     return a.d>b.d;
}

int dijk(int st, int ed){
    int dd[26];
    for(int i = 0; i < 26; i++)
            dd[i] = 1000000;
    priority_queue<node> q;
    q.push(node(st,0));
    
    while(!q.empty()){
                      node t = q.top();
                      q.pop();
                      int p = t.id;
                      //cout << t.d << endl;
                      if(p==ed)
                               return t.d;
                      if(dd[p]<t.d)
                                 continue;
                      dd[p] = t.d;
                      for(int i = 0; i < 26; i++)
                              if(d[p][i]>=0&&dd[i]>d[p][i]+t.d)
                                            q.push(node(i,t.d+d[p][i]));
    }
}

int main(){
    string s;
    while(cin>>s){
                  memset(d,-1,sizeof(d));
                  memset(deg,0,sizeof(deg));
                  int l = s.size(),odddeg = 0,total = l,res =0;
                  d[s[0]-'a'][s[l-1]-'a'] = d[s[l-1]-'a'][s[0]-'a'] = l;
                  deg[s[0]-'a']++, deg[s[l-1]-'a']++;
                  odddeg+=2;
                  
                  while(cin >> s&&s!="deadend"){
                            int l = s.size();
                            total+=l;
                            d[s[0]-'a'][s[l-1]-'a'] = d[s[l-1]-'a'][s[0]-'a'] = l;
                            deg[s[0]-'a']++, deg[s[l-1]-'a']++;
                            if(deg[s[0]-'a']%2)
                                               odddeg++;
                            else
                                odddeg--;
                            if(deg[s[l-1]-'a']%2)
                                                 odddeg++;
                            else
                                odddeg--;
                  }
                  //cout << "odd " << odddeg << endl;
                  if(odddeg==1){
                                for(int i = 0; i < 26; i++)
                                        if(deg[i]%2){
                                                     int t= 100000;
                                                     for(int j = 0; j < 26; j++)
                                                             if(d[i][j]>0)
                                                                          t = min(t,d[i][j]);
                                                     res = total+t;
                                                     break;
                                        }
                  }
                  else if(odddeg==0) res = total;
                  else{
                       int end[2], index = 0;
                       for(int i = 0; i < 26; i++)
                               if(deg[i]%2)
                                           end[index++] = i;
                       //cout << total << " " << end[0] << " " << end[1] << endl;
                       res = total + dijk(end[0],end[1]);
                  }
                       
                  cout << res << endl;
    }
}
