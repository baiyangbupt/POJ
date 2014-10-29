#include<iostream>
using namespace std;

struct wall{
       int l,r;
}ww[101];

struct col{
       bool haswall[101];
       int numofwall;
       col(){
             numofwall = 0;
             memset(haswall,0,sizeof(haswall));
       }
};

int T,N,K;

int main(){
    cin >> T;
    while(T--){
               cin >> N>> K;
               col cc[101];
               int rmargin = 0, lmargin = 1000, res = 0;
               for(int i = 0; i < N; i++){
                       int a,b,c,d;
                       cin >> a >> b >> c >> d;
                       if(a>c) swap(a,c);
                       lmargin = min(lmargin,a);
                       rmargin = max(rmargin,c);
                       ww[i].l = a, ww[i].r = c;
                       for(int j = a; j <= c; j++){
                               cc[j].haswall[i] = 1;
                               cc[j].numofwall++;
                       }
               }
               
               for(int i = lmargin; i <= rmargin; i++)
                       while(cc[i].numofwall>K){
                                                int m = -1, mi = -1;
                                                for(int j = 0; j < N; j++)
                                                        if(cc[i].haswall[j]>0&&ww[j].r>m)
                                                                                         m = ww[j].r, mi = j;
                                                int l = ww[mi].l, r = ww[mi].r;
                                                for(int j = l; j <= r; j++)
                                                        cc[j].haswall[mi] = 0, cc[j].numofwall--;
                                                res++;
                       }
               cout << res << endl;
    }
}
                       
