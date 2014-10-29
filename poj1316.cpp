#include<iostream>
using namespace std;

bool self[10000];

int main(){
    memset(self,0,sizeof(self));
    for(int i = 1; i < 10000; i++){
            if(self[i]==0)
                          cout << i << endl;
            int t = i, sum = i;
            while(t&&sum<10000){
                     sum+=t%10;
                     t/=10;
            }
            if(sum<10000) self[sum] = 1;
    }
    system("pause");
}
