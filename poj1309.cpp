#include<iostream>
using namespace std;

int num, person;

bool test(int n, int p){
     for(int i = 0; i < p; i++){
             if(n%p!=1)
                       return 0;
             n = (n-1)/p*(p-1);
     }
     return n%p==0;
}
int main(){
    test(25,3);
    while(cin>>num&&num!=-1){
                             int st = num;
                             while(st>0&&test(num,st)==0)
                                                   st--;
                             if(st==0)
                                      cout << num << " coconuts, no solution" << endl;
                             else 
                                  cout << num << " coconuts, " << st << " people and 1 monkey" << endl;
    }
}
