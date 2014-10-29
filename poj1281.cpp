#include<iostream>
#include<string>
#include<map>
#include<set>

using namespace std;

int main(){
    int m;
    while(cin>>m){
                  map<int, int> mp;
                  set<int> rmlist;
                  int n;
                  cin >> n;
                  for(int i = 0; i < n; i++){
                          int t;
                          cin >> t;
                          rmlist.insert(t);
                  }
                  string s;
                  int plc = 1,cnt = 0;
                  while(cin>>s&&s!="e"){
                                        if(s=="a"){
                                                   int t;
                                                   cin >> t;
                                                   if(mp.find(t)==mp.end())
                                                                           mp[t] = 1;
                                                   else
                                                       mp[t]++;
                                        }
                                        else if(s=="p"){
                                             int t;
                                             cin >> t;
                                             plc = t;
                                        }
                                        else{
                                             cnt++;
                                             if(mp.size()==0){
                                                              cout << -1 << endl;
                                                              continue;
                                             }
                                             map<int,int>::iterator it;
                                             it = plc==1?mp.begin():--mp.end();
                                             if(rmlist.find(cnt)!=rmlist.end())
                                                                               cout << it->first << endl;
                                             if(it->second==1)
                                                              mp.erase(it);
                                             else
                                                 it->second--;
                                        }
                  }
                  cout << endl;
    }
}
                                                                                
                  
                                                             
                                             
                  
