#include<iostream>
using namespace std;

int oddblack, evenblack, oddwhite, evenwhite;

int main(){
    int nc,n;
    cin >> nc;
    while(nc--){
                int t;
                oddblack = evenblack = oddwhite = evenwhite = 0;
                cin >> n;
                if(n%2){
                        for(int  i = 0; i < n; i++) cin >> t;
                        cout << "YES" << endl;
                }
                else{
                     for(int i = 0; i < n; i++){
                             cin >> t;
                             if(t==1){
                                      if(i%2) oddblack++;
                                      else evenblack++;
                             }
                             else{
                                  if(i%2) oddwhite++;
                                  else evenwhite++;
                             }
                     }
                     if(evenwhite-oddwhite>1||oddwhite-evenwhite>1||oddblack-evenblack>1||evenblack-oddblack>1)
                                                                                                               cout << "NO" << endl;
                     else cout << "YES" <<endl;
                }
    }
}
