#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int MAXN = 1<<22;
bool dp[MAXN],visit[MAXN],set;
int n, a[21], s;
vector<int> win;

int pickNewNum(int state, int num) {
    int oState = state;
    int mul = 1;
    while(num*mul <= 20) {
        if(state&(1<<(num*mul))) state^=(1<<num*mul);
        for(int i = 2; i <= 20; ++i) {
            if(((oState & (1<<i)) == 0) && (i+num*mul <= 20)) {
                if(state & (1<<(i+num*mul))) state^=(1<<(i+num*mul));
            }
        }
        ++mul;
    }
    return state;
}

bool dfs(int p, int k){
     if(p==0) return dp[0] = 0;
     if(visit[p]) return dp[p];
     
     visit[p] = 1;
     bool mustwin = 0;
     for(int i = 2; i < 20; i++)
             if(p&(1<<i)){
                          int st = pickNewNum(p,i);
                          if(dfs(st,k+1)==0){
                                         if(k==0) win.push_back(i);
                                         mustwin = 1;
                          }
             }
     if(mustwin) return dp[p] = 1;
     return dp[p] = 0;
}
                          
     

int main(){
    int ca = 1;
    while(cin >> n&&n){
              win.clear();
              memset(visit,0,sizeof(visit));
              s = 0;
              for(int i = 0; i < n; i++){
                      cin >> a[i];
                      if((s&(1<<a[i]))==0)
                                        s ^= (1<<a[i]);
              }
              cout << "Test Case #" << ca++ << endl;
              
              if(dfs(s,0)){
                           cout << "The winning moves are:";
                         for(int i = 0; i < win.size(); i++)
                                 cout  << " "<< win[i];
                         cout << endl;
              }
              else
                  cout << "There's no winning move." << endl;
              cout << endl;
    }
}
