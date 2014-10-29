#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;


int grid[8][8],n,localsum[8][8];
int res;

int getsum(int x1, int y1, int x2, int y2){
    if(x1==0){
              if(y1==0)
                       return localsum[x2][y2];
              else 
                   return localsum[x2][y2] - localsum[x2][y1-1];
    }
    
    if(y1==0) return localsum[x2][y2] - localsum[x1-1][y2];
    
    return localsum[x2][y2] - localsum[x1-1][y2] - localsum[x2][y1-1] + localsum[x1-1][y1-1];
}

void dfs(int p, int x1, int y1, int x2, int y2, int tsum){
     if(p==n-1){
                int t = getsum(x1,y1,x2,y2);
                //cout <<tsum + t*t << endl;
                res = min(res,tsum + t*t);
                return ;
     }
     
     
     int sum = getsum(x1,y1,x2,y2);
     
     for(int x = x1; x < x2; x++){
                int t = getsum(x1,y1,x,y2);
                if(t*t+tsum<res)
                                dfs(p+1,x+1,y1,x2,y2,t*t+tsum);
                t = sum-t;
                if(t*t+tsum<res)
                                dfs(p+1,x1,y1,x,y2,tsum+t*t);
     }
     
     for(int y = y1; y < y2; y++){
             int t = getsum(x1,y1,x2,y);
                if(t*t+tsum<res)
                                dfs(p+1,x1,y+1,x2,y2,t*t+tsum);
                t = sum-t;
                if(t*t+tsum<res)
                                dfs(p+1,x1,y1,x2,y,tsum+t*t);
     }
}
             
                

int main(){
    while(cin>>n){
                  res = 0x7fffffff;
                  double avg;
                  memset(localsum,0,sizeof(localsum));
                  for(int i = 0; i < 8; i++){
                          cin >> grid[i][0];
                          localsum[i][0] = (i==0?0:localsum[i-1][0])+grid[i][0];
                          for(int j = 1; j < 8; j++){
                                  cin >> grid[i][j];
                                  localsum[i][j] = i==0?localsum[i][j-1]+grid[i][j]:localsum[i-1][j]+localsum[i][j-1]-localsum[i-1][j-1]+grid[i][j];
                          }
                  }
                  
                  avg = localsum[7][7]*1.0/n;
                  
                  dfs(0,0,0,7,7,0);
                  double temp = sqrt((double)(res)/n-avg*avg);
                  //cout << res <<" " << avg << endl;
                  cout << setiosflags(ios::fixed) << setprecision(3)<< temp << endl;
    }
}

