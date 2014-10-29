#include<iostream>
#include<algorithm>

using namespace std;

struct node{
       int l,w;
};

bool operator<(const node &a, const node &b){
     if(a.l==b.l) return a.w < b.w;
     return a.l<b.l;
}

node nn[5001];
bool visit[5001];

int main(){
     int nc,n;
     cin >> nc;
     while(nc--){
                 cin >> n;
                 for(int i = 0; i < n; i++) cin >> nn[i].l >> nn[i].w;
                 sort(nn,nn+n);
                 memset(visit,0,sizeof(visit));
                 int count = 0, res = 0;
                 while(count<n){
                                int i = 0;
                                while(visit[i]) i++;
                                int curw = nn[i].w;
                                visit[i] = 1;
                                count++;
                                for(int j = i+1; j < n; j++){
                                        if(visit[j]==0&&nn[j].w>=curw){
                                                          curw = nn[j].w;
                                                          count++;
                                                          visit[j] = 1;
                                        }
                                }
                                res++;
                 }
                 cout << res <<  endl;
     }
}
