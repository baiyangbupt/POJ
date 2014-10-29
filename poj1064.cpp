#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

const double eps = 1e-5;
int k,n;
double a[100001];

int main(){
    while(cin >> n >> k){
              double mm = 0;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                mm = max(mm,a[i]);
        }
        
        double l = 0, r = mm, mid;
        while(l<r-eps){
                       mid = (l+r)/2;
                       int sum = 0;
                       for(int i = 1; i <= n; i++) sum+=int(a[i]/mid);
                       if(sum>=k) l = mid;
                       else r = mid;
        }
        int res = r*100;
        cout << setiosflags(ios::fixed) << setprecision(2)<<res/100.0 << endl;
        
    }
    system("pause");
}
