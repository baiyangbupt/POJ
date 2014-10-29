#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool tanning[26], used[26];

int main(){
    int n;
    while(cin>>n&&n){
                     memset(tanning,0,sizeof(tanning));
                     memset(used,0,sizeof(used));
                     int res = 0, cnt = 0;
                     string s;
                     cin >> s;
                     for(int i = 0; i < s.size(); i++){
                             if(tanning[s[i]-'A'])
                                                  tanning[s[i]-'A']=0, cnt--;
                             else{
                                  if(used[s[i]-'A']) continue;
                                  if(cnt==n)
                                            res++,used[s[i]-'A'] = 1;
                                  else{
                                       tanning[s[i]-'A'] = 1, cnt++;
                                  }
                             }
                     }
                     if(res==0)
                               cout <<"All customers tanned successfully." << endl;
                     else
                         cout << res << " customer(s) walked away." << endl;
    }
}
