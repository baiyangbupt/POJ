#include<iostream>
using namespace std;

int n;

int main(){
    cin >> n;
    while(n--){
               int a;
               cin >> a;
               if(a<=2) cout << 0<< endl;
               else if(a%2==0)
               {
	                    cout << a*(a-4)/2+1 << endl;
               }
               else cout << a*(a-3)/2 << endl;
               
    }
}
               
               
