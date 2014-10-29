#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    float bog = 0, avg, t;
    for(int i = 0; i < 12; i++){
            cin >> t;
            bog+=t;
    }
    avg = bog/12;
    cout<<"$" << setiosflags(ios::fixed) << setprecision(2)<<avg<<endl;
    system("pause");
}
