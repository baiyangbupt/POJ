#include<iostream>
#define ll long long 
using namespace std;


int N,  M , a[50001], e[50001], s[50001];
ll a1,a2,a3,s1,s2,s3,e1,e2,e3;
int st[50000][16];

void rmq_build(){
     for(int i = 0; i < N; i++)
             st[i][0] = a[i];
     for(int bit = 1, inv = 2; inv < N; bit++, inv<<=1){
             for(int sp = 0; sp+inv-1<N; sp++){
                     int t = inv>>1;
                     st[sp][bit] = min(st[sp][bit-1],st[sp+t][bit-1]);
             }
     }
}

int query(int l, int r){
    int res = 9973, inv = 1, bit = 0, len = r-l+1;
    while(len){
               if(len&inv){
                           res = min(res,st[r-inv+1][bit]);
                           len-=inv;
                           r = r-inv;
               }
               bit++, inv<<=1;
    }
    return res;
}

int main(){
    int w;
    cin >> w;
    while(w--){
               cin >> N >> a1 >> a2 >> a3 >> M >>s1>> s2>> s3>> e1>> e2>> e3;
               a1 %= 9973, a2 %= 9973, a3 %= 9973;
               s1 %= N/2, s2 %= N/2, s3 %= N/2, e1 %= N/2, e2 %= N/2, e3 %= N/2;
               ll hn = N/2;
               for(int i = 0; i < N; i++)
                       a[i] = (((i%9973)*(i%9973)*a1)%9973+((i%9973)*a2)%9973+a3)%9973;
               for(int i = 0; i < M; i++){
                       s[i] = (((i%hn)*(i%hn)*s1)%hn+((i%hn)*s2)%hn+s3)%hn;
                       e[i] = (((i%hn)*(i%hn)*e1)%hn+((i%hn)*e2)%hn+e3)%hn + s[i];
               }
               rmq_build();
               int res = -1, m = -1;
               for(int i = 0; i < M; i++){
                       int t = query(s[i],e[i]);
                       if(t>m){
                               m = t, res = i; 
                       }
               }
               
               cout << res << endl;
    }
}
               
