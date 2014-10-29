#include<iostream>
using namespace std;

int p[21], w[21];

int main(){
    int n,nc;
    cin >> nc;
    while(nc--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> p[i];
        
        w[1] = 1;
        for(int i = 2; i <= n; i++){
                if(p[i]-p[i-1]>=1){
                                   w[i] = 1;
                                   continue;
                }
                else{
                     int count = 0, j = i-1, t = w[j];
                     while(j>0&&p[i]-p[j]<i-j) j = j - 1;
                     if(j==0) w[i] = i;
                     else w[i] = i-j;
                }
        }
        for(int i = 1; i <= n; i++) cout << w[i] << " ";
        cout << endl;
    }
    system("pause");
}
