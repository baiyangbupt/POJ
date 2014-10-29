#include<iostream>
using namespace std;

int b,cost[6][6][6][6][6],c[6],k[6],p[6],code2num[1000],special[5],tcost[6][6][6][6][6];

void copy(){
     for(int i0 = 0; i0 <= k[0]; i0++)
             for(int i1 = 0; i1 <= k[1]; i1++)
                     for(int i2 = 0; i2 <= k[2]; i2++)
                             for(int i3 = 0; i3 <= k[3]; i3++)
                                     for(int i4 = 0; i4 <= k[4]; i4++)
                                             tcost[i0][i1][i2][i3][i4] = cost[i0][i1][i2][i3][i4];
}

void init(){
     for(int i0 = 0; i0 <= k[0]; i0++)
             for(int i1 = 0; i1 <= k[1]; i1++)
                     for(int i2 = 0; i2 <= k[2]; i2++)
                             for(int i3 = 0; i3 <= k[3]; i3++)
                                     for(int i4 = 0; i4 <= k[4]; i4++)
                                             cost[i0][i1][i2][i3][i4] = p[0]*i0+p[1]*i1+p[2]*i2+p[3]*i3+p[4]*i4;
     copy();
}

void print(){
     for(int i0 = 0; i0 <= k[0] ; i0++)
             for(int i1 = 0; i1 <= k[1]; i1++)
                     cout << i0 << " " << i1 << " " << cost[i0][i1][0][0][0] <<" " << tcost[i0][i1][0][0][0]<< endl;
     cout << endl;
}

int main(){
    while(cin>>b){
                  memset(cost,0,sizeof(cost));
                  memset(k,0,sizeof(k));
                  for(int i = 0; i < b; i++){
                          cin >> c[i] >> k[i] >> p[i];
                          code2num[c[i]] = i;
                  }
                  init();
                  //print();
                  int s;
                  cin >> s;
                  for(int i = 0; i < s; i++){
                            int items,reduce,num,code;
                            memset(special,0,sizeof(special));
                            cin >> items;
                            for(int j = 0; j < items; j++){
                                    cin >> code >> num;
                                    special[code2num[code]] = num;
                                    //cout << "special " << code2num[code] << " " << num << endl;
                            }
                            
                            cin >> reduce;
                            for(int i0 = 0; i0+special[0]<=k[0]; i0++)
                                   for(int i1 =0; i1+special[1]<=k[1]; i1++)
                                           for(int i2 = 0; i2+special[2]<=k[2]; i2++)
                                                   for(int i3 = 0; i3+special[3]<=k[3]; i3++)
                                                           for(int i4 = 0; i4+special[4]<=k[4]; i4++){
                                                                   if(cost[i0+special[0]][i1+special[1]][i2+special[2]][i3+special[3]][i4+special[4]]>cost[i0][i1][i2][i3][i4]+reduce)
                                                                      cost[i0+special[0]][i1+special[1]][i2+special[2]][i3+special[3]][i4+special[4]] = cost[i0][i1][i2][i3][i4]+reduce;
                                                           }
                            copy();
                            //print();
                  }
                  cout << cost[k[0]][k[1]][k[2]][k[3]][k[4]] << endl;
    }
}
