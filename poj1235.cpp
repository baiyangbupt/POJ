#include<iostream>
using namespace std;

struct node{
       int next[6], deg;
}nn[30*30*30];

bool exist[30*30*30],visit[30*30*30];
int T,N,M,K,L;

void build(){
     for(int i = 0; i < N*M*K; i++){
             int deg = 0;
             if(i%N!=0)
                       nn[i].next[deg++] = i-1;
             if(i%N!=N-1)
                         nn[i].next[deg++] = i+1;
             if(i%(M*N)>=N)
                           nn[i].next[deg++] = i-N;
             if(i%(M*N)<N*(M-1))
                                nn[i].next[deg++] = i+N;
             if(i>=N*M)
                       nn[i].next[deg++] = i-N*M;
             if(i<N*M*(K-1))
                             nn[i].next[deg++] = i+N*M;
             nn[i].deg = deg;
     }
}

int dfs(int r){
    
    if(visit[r]) return 0;
    
    int num = 0;
    visit[r] = 1;
    for(int i = 0; i < nn[r].deg; i++){
            int t = nn[r].next[i];
            //cout << r << " " << t << " "<< endl;
            if(exist[t]){
                           num += dfs(t);
                          // cout << r << " " << t << " " << num << endl;
            }
    }
    
    return num+1;
}
    

int main(){
    cin >> T;
    while(T--){
               cin >> N >> M >> K >> L;
               build();
               int total = N*M*K, res = 0;
               memset(exist,1,sizeof(exist));
               for(int i = 0; i < L; i++){
                       int p,x;
                       cin >> p;
                       for(int j = 0; j < p; j++){
                               cin >> x;
                               exist[x] = 0;
                       }
                       total-=p;
                       int t = 0;
                       memset(visit,0,sizeof(visit));
                       for(int i = 0; i < N*M*K; i++)
                               if(exist[i]){
                                            t = dfs(i);
                                            break;
                               }
                       //cout << t << " " << total << endl;
                       if(t<total) res++;
               }                            
               cout << res << endl;
    }
    
               
}
