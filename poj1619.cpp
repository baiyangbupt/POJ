#include<iostream>
using namespace std;

const int MAXN = 1000005;

int rec[MAXN], next[MAXN], b[MAXN];

void maketable(){
     rec[1] = 1, rec[2] = 2;
     
     for(int i = 1; i < MAXN; i++)
             next[i] = i;
     next[2] = 4;
     for(int i = 2; i < MAXN; i++)
             if(b[i]==0){
                         for(int j = 1; j*i<MAXN; j++)
                            if(b[i*j]==0)
                                 b[i*j] = i;
             }
     
     int cur = 2;
     for(int i = 3; i < MAXN; i++){
             int k = cur;
             cur = MAXN;
             
             while(k!=1){
                         int p = b[k];
                         while(rec[next[p]]&&next[p]+p<MAXN)
                                                            next[p]+=p;
                         cur = min(cur,next[p]);
                         while(k%p==0)
                                      k/=p;
             }
             rec[cur] = i;
     }
}

int main(){
    int n;
    maketable();
    while(cin>>n, n){
                  cout << "The number "<<n<<" appears in location "<<rec[n] <<'.' << endl;
    }
}
