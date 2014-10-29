#include<iostream>
#include<iomanip>
using namespace std;

int N,a[101*101][4][2],b[101*101][4][2],st[10000],ed[10000];


void init(){
      for(int i = 0; i < N*N; i++)
              a[i][0][0] = i/N, a[i][0][1] = i%N;
      for(int i = 1; i < 4; i++)
              for(int j = 0; j < N*N; j++){
                      a[j][i][0] = a[j][i-1][1];
                      a[j][i][1] = N-1-a[j][i-1][0];
              }
      
      for(int i = 0; i < N*N; i++)
              b[i][0][0] = i/N, b[i][0][1] = N-1-(i%N);
      for(int i = 1; i < 4; i++)
              for(int j = 0; j < N*N; j++){
                      b[j][i][0] = b[j][i-1][1];
                      b[j][i][1] = N-1-b[j][i-1][0];
              }
}

int dis(int a, int b, int c, int d){
    return (a-c>0?a-c:c-a)+(b-d>0?b-d:d-b);
}

int main(){
    int nc = 1;
    while(cin>>N&&N){
                     init();
                     int m;
                     cin >> m;
                     for(int i = 0; i < m; i++)
                             cin >> st[i] >> ed[i];
                     
                     int res = 1000000;
                     for(int i = 0; i < 4; i++){
                             int t = 0;
                             for(int j = 0; j < m; j++)
                                     t+=dis(a[st[j]-1][0][0],a[st[j]-1][0][1],a[ed[j]-1][i][0],a[ed[j]-1][i][1]);
                             res = min(res,t);
                     }
                     for(int i = 0; i < 4; i++){
                             int t = 0;
                             for(int j = 0; j < m; j++)
                                     t+=dis(a[st[j]-1][0][0],a[st[j]-1][0][1],b[ed[j]-1][i][0],b[ed[j]-1][i][1]);
                             res = min(res,t);
                     }
                     double avg = (res+m)*1.0/m;
                     cout << "Scenario " << nc<<": smallest average = ";
                     cout << setiosflags(ios::fixed) << setprecision(4) << avg << endl;
                     cout << endl;
                     nc++;
    }
}
              
