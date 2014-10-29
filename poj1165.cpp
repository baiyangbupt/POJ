#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct node{
       int n1,n2,n3,n4,n5;
};

bool operator<(const node &a, const node &b){
     if(a.n1==b.n1&&a.n2==b.n2&&a.n3==b.n3&&a.n4==b.n4)
                                                       return a.n5 < b.n5;
     else if(a.n1==b.n1&&a.n2==b.n2&&a.n3==b.n3)
          return a.n4<b.n4;
     else if(a.n1==b.n1&&a.n2==b.n2)
          return a.n3<b.n3;
     else if(a.n1==b.n1)
          return a.n2 < b.n2;
     return a.n1<b.n1;
} 

vector<node> res;

bool isprime(int x){
     for(int i = 2; i*i <= x; i++)
             if(x%i==0)
                       return false;
     
     return true;
}

int grid[5][5],sum,rowset[5],colset[5],diagset[2],rowsum[5],colsum[5],diagsum[2],rownum[5],colnum[5],diagnum[2],con[5][5];
int base[5] = {10000,1000,100,10,1};


void update1(int x, int y, int t){
     grid[x][y] = t;
     rowset[x]++, colset[y]++, rowsum[x]+=t, colsum[y]+=t, rownum[x]+=t*base[y], colnum[y]+=t*base[x];
     if(x==y) diagset[0]++, diagsum[0]+=t, diagnum[0]+=t*base[x];
     if(x+y==4) diagset[1]++, diagsum[1]+=t, diagnum[1]+=t*base[y];
     for(int i = 0; i < 5; i++)
             if(grid[i][y]<0)
                             con[i][y]++;
     for(int i = 0; i < 5; i++)
             if(grid[x][i]<0)
                             con[x][i]++;
     if(x==y){
              for(int i = 0;  i< 5; i++)
                      if(grid[i][i]<0)
                                      con[i][i]++;
     }
     if(x+y==4){
                for(int i = 0; i < 5; i++)
                        if(grid[i][4-i]<0)
                                          con[i][4-i]++;
     }
}
void update2(int x, int y, int t){
     rowset[x]--, colset[y]--, rowsum[x]-=t, colsum[y]-=t, rownum[x]-=t*base[y], colnum[y]-=t*base[x];
     if(x==y) diagset[0]--, diagsum[0]-=t, diagnum[0]-=t*base[x];
     if(x+y==4) diagset[1]--, diagsum[1]-=t, diagnum[1]-=t*base[y];
     for(int i = 0; i < 5; i++)
             if(grid[i][y]<0)
                             con[i][y]--;
     for(int i = 0; i < 5; i++)
             if(grid[x][i]<0)
                             con[x][i]--;
     if(x==y){
              for(int i = 0;  i< 5; i++)
                      if(grid[i][i]<0)
                                      con[i][i]--;
     }
     if(x+y==4){
                for(int i = 0; i < 5; i++)
                        if(grid[i][4-i]<0)
                                          con[i][4-i]--;
     }
     grid[x][y] = -1;
}

