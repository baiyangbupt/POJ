#include<iostream>
using namespace std;

int m;
int a[15][15],mp[25][25];
bool down[25][25], right[25][25];

void print(){
     for(int i = 1; i <= 2*m-1; i++){
             for(int j  = 1; j <= 2*m+1; j++)
                     if(mp[i][j]==1) cout << "H";
                     else if(mp[i][j]==0) cout << "O";
                     else cout << " ";
             cout <<endl;
     }
     cout << "done" << endl;
}

int main(){ 
    int nc = 1;
    while(cin>>m&&m){
                     cout << "Case " << nc++ << ":" <<endl;
                     cout << endl;
                     bool right[25][25];
                     memset(mp,-1,sizeof(mp));
                     memset(down,0,sizeof(down));
                     memset(right,0,sizeof(right));
                     for(int i = 1; i <= m; i++)
                             for(int j = 1; j <= m; j++)
                                     cin >> a[i][j];
                     for(int i = 1; i <= m; i++){
                             int p = 1,row = 2*(i-1)+1;
                             for(int j = 1; j <= m; j++){
                                     //print();
                                     //cout << i << " " << j <<endl;
                                     if(j==1){
                                              if(a[i][j]==0){
                                                             right[row][p] = 1;
                                                            mp[row][p++] = 1, mp[row][p++] = 0;
                                                            if(row==1) down[row][2] = 1, mp[row+1][2] = 1;
                                                            else{
                                                                 mp[row-1][2]<0?(down[row-1][2] = 1, mp[row-1][2] = 1): (down[row][2] = 1,mp[row+1][2] = 1);
                                                            }
                                              }
                                              else if(a[i][j]==1){
                                                   right[row][p] = 1, mp[row][p++] = 1, right[row][p] = 1, mp[row][p++] = 0, mp[row][p++] = 1;
                                              }
                                              else{
                                               down[row-1][p] = down[row][p] = 1;
                                               mp[row-1][p] = 1, mp[row][p] = 0, mp[row+1][p] = 1, p++;
                                              } 
                                     }
                                     else{
                                          if(a[i][j]==0){
                                                         if(mp[row][p-1]==0){
                                                                             right[row][p] = 1;
                                                                            mp[row][p++] = 1, mp[row][p] = 0;
                                                                            if(row==1) down[row][p]=1, mp[row+1][p] = 1;
                                                                            else{
                                                                                 mp[row-1][p]<0?(down[row-1][p] = 1,mp[row-1][p] = 1): (down[row][p] = 1, mp[row+1][p] = 1);
                                                                            }
                                                                            p++;
                                                         }
                                                         else{
                                                              right[row][p] = 1;
                                                              mp[row][p] = 0;
                                                              if(row==1) down[row][p]=1, mp[row+1][p] = 1;
                                                              else{
                                                                   mp[row-1][p]<0?(down[row-1][p] = 1,mp[row-1][p] = 1): (down[row][p] = 1,mp[row+1][p] = 1);
                                                              }
                                                              p++;
                                                              mp[row][p++] = 1;
                                                         }
                                          }
                                          else if(a[i][j]==1) right[row][p] = 1, mp[row][p++] = 1, right[row][p] = 1,mp[row][p++] = 0, mp[row][p++] = 1;
                                          else{
                                               down[row-1][p] = down[row][p] = 1;
                                               mp[row-1][p] = 1, mp[row][p] = 0, mp[row+1][p] = 1, p++;
                                          }
                                     }
                             }
                     }
                     for(int i = 1; i <= 4*m+3; i++) cout << "*";
                     cout << endl;
                     for(int i = 1; i <= 2*m-1; i++){
                             cout << "*";
                             for(int j =1; j<2*m+1; j++){
                                     if(mp[i][j]==1) cout << "H";
                                     else if(mp[i][j]==0) cout << "O";
                                     else cout << " ";
                                     if(right[i][j]) cout << "-";
                                     else cout << " ";
                             }
                             if(mp[i][2*m+1]==0) cout << "O";
                             else if(mp[i][2*m+1]==1) cout << "H";
                             else cout << " ";
                             cout << "*";
                             cout << endl;
                             if(i<2*m-1){
                                         cout << "*";
                                         for(int j = 1; j <=4*m+1; j++)
                                                 if(j%2&&down[i][(j+1)/2])
                                                   cout << "|";
                                                 else
                                                     cout << " ";
                                         cout << "*";
                                         cout << endl;
                             }
                     }
                     for(int i = 1; i <= 4*m+3; i++) cout << "*";
                     cout << endl;
                     cout << endl;
    }
}
