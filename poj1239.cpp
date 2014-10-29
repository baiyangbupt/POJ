#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

int atoi(string s){
    int res, i = 0;
    while(i<s.size()&&s[i]=='0') i++;
    if(i==s.size()) return 0;
    s = s.substr(i);
    stringstream ss;
    ss<<s;
    ss>>res;
    return res;
}

string s;
int dp[100],path[100];


void dpsolve(string s){
    for(int i = 0; i < s.size(); i++)
                                  dp[i] = 1000000;
      dp[0] = s[0]-'0';
      for(int i = 1; i < s.size(); i++){
              int mi = -1,m = 100000;
              for(int j = i; j >= 0; j--){
                      int t = atoi(s.substr(j,i-j+1));
                      if(t>dp[j-1]&&m>t)
                                            m = t,mi = j-1;
                                            //mi = j-1;
              }
              dp[i] = m;
              path[i] = mi;
      }
      int final = dp[s.size()-1], ed = path[s.size()-1];
      
      string ss = s.substr(0,ed+1);
      
      dp[ss.size()] = final;
      path[ss.size()] = s.size();
      for(int i = ss.size()-1; i >=0; i--){
              if(ss[i]=='0')
                            dp[i] = dp[i+1], path[i] = path[i+1];
              else{
                   int m = -1, mi = -1;
                   for(int j = i; j < ss.size(); j++){
                           int t = atoi(ss.substr(i,j-i+1));
                           if(t<dp[j+1]&&t>m)
                                             m = t, mi = j+1;
                   }
                   dp[i] = m;
                   path[i] = mi;
              }
      }
      int t = 0;
      while(t<s.size()){
                        int next = path[t];
                        cout << s.substr(t,next-t) << (next!=s.size()?',':'\n');
                        t = next;
      }
}

int main(){
    while(cin>>s&&s!="0"){
                          dpsolve(s);
    }
}
                          