void dfs(int set){   
     //cout << set << endl;
     if(set==24){
                 node n;
                 n.n1 = rownum[0], n.n2 = rownum[1], n.n3 = rownum[2], n.n4 = rownum[3], n.n5 = rownum[4];
                 res.push_back(n);
                 return;
     }
     
     int t = -1,x,y;
     bool undo = 1;
     for(int i = 0; i < 5 && undo; i++)
             for(int j = 0; j < 5&&undo; j++)
                     if(grid[i][j]<0){
                                      if(con[i][j]>t){
                                                      t = con[i][j];
                                                      x =i, y = j;
                                      }
                     }
     //cout << set << " " << x << " " << y << endl;
     /*if(x==5){
              for(int i = 0; i < 5; i++){
                      for(int j = 0; j < 5; j++)
                              cout << con[i][j] << " ";
                      cout << endl;
              }
     }*/
     if(rowset[x]==4){
                      t = sum - rowsum[x];
                      if((x==4||y==4)&&((t&1)==0)) return;
                      if(t==0&&(x==0||y==0)) return;           //0 can not be the beginning
                      if(!isprime(rownum[x]+t*base[y])) return;  //not prime
                      if(colset[y]==4&&(colsum[y]+t!=sum||!isprime(colnum[y]+t*base[x]))) return; //colum not match
                      if(colset[y]<4&&colsum[y]+t>sum) return;
                      if(x==y){
                               if(diagset[0]==4&&(diagsum[0]+t!=sum||!isprime(diagsum[0]+t*base[x]))) return; 
                               if(diagset[0]<4&&diagsum[0]+t>sum) return;
                      }
                      if(x+y==4){
                               if(diagset[1]==4&&(diagsum[1]+t!=sum||!isprime(diagsum[1]+t*base[y]))) return; 
                               if(diagset[1]<4&&diagsum[1]+t>sum) return;
                      }
     }
     else if(colset[y]==4){
                   t = sum - colsum[y];
                   if((x==4||y==4)&&((t&1)==0)) return;
                  if(t==0&&(x==0||y==0)) return;           //0 can not be the beginning
                  if(!isprime(colnum[y]+t*base[x])) return;  //not prime
                  if(x==y){
                           if(diagset[0]==4&&(diagsum[0]+t!=sum||!isprime(diagsum[0]+t*base[x]))) return; 
                           if(diagset[0]<4&&diagsum[0]+t>sum) return;
                  }
                  if(x+y==4){
                           if(diagset[1]==4&&(diagsum[1]+t!=sum||!isprime(diagsum[1]+t*base[y]))) return; 
                           if(diagset[1]<4&&diagsum[1]+t>sum) return;
                  }
     }
     else if(x==y&&diagset[0]==4){
                  t = sum -diagsum[0];
                  if((x==4||y==4)&&((t&1)==0)) return;
                  if(t==0&&(x==0||y==0)) return;
                  if(!isprime(diagnum[0]+t*base[x])) return;
                  if(x+y==4){
                           if(diagset[1]==4&&(diagsum[1]+t!=sum||!isprime(diagsum[1]+t*base[y]))) return; 
                           if(diagset[1]<4&&diagsum[1]+t>sum) return;
                  }
     }
     else if(x+y==4&&diagset[1]==4){
                               t = sum-diagsum[1];
                               if((x==4||y==4)&&((t&1)==0)) return;
                               if(t==0&&(x==0||y==0)) return;
                               if(!isprime(diagnum[1]+t*base[y])) return;
     }
       
     if(rowset[x]==4||colset[y]==4||(x==y&&diagset[0]==4)||(x+y==4&&diagset[1]==4)){                     
         update1(x,y,t);
         dfs(set+1);         
         update2(x,y,t);
     }
     else{
          int st = (x==0||y==0)?1:0;
          for(t = st; ;t++){
                if((x==4||y==4)&&((t&1)==0)) continue;
                if(t+rowsum[x]>sum||t+colsum[y]>sum||(x==y&&t+diagsum[0]>sum)||(x+y==4&&t+diagsum[1]>sum)) break;
                update1(x,y,t);
                dfs(set+1);
                update2(x,y,t);
          }
     }
}       
                                 
int main(){
    while(cin>>sum){
                    memset(grid,-1,sizeof(grid));
                    memset(rowset,0,sizeof(rowset));
                    memset(colset,0,sizeof(colset));
                    memset(diagset,0,sizeof(diagset));
                    memset(rownum,0,sizeof(rownum));
                    memset(colnum,0,sizeof(colnum));
                    memset(diagnum,0,sizeof(diagnum));
                    memset(rowsum,0,sizeof(rowsum));
                    memset(colsum,0,sizeof(colsum));
                    memset(diagsum,0,sizeof(diagsum));
                    memset(con,0,sizeof(con));
                    cin >> grid[0][0];
                    rowset[0] = 1;
                    colset[0] = 1;
                    diagset[0] = 1;
                    diagnum[0] = colnum[0] = rownum[0] = grid[0][0]*10000;
                    diagsum[0] = colsum[0] = rowsum[0] = grid[0][0];
                    
                    for(int i = 1;  i< 5; i++) con[0][i]++, con[i][0]++, con[i][i]++; 
                    dfs(0);
                    sort(res.begin(), res.end());
                    for(int i = 0; i < res.size(); i++){
                            cout << res[i].n1 << endl;
                            cout << res[i].n2 << endl;
                            cout << res[i].n3 << endl;
                            cout << res[i].n4 << endl;
                            cout << res[i].n5 << endl;
                            cout << endl;
                    }
    }
}
