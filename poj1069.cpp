#include<iostream>
#include<algorithm>
using namespace std;

bool mp[101][101];
int a[11], b[11], n, s, cnt;

void print(){
     for(int i = 2*s; i > s; i--){
             for(int j = 1; j <= 4*s; j++)
                     cout << mp[i][j];
             cout << endl;
     }
     for(int i = s; i >= 1; i--){
             for(int j = 1; j <= 4*s; j++)
                     cout << mp[i][j];
             cout << endl;
     }
}

void init(){
     cin >> s;
     cin >> n;
     for(int i = 0; i < n; i++) cin >> a[i];
     sort(a, a+n);
     cnt = 0;
     for(int i = 0; i < n; i++){
             if(a[i]>2*s) break;
             bool vacan = 1;
             for(int j = 0; j < i && vacan; j++)
                     if(a[i]%b[j]==0)
                                     vacan = 0;
             if(vacan == 0) continue;
             b[cnt++] = a[i];
     }
     for(int i = 0; i < 101; i++)
             for(int j = 0; j < 101; j++) 
                     mp[i][j] = 1;
     
     for(int i = 1; i <= s; i++)
             for(int j = 1; j <= 2*s+1+2*(i-1); j++)
                     mp[i][j] = 0;
     for(int i = s+1; i <= 2*s; i++)
             for(int j = 2+2*(i-s-1); j <= 4*s; j++)
                     mp[i][j] = 0;
}

bool test(int x, int y, int k){
     if(y%2==0){
             for(int i = x; i >= x-b[k]+1; i--)
                     for(int j = y-2*(x-i); j <= y; j++)
                             if(i<=0||j<=0||mp[i][j]) return 0;
     }
     else{
          for(int i = x; i <= x+b[k]-1; i++)
                  for(int j = y; j <= y+2*(i-x); j++)
                          if(i<=0||j<=0||mp[i][j]) return 0;
     }
     return 1;
}

void mark(int x, int y, int k, int flag){
     if(y%2==0){
             for(int i = x; i >= x-b[k]+1; i--)
                     for(int j = y-2*(x-i); j <= y; j++)
                             mp[i][j] = flag;
     }
     else{
          for(int i = x; i <= x+b[k]-1; i++)
                  for(int j = y; j <= y+2*(i-x); j++)
                  mp[i][j] = flag;
     }
}

bool dfs(int x, int y){
     if(x==1&&y>4*s||x<1) return 1;
     cout << x << " " << y << endl;
     //print();
     
     if(y>4*s) return dfs(x-1,1);
     else if(mp[x][y]){
          int j;
          for(j = y+1; j<=4*s; j++)
                  if(mp[x][j]==0)
                                 break;
          return dfs(x,j);
     }
     else{
          for(int i = 0; i < cnt; i++){
             if(test(x,y,i)){
                             mark(x,y,i,1);
                             if(dfs(x,y+1)) return 1;
                             mark(x,y,i,0);
             }
             else break;
          }
     }
     return 0;
}
     
     
                          
int main(){
    int nc;
    cin >> nc;
    while(nc--){
                init();
                if(dfs(2*s,1)) cout << "YES"<<endl;
                else cout << "NO" << endl;
    }
}
