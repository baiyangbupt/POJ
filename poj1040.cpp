#include<iostream>

using namespace std;

int c,s,deal[22][3],d,capacity[8];

int dfs(int p){
    if(p==d) return 0;
    
    int st = deal[p][0], ed = deal[p][1], cc = deal[p][2];
    bool canhold = 1;
    for(int i = st; i < ed; i++)
            if(capacity[i]+cc>c){
                                 canhold = 0;
                                 break;
            }
    
    if(canhold==0)
                  return dfs(p+1);
    int r1, r2;
    for(int i = st; i < ed; i++)
            capacity[i]+=cc;
    
    r2 = dfs(p+1)+cc*(ed-st);
    for(int i = st; i < ed; i++)
            capacity[i]-=cc;
    r1 = dfs(p+1);
    return max(r1,r2);
}

int main(){
    while(cin>>c>>s>>d&&(c||s||d)){
                                      for(int i = 0; i < d; i++) cin >> deal[i][0] >> deal[i][1] >> deal[i][2];
                                      memset(capacity,0,sizeof(capacity));
                                      cout << dfs(0) << endl;
    }
}
