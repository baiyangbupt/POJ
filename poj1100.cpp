#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int target,a[100],n,cur,b[100];
bool insertp[100];

int atoi(string s){
    int res;
    stringstream ss;
    ss<<s;
    ss>>res;
    return res;
}

bool dfs(int p){
     if(p==n){
              if(cur==target) return 1;
              else return 0;
     }
     
     cur+=a[p];
     b[p] = 1;
     if(dfs(p+1)) return 1;
     cur-=a[p];
     b[p] = 0;
     
     cur-=a[p];
     b[p] = 2;
     if(dfs(p+1)) return 1;
     cur+=a[p];
     b[p] = 0;
     
     cur*=a[p];
     b[p] = 3;
     if(dfs(p+1)) return 1;
     cur/=a[p];
     b[p] = 3;
     
     return 0;
}
     

int main(){
    string s;
    int nc = 1;
    while(getline(cin,s)&&s!="0"){
                                  memset(insertp,0,sizeof(insertp));
                                  memset(b,0,sizeof(b));
                                  string temp;
                                  n = 0;
                                  int i = 0, st;
                                  while(s[i]==' ') i++;
                                  while(s[i]<='9'&&s[i]>='0') temp.push_back(s[i]), i++;
                                  st = i;
                                  while(s[st]!='=') st++;
                                  st++;
                                  target = atoi(temp);
                                  temp.clear();
                                  while(i<s.size()){
                                                    if(s[i]==' '||s[i]=='('||s[i]==')'||s[i]=='='){
                                                               if(temp.size()>0){
                                                                                 insertp[i-1]=1;
                                                                                a[n++] = atoi(temp), temp.clear();
                                                               }
                                                    }
                                                    else temp.push_back(s[i]);
                                                    i++;
                                  }
                                  if(temp.size()>0)  a[n++] = atoi(temp);
                                  
                                  cout << "Equation #" << nc << ":" << endl;
                                  cur = a[0];
                                  if(dfs(1)){
                                             cout << target<<'=';
                                             string res;
                                             int bi = 1;
                                             while(s[st]==' ') st++;
                                             int i = st;
                                             while(i<s.size()){
                                                               if(s[i]==' '){
                                                                          i++;
                                                               }
                                                               else if(s[i]=='('||s[i]==')'){
                                                                    res.push_back(s[i]);
                                                                    i++;
                                                               }
                                                               else{
                                                                    res.push_back(s[i]);
                                                                    if(insertp[i]){
                                                                                   i++;
                                                                                   while(s[i]==' '||s[i]==')'){
                                                                                                 if(s[i]==')') res.push_back(s[i]);
                                                                                                 i++;
                                                                                   }
                                                                                   if(bi<n){
                                                                                            switch(b[bi]){
                                                                                                 case 0: break;
                                                                                                 case 1: res.push_back('+'); break;
                                                                                                 case 2: res.push_back('-'); break;
                                                                                                 default: res.push_back('*'); break;
                                                                                            }
                                                                                            bi++;
                                                                                   }
                                                                    }
                                                                    else i++; 
                                                               }
                                             }
                                             cout << res << endl;       
                                  }
                                  else cout << "Impossible" << endl;
                                  cout << endl;
                                  nc++;
    }                             
}
                                                                
                                            
