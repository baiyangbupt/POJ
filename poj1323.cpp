#include<iostream>
#include<algorithm>
using namespace std;

bool visit[1500];

int m,n,a[550];

int main(){
    int nc = 1;
    while(cin>>m>>n&&m){
                        memset(visit,0,sizeof(visit));
                     int num = m*n;
                     for(int i = 0; i < n; i++)
                             cin >> a[i];
                     sort(a,a+n);
                     int res = 0,st = 1;
                     for(int i = 0; i < n; i++) visit[a[i]] = 1;
                     for(int i = 0; i < n; i++){
                             int j = a[i];
                             while(j<=num&&visit[j]) j++;
                             if(j>num){
                                       res+=n-i;
                                       break;
                             }
                             else
                                 visit[j] = 1;
                             j = st;
                             int pee = 0;
                             while(pee<m-2){
                                            if(visit[j]==0){
                                                            //cout << "j " << j << endl;
                                                           visit[j] = 1, pee++;
                                            }
                                            j++;
                             }
                             st = j;
                             //cout << res << endl;
                     }
                     cout << "Case " << nc++ << ": " <<res <<  endl;
    }
}
