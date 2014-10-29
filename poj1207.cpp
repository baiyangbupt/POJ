#include<iostream>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;

const int MAX = 10001;
int dp[1000000],m[MAX<<4],num;

int dfs(int p){
    if(p>=MAX-1){
               int res;
               if(p%2==0) res = dfs(p/2)+1;
               else res = dfs(p*3+1)+1;
               return res;
    }
    
    if(dp[p]>0) return dp[p];
    
    if(p%2==0) return dp[p] = dfs(p/2)+1;
    
    return dp[p] = dfs(p*3+1)+1;
}

void pushup(int rt){
     m[rt] = max(m[rt<<1], m[rt<<1|1]);
}

void build(int l, int r, int rt){
     if(l==r){
              m[rt] = dp[l];
              //cout << l << " " << m[rt] << endl;
              return;
     }
     
     int m = (l+r)>>1;
     build(lson);
     build(rson);
     pushup(rt); 
}

int query(int L, int R, int l, int r, int rt){
    if(L<=l&&r<=R){
                   return m[rt];
    }
    
    int m = (l+r)>>1,r1 = 0,r2 = 0;
    if(L<=m) r1 = query(L,R,lson);
    if(R>m) r2 = query(L,R,rson);
    
    return max(r1,r2);
}

int main(){
    dp[1] = 1;
    for(int i = 1; i < MAX; i++){
            dfs(i);
    }
    build(1,MAX,1);
    int l,r;
    
    while(cin>>l>>r){
                     int templ = l, tempr = r;
                     if(r<l)
                            swap(l,r);
                            
                     cout << templ << " " << tempr << " " << query(l,r,1,MAX,1) << endl;
    }
}
