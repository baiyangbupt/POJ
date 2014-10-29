#include<iostream>
#include<string>
using namespace std;

const double PI = 3.14159, derta = 0.0000001;

int main(){
    string s;
    while(cin>>s&&s!="ENDOFINPUT"){
                                   int x,y,z;
                                   cin >> x >> y >> z;
                                   z = min(z,360-z);
                                   double needed = x*z/360.*2*PI*2, cover = 5*y;
                                   if(cover>=needed){
                                                       cover-=needed;
                                                       cover/=5;
                                                       int res = cover;
                                                       cout << "YES " << res << endl;
                                   }
                                   else{
                                        cout << "NO " << cover << endl;
                                   }
                                   cin >> s;
    }
}
                                   
