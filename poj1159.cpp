#include<iostream>
#include<string>
using namespace std;

int dp[5001];
string reverse(string a){
     string res = a;
     int i = 0, j = res.size()-1;
     
     while(i<j){
                swap(res[i],res[j]);
                i++, j--;
     }
     return res;
}

int main(){
    string a,b;
    int l;
    while(cin>>l){
                  cin >> a;
                  b = reverse(a);
                  dp[0] = a[0]==b[0];
                  
                  for(int i = 1; i < l; i++) dp[i] = dp[i-1]==1?1:a[0]==b[i];
                  for(int i = 1; i < l; i++){
                          int t = dp[0],m;
                          dp[0] = dp[0]==1?1:a[i]==b[0];
                          
                          for(int j = 1; j < l; j++){
                                  m = dp[j];
                                  if(a[i]==b[j])
                                       dp[j] = max(t+1,max(dp[j],dp[j-1]));
                                  else
                                      dp[j] = max(dp[j],dp[j-1]);
                                  t = m;
                          }
                  }
                  cout << l-dp[l-1] << endl;
    }
}
