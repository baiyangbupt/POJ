#include<iostream>

using namespace std;

int d[16],a[20][20],b[20][20],day;

void update(){
     for(int i = 0; i < 20; i++)
             for(int j = 0; j < 20; j++)
                     a[i][j] = b[i][j];
}

int main(){
     cin >> day;
     for(int i = 0; i < 16; i++) cin >> d[i];
     for(int i = 0; i < 20; i++)
             for(int j = 0; j < 20; j++)
                     cin >> a[i][j];
     while(day--){
                  for(int i = 0; i < 20; i++)
                          for(int j = 0; j < 20; j++){
                                  b[i][j] = a[i][j]+d[a[i][j]+(i>0?a[i-1][j]:0)+(b>0?a[i][j-1]:0)+(i<19?a[i+1][j]:0)+(j<19?a[i][j+1]:0)];
                                  b[i][j] = b[i][j]>3?3:(b[i][j]<0?0:b[i][j]);
                          }
                  update();
     }
     
     for(int i=  0; i < 20; i++){
             for(int j = 0; j < 20; j++)
                     switch(a[i][j]){
                                     case 0:cout <<'.'; break;
                                     case 1:cout << '!'; break;
                                     case 2: cout << 'X'; break;
                                     default:cout << '#';
                     }
             cout << endl;
     }
     
     system("pause");
}
