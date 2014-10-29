#include<iostream>
using namespace std;

int dis[150][150],n;

int main(){
    while(cin>>n&&n){
                     for(int i = 0; i < n-1; i++)
                             for(int j = i+1; j < n; j++)
                                     cin >> dis[i][j];
                     
                     int res = 0;
                     for(int i = 0; i < n-2; i++){
                             int j = i+1, k = i+2;
                             res += (dis[i][j]+dis[i][k]-dis[j][k])/2;
                     }
                     res+=dis[n-2][n-1];
                     cout << res << endl;
    }
}
