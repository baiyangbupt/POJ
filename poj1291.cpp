#include<iostream>
#include<string>
using namespace std;

int fa[2002],num[2002],N;
bool visit[1001];

int find(int x){
    if(fa[x]==x)
                return x;
    return fa[x] = find(fa[x]);
}

void Union(int x, int y){
     int m = find(x), n = find(y);
     if(m<n)
            fa[n] = m, num[m]+=num[n];
     else if(m>n)
          fa[m] = n, num[n] += num[m];
}

int main(){
    while(cin>>N&&N){
                  for(int i = 1; i <= 2*N; i++)
                          fa[i] = i, num[i] = 0;
                  for(int i = 1; i <= N; i++)
                          num[i] = 1;
                  
                  bool invalid = 0;
                  string s;
                  int t;
                  for(int i = 1; i <= N; i++){
                          cin >> s;
                          cin >> t;
                          cin >> s;
                          cin >> s;
                          if(s=="true."){
                                         int m = find(i), n = find(t);
                                         if(m-n==N||n-m==N){
                                                            invalid = 1;
                                         }
                                         Union(m,n);
                                         Union(m+N,n+N);
                          }
                          else{
                               int m = find(i), n = find(t);
                               if(m==n){
                                        invalid = 1;
                               }
                               Union(m+N,n);
                               Union(m,n+N);
                          }
                  }
                  if(invalid){
                              cout <<"Inconsistent" << endl;
                              continue;
                  }
                  memset(visit,0,sizeof(visit));
                  int res = 0;
                  for(int i = 1; i <= N; i++){
                          int m = find(i);
                          if(visit[m]==0){
                                          int n = find(i+N);
                                          //cout << i << " " << fa[i] << " " << num[m] << " " << n << " " << num[n] << endl;
                                          res += max(num[m],num[n]);
                                          visit[m] = visit[n] = 1;
                          }
                  }
                  cout << res << endl;
    }
                  
}
