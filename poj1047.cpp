#include<iostream>
#include<set>
using namespace std;

string reverse(string a){
     string res = a;
     int l = 0, h = res.size()-1;
     while(l<h){
                swap(res[l],res[h]);
                l++, h--;
     }
     return res;
}

string add(const string a, const string b){
       int c[100];
       string s1, s2;
       if(a.size()<b.size())
           s1 = reverse(a), s2 = reverse(b);
       else
           s1 = reverse(b), s2 = reverse(a);
       memset(c,0,sizeof(c));
       int jinwei = 0, i;
       for(i = 0; i < min(s1.size(), s2.size()); i++){
               c[i] = s1[i]-'0'+s2[i]-'0'+jinwei;
               jinwei = c[i]/10;
               c[i] %= 10;
       }
       
       while(i<max(s1.size(),s2.size())){
                                         c[i] = s2[i]-'0'+jinwei;
                                         jinwei = c[i]/10;
                                         c[i]%=10;
                                         i++;
       }
       
       if(jinwei) c[i++] = 1;
       string res;
       for(int j = 0; j < i; j++) res.push_back('0'+c[j]);
       //cout << res << endl;
       res = reverse(res);
       return res;
}

int digit[10], cur[10];

bool solve(string a){
     memset(digit,0,sizeof(digit));
     for(int i = 0; i < a.size(); i++)
             digit[a[i]-'0']++;
     int n = a.size();
     string origin = a;
     set<string> hash;
     hash.insert(a);
     for(int i = 2; i <= n; i++){
             memset(cur,0,sizeof(cur));
             a = add(a,origin);
             if(a.size()!=n||hash.find(a)!=hash.end()) return 0;
             for(int j = 0; j < a.size(); j++)
                     if(cur[a[j]-'0']>=digit[a[j]-'0'])
                                                      return 0;
                     else cur[a[j]-'0']++;
             hash.insert(a);
     }
     return 1;
}

             
       

int main(){
    string s1,s2;
    while(cin>>s1)
                  if(solve(s1))
                      cout << s1 << " is cyclic" << endl;
                  else
                      cout << s1 << " is not cyclic" << endl;
                       }
