#include<iostream>
#include<string>
#include<map>

using namespace std;

int score[26] = {2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7},len,num[26],tnum[26],pos[26],bitnum[8],base[8];
int dp[10000];

bool canadd(int a, int b){
     for(int i = 1; i < len; i++){
             int ia = (a/base[i-1])%bitnum[i],ib = (b/base[i-1])%bitnum[i];
             if(ia+ib>=bitnum[i])
                                 return 0;
     }
     return 1;
}

int main(){
    string s;
    while(cin >> s){
              memset(num,0,sizeof(num));
              memset(pos,-1,sizeof(pos));
              memset(dp,0,sizeof(dp));
              int top;
              len = 1;
              for(int i = 0; i < s.size(); i++){
                      if(pos[s[i]-'a']<0)
                                         pos[s[i]-'a'] = len, num[s[i]-'a'] = 1, len++;
                      else
                          num[s[i]-'a']++;
              }
              for(int i = 0; i < 26; i++)
                      if(pos[i]>=0)
                                   base[pos[i]] = bitnum[pos[i]] = num[i]+1;
              
              base[0] = 1;
              for(int i = 1; i < len; i++)
                      base[i] = base[i-1]*base[i];
                      
              top = base[len-1];
              string t;
              while(cin>>t&&t!="."){
                                    memset(tnum,0,sizeof(tnum));
                                    int tscore = 0, valid = 1, state = 0;
                                    for(int i = 0; i < t.size() && valid; i++){
                                            if(tnum[t[i]-'a']==num[t[i]-'a'])
                                                                             valid = 0;
                                            else
                                                tnum[t[i]-'a']++,tscore+=score[t[i]-'a'];
                                    }
                                    
                                    if(valid==0) continue;
                                    for(int i  =0; i < 26; i++)
                                            if(pos[i]>=0)
                                                         state+=tnum[i]*base[pos[i]-1];
                                    dp[state] = tscore;
                                    for(int i = top; i >= 0; i--)
                                            if(dp[i]>0){
                                                        if(canadd(i,state)&&dp[i+state]<dp[i]+dp[state])
                                                                                                        dp[i+state] = dp[i] + dp[state];
                                            }
              }
              int res = 0;
              for(int i = top; i>=0; i--)
                      res = max(res,dp[i]);
              cout << res << endl;
    }
}
