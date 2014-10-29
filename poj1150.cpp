#include<iostream>

using namespace std;

int getns(int n, int b){
    if(n==0) return 0;
    
    return n/b+getns(n/b,b);
} 

int g(int n, int b){
    if(n==0) return 0;
    
    return n/10+(n%10>=b)+g(n/5,b);
}

int getx(int n, int b){
    if(n==0) return 0;
    
    return getx(n/2,b)+g(n,b);
}


int resi[4][4] = {2,4,8,6,3,9,7,1,7,9,3,1,9,1,9,1};
int main(){
    int n,m;
    while(cin>>n>>m){
                     int twos = 0, fives = 0, threes = 0, sevens = 0, nines = 0;
                     
                     twos = getns(n,2) - getns(n-m,2);
                     fives = getns(n,5) - getns(n-m,5);
                     threes = getx(n,3) - getx(n-m,3);
                     sevens = getx(n,7) - getx(n-m,7);
                     nines = getx(n,9) - getx(n-m,9);
                     
                     if(twos<fives){
                                    cout << "5" << endl;
                                    continue;
                     }
                     
                     twos -= fives;
                     int res = 1;
                     if(twos!=0) res *= resi[0][(twos-1)%4];
                     if(threes!=0) res *= resi[1][(threes-1)%4];
                     if(sevens!=0) res *= resi[2][(sevens-1)%4];
                     if(nines!=0) res *= resi[3][(nines-1)%4];
                     res %= 10;
                     cout << res << endl;
    }
}
                              
