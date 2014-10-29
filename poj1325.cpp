#include<iostream>
using namespace std;

int n,m,match[100],pre[100];
bool mp[100][100], visit[100];

int hung(int p){
    for(int i = 0; i < m; i++)
            if(mp[p][i]&&visit[i]==0){
                         visit[i] = 1;
                         if(pre[i]<0||hung(pre[i])){
                                                      pre[i] = p;
                                                      match[p]=  i;
                                                      return 1;
                         }
            }
    return 0;
}

int main(){
    int k;
    while(cin>>n&&n){
                         cin >> m >> k;
                           memset(mp,0,sizeof(mp));
                           memset(pre,-1,sizeof(pre));
                           for(int i = 0; i < k; i++){
                                   int x,y,z;
                                   cin >> x >> y >> z;
                                   if(y*z>0) mp[y][z] = 1;
                           }
                           int res = 0;
                           for(int i = 0; i < n; i++){
                                   memset(visit,0,sizeof(visit));
                                   res+=hung(i);
                           }
                           cout << res << endl;
    }
}
