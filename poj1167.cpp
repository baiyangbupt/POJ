#include<iostream>
#include<algorithm>
using namespace std;

int n,a[303],stoptime[61],res,lines;
struct node{
       int st, d, stops;
}nn[18];

bool operator < (const node &a, const node &b){
     return a.stops > b.stops;
}

bool chk(int st, int d){
     int t =st;
     while(t < 60)
             if(stoptime[t]==0) return 0;
             else
                 t+=d;
     return 1;
}

void dfs(int p, int num){
    if(n == 0) {
         res = min(num,res);
         //cout << num << endl;
         return;
    }
     
     for(int i = p; i < lines; i++){
                                       if(num+ n / nn[i].stops>=res) return;
             if(chk(nn[i].st,nn[i].d)){
                                       
                                       int t = nn[i].st, d = nn[i].d;
                                       while(t<60)
                                                   n--, stoptime[t]--, t+=d;
                                       dfs(i,num+1);
                                       t = nn[i].st, d = nn[i].d;
                                       while(t<60)
                                                   n++, stoptime[t]++, t+=d;
             }
     }
}


int main(){
    cin >> n;
    memset(stoptime,0,sizeof(stoptime));
    for(int i = 0; i < n; i++){
            cin >> a[i];
            stoptime[a[i]] += 1;
    }
    
    lines = 0;
    for(int i = 0; i <= 29; i++){
            if(stoptime[i]==0) continue;
            for(int j = i+1; j <= 59-i; j++){
                    if(chk(i,j)){
                                            nn[lines].st = i;
                                            nn[lines].d = j;
                                            nn[lines].stops = (59-i)/j+1;
                                            lines++;
                    }
            }
    }
    sort(nn,nn+lines);
    res = 17;
    dfs(0,0);
    //int tt = res;
    
    cout << res << endl;
    system("pause");
}
