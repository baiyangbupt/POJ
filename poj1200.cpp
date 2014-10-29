#include<iostream>
#include<string>
#include<set>
using namespace std;

int n,nc,mod = 10000007;
bool hash[10000007];
int t[200];
int main(){
    string s;
    while(cin>>n>>nc){
                      cin >> s;
                      memset(t,-1,sizeof(t));
                      memset(hash,0,sizeof(hash));
                      int j = 0;
                      for(int i = 0; i < s.size(); i++)
                              if(t[s[i]]==-1)
                                             t[s[i]] = j++;
                      
                      int sum = 0, res = 0;
                      for(int i = 0; i < n; i++){
                              sum = (sum*nc + t[s[i]]) %mod;
                      }
                      sum = sum%mod;
                      hash[sum] = res = 1;
                      
                      for(int i = n; i < s.size(); i++){
                              int base = 1;
                              for(int j = 1; j < n; j++) base*=nc;
                              sum-=t[s[i-n]]*base;
                              sum = (sum*nc+t[s[i]])%mod;
                              //cout << sum << endl;
                              if(hash[sum]==0)
                                              res++, hash[sum] = 1;
                      }
                      cout << res << endl;
                      
    }
    
                               
}                  
