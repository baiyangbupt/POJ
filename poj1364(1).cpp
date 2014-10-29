#include<iostream>
#include<string>
using namespace std;

int n,m,dis[101],edge[1001][3];

bool relax(int u, int v, int c){
     if(dis[u]>dis[v]+c){
                         dis[u] = dis[v]+c;
                         return 1;
     }
     return 0;
}

int main(){
    while(cin>>n&&n){
                     cin >> m;
                     string s;
                     for(int i = 0; i < m; i++){
                             int a, b, c;
                             cin >> a >> b >> s >> c;
                             if(s[0]=='l'){
                                           edge[i][0] = a+b;
                                           edge[i][1] = a-1;
                                           edge[i][2] = c-1;
                             }
                             else{
                                  edge[i][0] = a-1;
                                  edge[i][1] = a+b;
                                  edge[i][2] = -c-1;
                             }
                     }
                     bool valid = 1;
                     dis[0] = 0;
                     for(int i = 1; i <= n; i++)
                             dis[i] = 100000000;
                     int i;
                     for(i = 1; i <= n; i++){
                             bool flag = 0;
                             for(int j = 0; j < m; j++)
                                     if(1==relax(edge[j][0],edge[j][1],edge[j][2]))
                                                                          flag = 1;
                             if(0==flag)
                                        break;
                     }
                     if(i<n){
                             cout << "lamentable kingdom" << endl;
                             continue;
                     }
                     for(int j = 0; j < m; j++){
                             if(1==relax(edge[j][0],edge[j][1], edge[j][2])){
                                                                valid = 0;
                                                                break;
                             }
                     }
                     if(valid==0)
                                 cout << "successful conspiracy" << endl;
                     else
                         cout << "lamentable kingdom" << endl;
    }
}
