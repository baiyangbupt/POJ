#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
bool visit[10000];

int main(){
    int nc = 1;
    while(cin>>m>>n&&m){
                        memset(visit,0,sizeof(visit));
                        for(int i = 0; i < n; i++){
                                int t;
                                cin >> t;
                                visit[t] = 1;
                        }
                        int p = n*m, num = 0, res = 0;
                        while(p>=0){
                                     if(visit[p])
                                                 num++, res = max(res,num);
                                     else
                                         num--;
                                     p--;
                        }
                        cout << "Case " << nc++ << ": " << res << endl;
    }
}
