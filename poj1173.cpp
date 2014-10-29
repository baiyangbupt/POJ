#include<iostream>
#include<string>
#include<map>
using namespace std;

int n,k,m,cnt,snum;
long long a[101];
map<long long, int> hash;

void print(long long s){
     if(s==0) return;
     print(s/2);
     cout << (s&1);
     return;
}
     

void dfs(int p, int zeros, int ones, long long &s, int bars){
     if(p==n&&bars<k) return;
     
     if(bars==k){
                 if(n-p+1>m) return;
                 long long t = (s&1), temp = s;
                 while(p<n) s<<=1, s+=t, p++;
                 if(hash.find(s)!=hash.end())
                                             hash[s] = cnt;
                 cnt++;
                 s = temp;
                 return;
     }
     
     long long t = s;
     if(zeros<m)
                s<<=1, ((s&2)==0)?dfs(p+1,zeros+1,0,s,bars):dfs(p+1,zeros+1,0,s,bars+1);
     s = t;
     if(ones<m)
               s<<=1, s+=1, ((s&2)>0)?dfs(p+1,0,ones+1,s,bars):dfs(p+1,0,ones+1,s,bars+1);
     
     return;
}

int main(){
    while(cin >> n >> k >> m){
              cin >> snum;
              for(int i = 0; i < snum; i++){
                      string t;
                      long long aa = 0;
                      cin >> t;
                      for(int j = 0; j < t.size(); j++){
                              aa+=t[j]-'0';
                              if(j<t.size()-1) aa<<=1;
                      }
                      a[i] = aa;
                      hash[aa] = 0;
              }
              cnt = 0;
              long long s = 1;
              dfs(1,0,1,s,1);
              cout << cnt << endl;
              for(int i = 0; i < snum; i++)
                      cout << hash[a[i]] << endl;
    }
}
