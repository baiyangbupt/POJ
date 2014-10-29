#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int n,c,fa[9],odd[9],cc[4];
vector<string> res;

int findp(int x){
    if(fa[x]==x)
                return x;
    return fa[x] = findp(fa[x]);
}

void Union(int x, int y){
    int m = findp(x), n = findp(y);
    if(m<n)
           fa[n] = m;
    else if(n<m)
         fa[m] = n;
}

void dfs(int p, int sum){
     if(p==4){
              if(sum!=c) return;
              string s;
              for(int i = 1; i <= n; i++){
                      int t = cc[0];
                      if(i%2) t+=cc[1];
                      else t+=cc[2];
                      if(i%3==1)
                                t+=cc[3];
                      s.push_back((t%2?0:1)+'0');
              }
              res.push_back(s);
              return;
     }
     
     for(int i = 0; sum+i<=c; i++){
             //cout << p << " " << i << endl;
             int fa1 = findp(p), fa2 = findp(p+4);
             bool od = i%2;
             if(odd[fa1]!=-1&&odd[fa1]!=od) continue;
             if(odd[fa1]!=-1)
                          cc[p] = i, dfs(p+1,sum+i);
             else{
                  cc[p] = i;
                  odd[fa1] = od;
                  odd[fa2] = 1-od;
                  dfs(p+1,sum+i);
                  odd[fa1] = -1;
                  odd[fa2] = -1;
             }
     }
}

int main(){
    while(cin >> n >> c){
              memset(odd,-1,sizeof(odd));
              for(int i = 0; i <= 8; i++) fa[i] = i;
              int x;
              while(cin>>x&&x!=-1){
                                   if(x%3==1){
                                              bool od = (c%2);
                                              int fa1 = x%2?findp(2):findp(1),fa2 = x%2?findp(6):findp(5);
                                              odd[fa1] = od?1:0, odd[fa2] = od?0:1;
                                   }
                                   else{
                                        if(x%2)
                                               Union(0,1), Union(0+4,1+4);
                                        else Union(0,2), Union(0+4,2+4);
                                   }
              }
              while(cin>>x&&x!=-1){
                                   if(x%3==1){
                                              bool od = 1-(c%2);
                                              int fa1 = x%2?findp(2):findp(1),fa2 = x%2?findp(6):findp(5);
                                              odd[fa1] = od?1:0, odd[fa2] = od?0:1;
                                   }
                                   else{
                                        if(x%2)
                                               Union(0,1+4), Union(0+4,1);
                                        else Union(0,2+4), Union(0+4,2);
                                   }
              }
              dfs(0,0);
              sort(res.begin(),res.end());
              for(int i = 0; i< res.size(); i++)
                      cout << res[i] << endl;
    }
}            
