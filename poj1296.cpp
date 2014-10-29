#include<iostream>
using namespace std;

int l, a[401][401], b[401][401];

void printb(){
     for(int i = 1; i <= l; i++){
             for(int j = 1; j <= l; j++)
                     cout << b[i][j] << " ";
             cout << endl;
     }
     cout << endl;
}
void rotateb(){
     for(int i = 1; i <= l/2; i++){
             for(int j = l-i+1; j >= 2; j--){
                     swap(b[i][j],b[l+1-j][i]);
                     swap(b[l+1-j][i],b[l+1-i][l+1-j]);
                     swap(b[l+1-i][l+1-j],b[j][l+1-i]);
             }
     }
}

void flapb(){
     for(int i = 1; i <= l/2; i++)
             for(int j = 1; j <= l; j++)
                     swap(b[i][j],b[l-i+1][j]);
}

float def(){
      int res = 0;
      for(int i = 1; i <= l; i++)
              for(int j = 1; j <= l; j++)
                      if(max(b[i][j]-a[i][j],a[i][j]-b[i][j])<=100)
                                                                   res++;
      cout << res << endl;
      return (float)(res*1.0/(l*l));
}

int main(){
    while(cin>>l&&l){
                     for(int i = 1; i <= l; i++)
                             for(int j = 1; j <= l; j++)
                                     cin >> a[i][j];
                     cout << endl;
                     for(int i = 1; i <= l; i++)
                             for(int j = 1; j<=l; j++)
                                     cin >> b[i][j];
                     
                     cout << endl;
                     float res = def();
                     for(int i = 1; i <= 3; i++){
                             rotateb();
                             printb();
                             res = max(res, def());
                     }
                     rotateb();
                     flapb();
                     printb();
                     for(int i =1; i <= 4; i++){
                             res = max(res,def());
                             rotateb();
                             printb();
                     }
                     cout << res << endl;
    }
}
