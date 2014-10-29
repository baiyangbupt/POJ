#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int N,A,B,cnt[13][1<<13];
map<string, int> mp;

struct node{
       int v,cnt,len;
       node(int a, int b, int c):v(a),cnt(b),len(c){}
};

bool operator<(const node &a, const node &b){
     if(a.cnt==b.cnt){
                      if(a.len==b.len)
                                      return a.v>b.v;
                      return a.len>b.len;
     }
     return a.cnt > b.cnt;
}

vector<node> res;

void print(int val, int len){
     int bit = (1<<(len-1));
     while(bit>0){
                  cout << ((val&bit)>0);
                  bit>>=1;
     }
}

void gprint(){
     int num = 0, i = 0;
     while(num<N&&i<res.size()){
                                int t = res[i].cnt;
                                cout << t;
                                while(i<res.size()&&res[i].cnt==t){
                                                                  cout << " ";
                                                                  print(res[i].v,res[i].len),i++;
                                }
                                cout << endl;
                                num++;
     }
}

int main(){
    string s,t;
    while(cin>>A>>B>>N){
                        memset(cnt,0,sizeof(cnt));
                        cin >> s;
                        int t = 0;
                        int i = 0,len = 0;
                        while(i<A)
                                  t<<=1, t+=s[i]-'0', i++;
                        cnt[A][t]++;
                        len = A;
                        while(i<s.size()-1){
                                          if(len<B){
                                                    t<<=1, t+=s[i]-'0', len++;
                                                    int j = 0, temp = 0, bit = 1;
                                                    while(j<A)
                                                              temp+=(t&bit), j++, bit<<=1;
                                                    while(j<=len)
                                                              cnt[j][temp]++, temp+=(t&bit), j++, bit<<=1;
                                          }
                                          else{
                                               t&=(~(1<<(B-1))), t<<=1, t+=s[i]-'0';
                                               int j = 0, temp = 0, bit = 1;
                                               while(j<A)
                                                         temp+=(t&bit), j++, bit<<=1;
                                               while(j<=len)
                                                            cnt[j][temp]++, temp+=(t&bit), j++, bit<<=1;
                                          }
                                          i++;
                        }
                         
                         res.clear();
                        for(int i = A; i <= B; i++)
                                for(int j = 0; j < (1<<B); j++)
                                        if(cnt[i][j]>0)
                                                        res.push_back(node(j,cnt[i][j],i));
                        
                        sort(res.begin(),res.end());
                        gprint();
    }
}
                        
