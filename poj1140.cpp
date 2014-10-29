#include<iostream>
#include<string>
#include<map>
using namespace std;

int exGCD(int a, int b, int &x ,int &y){
    if(a>b) return exGCD(b,a,y,x);
    
    if(a==0){
             x = 0, y = 1;
             return b;
    }
    
    int r = exGCD(b%a,a,x,y);
    int t = x;
    x = y-b/a*x, y = t;
    return r;
}

string res;

int quotient(int a, int b){
     res.clear();
     res.push_back('.');
     map<int,int> fraction;
     bool over;
     int pos = 1;
     while(1){
              a *= 10;
              if(fraction.find(a)!=fraction.end())
                                                   return pos-fraction[a];
              else
                  fraction[a] = pos;
              if(a%b==0){
                         res.push_back('0'+a/b);
                         return 0;
              }
              
              res.push_back('0'+a/b);
              a = a%b;
              pos++;
     }
}

int main(){
    int a, b, x, y;
    while(cin>>a>>b&&a){
                        int t = exGCD(a,b,x,y);
                        a/=t, b/=t;
                        int repeat =quotient(a,b);
                        int i = 0;
                        while(i+49<res.size()){
                                               cout << res.substr(i,50)<<endl;
                                               i+=50;
                        }
                        if(i<res.size()){
                                         cout << res.substr(i) << endl;
                        }
                        if(repeat==0){
                                     cout << "This expansion terminates." << endl;
                        }
                        else{
                             cout << "The last " << repeat<< " digits repeat forever."<< endl;
                        }
    }
}
            
