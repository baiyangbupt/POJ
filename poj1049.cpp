#include<iostream>
using namespace std;

int a[101][101],s[101],n;


int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                    cin >> a[i][j];
    int res = 0;
    for(int i = 1; i <= n; i++){
            memset(s,0,sizeof(s));
            for(int j = i; j >= 1; j--){
                    //cout << "s ";
                    for(int k = 1; k <= n; k++){
                            s[k]+=a[j][k];
                            //cout << s[k] << " ";
                    }
                    //cout << endl;
                    int m = 0, M = s[1];
                    //cout << "M ";
                    for(int i = 1; i <= n; i++){
                            m+=s[i];
                            M = max(m,M);
                            m = max(0,m);
                            //cout << M <<" ";
                    }
                    //cout << endl;
                    res = max(res,M);
            }
            
            
    }
    cout << res << endl;
    system("pause");
}
