#include <iostream>
#include <cstdlib>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;

const int N = 10001;
int color[N<<4],res,hash[N],a[N],b[N],x[N<<2];

void pushdown(int rt){
     if(color[rt]!=0){
         color[rt<<1] = color[rt];
         color[rt<<1|1] = color[rt];
         color[rt] = 0;
     }
}

void update(int c, int L, int R, int l, int r, int rt){
     if(L<=l&&r<=R){
                    color[rt] = c;
                    return;
     }
     
     pushdown(rt);
     
     if(l==r) return;
     
     int m = (l+r)>>1;
     if(L<=m) update(c,L,R,lson);
     if(R>m) update(c,L,R,rson);
}

int query(int l, int r, int rt){
    if(color[rt]){
                   if(hash[color[rt]]==0) {
                                 
                                 hash[color[rt]] = 1;
                                 return 1;
                   }
                   return 0;
    }
    if(l==r) return 0;
    int res = 0;
    int m = (l+r)>>1;
    res+=query(lson);
    res+=query(rson);
    return res;
}

int comp(const void *a, const void *b){
    return *(int *)a-*(int *)b;
}

int halfsearch(int k, int *x, int len){
    int l = 0,h = len-1;
    while(l<=h){
                int m = (l+h)>>1;
                if(x[m]==k) return m;
                if(x[m]>k) h = m-1;
                else 
                     l = m+1;
    }
 }

int main(){
    int ncase;
    cin >> ncase;
    while(ncase--){
                   res=0;
                   memset(hash,0,sizeof(hash));
                   memset(color,0,sizeof(color));
                   int n;
                   cin >> n;
                   for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
                   for (int i = 0; i < n; i++){
                       x[2*i]=a[i];
                       x[2*i+1]=b[i];
                   }
                   qsort(x,2*n,sizeof(int), comp);
                   
                   int m = 1;
                   for (int i = 1; i<2*n;i++)
                       if(x[i]!=x[i-1])
                                       x[m++] = x[i];
                   for (int i = m-1; i > 0; i--) x[2*i] = x[i];
                   for (int i = m-1; i > 0; i--) x[2*i-1] = x[2*i];
                   for (int i = 1; i < m; i++) 
                       if(x[2*i]-x[2*(i-1)]>1)
                                              x[2*i-1] = (x[2*i]+x[2*(i-1)])>>1;
                   
                   int k = 1;
                   for (int i = 1; i<2*m;i++)
                       if(x[i]!=x[i-1])
                                       x[k++] = x[i];
                   for (int i = 0; i < n; i++){
                       int l,r;
                       l = halfsearch(a[i],x,k)+1;
                       r = halfsearch(b[i],x,k)+1;
                       cout << l<< " " << r << endl;
                       update(i+1,l,r,1,k,1);
                   }
                   cout << query(1,k,1) << endl;
    }
    system("pause");
}
