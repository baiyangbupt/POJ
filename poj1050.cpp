#include<iostream>

using namespace std;

int a[101][101], s[101];

int main(){
    int n, res = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                    cin >> a[i][j];
    
    for(int i = 1; i <= n; i++){
            memset(s,0,sizeof(s));
            for(int j = i; j >= 0; j--){
                    for(int k = 1; k <= n; k++)
                            s[k] += a[j][k];
                    
                    int m = 0, M = s[1];
                    for(int k = 1; k <= n; k++){
                            m += s[k];
                            M = max(m,M);
                            m = max(m,0);
                    }
                    res = max(res,M);
            }
    }
    cout << res << endl;
    system("pause");
}
                            
