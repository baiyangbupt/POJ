#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

const int N = 10000, SEG = 10000000;
int p[2*N],n;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
            cin >> p[i];
    
    sort(p,p+n);
    
    for(int i = 0; i < n; i++) p[i+n] = p[i]+SEG;
    
    int i = 0, j;
    double res,tempres = 0;
    int sym = p[i]+SEG/2;
    
    for(j = 1; p[j]<=sym; j++){
            tempres += p[j]-p[i];
    }
    int st = j;
    while(j<n)
              tempres += SEG-(p[j]-p[i]), j++;
    
    res = tempres;
    for(i = 1; i < n; i++){
          sym = p[i]+SEG/2;
          
          for(j = st; p[j] <= sym; j++){
                  tempres += p[j] - p[i];
                  tempres -= SEG - (p[j]-p[i-1]);
          }
          
          tempres += (p[i]-p[i-1])*(n-st+2*i-j);
          st = j;
          res = min(res,tempres);
    }
    
    cout << setiosflags(ios::fixed) << setprecision(0) << res << endl;
    system("pause");
}
     
