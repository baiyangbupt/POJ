#include<iostream>
using namespace std;

int n,a[10001], b[10001];

int main(){
     int nc;
     cin >> nc;
     while(nc--){
                 cin >> n;
                 for(int i = 1; i <= n; i++){
                         cin >> a[i];
                         b[a[i]] = i;
                 }
                 
                 int res = 0;
                 for(int i = 1; i <= n; i++)
                         if(a[i]!=i){
                                     int cnt = 0, posi = i, targetposi = a[i], p = b[i];
                                     while(posi!=targetposi){
                                                             swap(a[posi],a[p]);
                                                             posi = p;
                                                             p = b[p];
                                                             cnt++;
                                     }
                                     res += cnt;
                         }
                 cout << res << endl;
     }
     }
                                     
