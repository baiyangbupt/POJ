#include<iostream>
#include<string>
using namespace std;

int getmil(char c, int p){
    if(c=='Y'){
               if(p>500)
                        return p;
               return 500;
    }
    if(c=='F')
               return 2*p;
    if(p%2)
           return p+p/2+1;
    return p+p/2;
}

int main(){
    string a,b;
    char c;
    int p,res=0;
    while(cin>>a&&a!="#"){
                          if(a=="0"){
                                     cout << res << endl;
                                     res = 0;
                          }
                          else{
                               cin >> b >> p>>c;
                               res+=getmil(c,p);
                          }
    }
}

