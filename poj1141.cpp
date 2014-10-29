#include<iostream>
#include<string>
#include<stack>

using namespace std;

int dp[201][201],path[101][101];
const int MAX = 100000;
string res,s;

string print(int i, int j){
     if(i>j) return "";
     if(i==j){
              if(s[i]=='('||s[i]==')') return "()";
              else return "[]";
     }
     
     string res;
     if(path[i][j]==-1){
                        if(i==j-1)
                                  return s.substr(i,2);
                        res.push_back(s[i]);
                        res.append(print(i+1,j-1));
                        res.push_back(s[j]);
                        return res;
     }
     
     int k = path[i][j];
     res.append(print(i,k));
     res.append(print(k+1,j));
     return res;
}

int main(){
    cin >> s;
              for(int i = 0; i < s.size(); i++) dp[i][i] = 1;
              
              for(int len = 2; len<=s.size(); len++)
                      for(int i = 0; i+len-1<s.size(); i++){
                              int t;
                              t = (s[i]=='('&&s[i+len-1]==')'||s[i]=='['&&s[i+len-1]==']')?path[i][i+len-1] = -1,(len>2?dp[i+1][i+len-2]:0):MAX;
                              for(int k = i; k < i+len-1; k++)
                                      if(dp[i][k]+dp[k+1][i+len-1]<t){
                                                                      path[i][i+len-1] = k;
                                                                      t = min(t, dp[i][k]+dp[k+1][i+len-1]);
                                      }
                              dp[i][i+len-1] = t;
                      }
              cout << print(0,s.size()-1) << endl;
              system("pause");
}
