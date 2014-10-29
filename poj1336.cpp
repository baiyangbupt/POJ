#include<iostream>
#include<set>
using namespace std;

int w[25][25],win[25],n,res[25];

bool test(int p){
     int twin[25];
     for(int i = 0; i < n; i++)
             twin[i] = win[i];
     
     for(int i = 0; i < n; i++)
             twin[p]+=w[i][p];
     
     for(int i = 0; i < n; i++)
             for(int j = i+1; j < n; j++)
                     if(i!=p&&j!=p){
                                    int t = w[i][j];
                                    while(t){
                                             if(twin[i]>twin[j])
                                                                twin[j]++, t--;
                                             else
                                                 twin[i]++,t--;
                                    }
                     }
     int m = 0;
     for(int i = 0; i < n; i++)
             if(m<twin[i])
                          m = twin[i];
     if(m>twin[p])
                  return 0;
     return 1;
}

int main(){
    int nc;
    cin >> nc;
    while(nc--){
                cin >> n;
                for(int i = 0; i < n; i++){
                        int a;
                        cin >> win[i] >> a;
                }
                for(int i = 0; i < n; i++)
                        for(int j = 0; j < n; j++)
                                cin >> w[i][j];
                
                int cnt = 0;
                for(int i = 0; i < n; i++)
                        if(test(i)){
                                    res[cnt++] = i+1;
                        }
                cout << res[0];
                for(int i = 1; i < cnt; i++)
                        cout << " " << res[i];
                cout << endl;
    }
}
