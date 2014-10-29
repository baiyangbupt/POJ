#include<iostream>
using namespace std;

const int len = 31268;
int num[len], total[len];
void init(){
     num[0]=total[0] = 0;
     num[1] = 1;
     total[1] = 1;
     for(int i = 2; i < len; i++){
             int t = 0, ti = i;
             while(ti){
                      t++;
                      ti/=10;
             }
             num[i] = num[i-1]+t;
             total[i] = total[i-1]+num[i];
             if(total[i]<0) break;
     }
     //cout << total[31267]<< endl;
}

int main(){
    init();
    int q,nc;
    cin >> nc;
    while(nc--){
                  cin>>q;
                  if(q>total[31267]) q-=total[31267];
                  else{
                      int i = 0;
                      while(q>total[i]) i++;
                      if(q==total[i]){
                                      cout<<i%10 << endl;
                                      continue;
                      }
                      q-=total[i-1];
                  }
                  int i = 0;
                  while(q>num[i]) i++;
                  if(q==num[i]){
                                cout << i%10 << endl;
                                continue;
                  }
                  q-=num[i-1];
                  int t = i, bits = 1;
                  while(t) t/=10, bits*=10;
                  bits/=10;
                  while(--q){
                           i = i-i/bits*bits;
                           bits/=10;
                  }
                  cout << i/bits << endl;
    }
                  
    system("pause");
}
