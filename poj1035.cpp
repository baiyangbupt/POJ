#include<iostream>
#include<string>
#include<vector>
using namespace std;

string dict[10001];

int dis(string a, string b){
    if(a.size()>b.size()+1||b.size()>a.size()+1) return 2;
    if(a.size()==b.size()){
                           int d = 0;
                           for(int i = 0; i < a.size(); i++)
                                   if(a[i]!=b[i])
                                                 d++;
                           return d;
    }
    else{
         if(a.size()>b.size()) swap(a,b);
         bool dif = 0;
         for(int i = 0, j = 0; i < b.size(); )
                 if(dif==0&&a[i]!=b[j])
                               dif = 1, j++;
                 else if(dif==1&&a[i]!=b[j])
                      return 2;
                 else i++,j++;
         return 1;
    }
}

int main(){
    string s;
    int i = 1;
    while(cin>>s){
                  if(s=="#") break;
                  dict[i] = s;
                  i++;
    }
    while(cin>>s){
                  if(s=="#") break;
                  vector<int> res;
                  bool cor = 0;
                  for(int j = 1; j < i; j++)
                          if(dis(s,dict[j])==0){
                                                cout << s << " is correct" << endl;
                                                cor = 1;
                                                break;
                          }
                          else if(dis(s,dict[j])==1) res.push_back(j);
                  
                  if(cor) continue;
                  cout << s << ":" ;
                  if(res.size()>0){
                                   for(int j = 0; j < res.size(); j++)
                                           cout << " " << dict[res[j]];
                  }
                  cout << endl;
    }
}
