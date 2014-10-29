#include<iostream>
using namespace std;

int gcd(int x, int y){
    if(x>y) return gcd(y,x);
    if(x==0) return y;
    return gcd(y%x, x);
}

int resi[20],mod[20];
int main(){
    int n,num = 1;
    int stdate,x,y,z;
    while(cin>>n&&n){
                     stdate = 0;
           for(int i = 0; i < n; i++){
                   cin >> x >> y >> z;
                   stdate = max(stdate,y);
                   mod[i] = z-y;
                   resi[i] = x%mod[i];
           }
           int res = resi[0], mul = mod[0];
           for(int i = 1; i < n; i++){
                   while(res%mod[i]!=resi[i]&&res<=10000)
                                                        res+=mul;
                   if(res>10000) break;
                   mul = mul/gcd(mul,mod[i])*mod[i];
           }
           
           while(res<stdate) res+=mul;
           cout << "Case #" << num << ":" << endl;
           if(res>=10000){
                         cout << "Unknown bugs detected" <<"."<< endl;
           }
           else{
                cout << "The actual year is " << res <<"."<< endl;
           }
           cout << endl;
           num++;
    }
}
