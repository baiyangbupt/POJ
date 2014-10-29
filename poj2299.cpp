#include <iostream>
#include <vector>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;

const int N = 500000;
int sum[500000<<2];

void pushup(int rt){
     sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}

void build(int l, int r, int rt){
     memset(sum,0,sizeof(sum));
}

void update(int p, int l, int r, int rt){
     if(l==r){
              sum[rt] = 1;
              return ;
     }
     int m = (l+r)>>1;
     if(p<=m) update(p,lson);
     else update(p,rson);
     pushup(rt);
}

int query(int p, int l, int r, int rt){
    if(l>=p)
            return sum[rt];
    int m = (l+r)>>1;
    if(m<p)   return query(p,rson);
    else return query(p,lson)+query(p,rson);
}

int bs(vector<int> &v, int k, int l, int h){
    while(l<=h){
                int m = (l+h)>>1;
                if(v[m]==k) return m;
                if(v[m]>k) h = m-1;
                else l = m+1;
    }
    return -1;
}

int main(){
    int n;
    while(cin >> n){
              if(n==0) break;
              build(1,n,1);
              int count = 0;
              vector<int> v(n),t(n);
              for(int i = 0; i < n; i++){
                      cin >> v[i];
                      t[i] = v[i];
              }
              sort(t.begin(),t.end());
              for(int i = 0; i < n; i++)
                      v[i] = bs(t, v[i], 0, n-1)+1;
              
              for(int i = 0; i < n; i++){
                      count+=query(v[i]+1,1,n,1);
                      update(v[i],1,n,1);
              }
              //for(int i = 0; i < n; i++) cout << sum[i] << " ";
              //cout << endl;
              cout << count << endl;
    }
}
