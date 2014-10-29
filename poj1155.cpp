#include<iostream>
#include<vector>
using namespace std;

struct node{
       vector<int> weight,sons;
       int val;
}nn[3003];

int N,M,dp[3001][3001];

int treedp(int p){
     if(nn[p].val!=0){
                   dp[p][1] = nn[p].val;
                   dp[p][0] = 0;
                   return 1;
     }
     
     int mp = 0;
     int temp[3001];
     memset(temp,0,sizeof(temp));
     //cout << p << endl;
     for(int i = 0; i < nn[p].sons.size(); i++){
             //cout << nn[p].sons[i] << " ";
             int curp = nn[p].sons[i];
             int tp = treedp(curp);
             for(int j = 1; j <= tp; j++)
                     dp[curp][j]-=nn[p].weight[i];
             
             for(int j = 1; j <= tp; j++){
                     for(int k = mp; k >=0; k--)
                             dp[p][k+j] = max(dp[p][k+j], dp[curp][j]+temp[k]);
             }
             for(int i = 1; i <= mp+tp; i++) temp[i] = dp[p][i];
             mp += tp;
     }
     return mp;
}
             

int main(){
    cin >> N >> M;
    for(int i = 1; i <= N-M; i++){
            int t;
            cin >> t;
            for(int j = 0; j < t; j++){
                    int a,b;
                    cin >> a >> b;
                    nn[i].val = 0;
                    nn[i].sons.push_back(a), nn[i].weight.push_back(b);
            }
    }
    
    for(int i = N-M+1; i <= N; i++)
            cin >> nn[i].val;
    
    for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                    dp[i][j] = -100000;
    int m = treedp(1);
    int i;
    for(i = m; i >= 0; i--)
            if(dp[1][i]>=0)
                           break;
            cout << i << endl;
    system("pause");
    }
