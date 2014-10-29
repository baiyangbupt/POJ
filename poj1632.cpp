#include<iostream>
#define ll long long
using namespace std;

long long state[40];
int n;

int count(long long x){
    int res = 0;
    while(x){
             res += (x&1);
             x>>=1;
    }
    return res;
}

bool canmatch(int p, int targetnum, int leftnum, long long right){
     if(p>36)
             return 0;
     
     if(count(right)<leftnum)
                             return 0;
     else if(leftnum==targetnum)
                        return 1;
     
     long long t = (right&state[p]);
     return (canmatch(p+1,targetnum,leftnum+1,t) || canmatch(p+1,targetnum,leftnum,right));
     
}     


int main(){
    int nc;
    cin >> nc;
    long long init = 0, base = 1;
    for(int i = 0; i < 40; i++){
            base<<=1;
            init |= base;
    }
    while(nc--){
                cin >> n;
                memset(state,0,sizeof(state));
                
                for(int i = 0; i <n; i++){
                        int a,b;
                        cin >> a >> b;
                        state[a]|=(1ll<<b);
                }
                int i = 1;
                while(canmatch(1,i,0,init)&&i*i<=n)
                                        i++;
                cout << i-1 << endl;
    }
}    
