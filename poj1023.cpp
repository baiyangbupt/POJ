#include<iostream>
#include<string>
using namespace std;

string i2b(long long i){
       string res;
       while(i){
                res.insert(res.begin(),i%2+'0');
                i>>=1;
       }
       return res;
}

int main(){
    int t;
    string ba;
    cin >> t;
    while(t--){
               long long chk;
               int k;
               cin >> k;
               cin >> ba;
               cin >> chk;
               if(chk<0) {
                         chk = -1*chk;
                         for(int i = 0; i < ba.size(); i++)
                                 ba[i] = ba[i]=='n'?'p':'n';
               }
               string bin = i2b(chk),res;
               int l1 = bin.size(), l2 = ba.size();
               int i = l1;
               while(i<l2) bin.insert(bin.begin(),'0'), i++;
               if(l1>l2){
                                 cout << "Impossible" << endl;
                                 continue;
               }
               bool imp = 0;
               int jiewei = 0;
               for(int i = l2-1, j = l2-1; i>=0; i--, j--){
                       if(jiewei==0){
                                     if(ba[j]=='n'&&bin[i]=='1') jiewei = 1;
                                     res.insert(res.begin(),bin[i]);
                       }
                       else{
                            if(ba[j]=='p'&&bin[i]=='0') jiewei = 0;
                            res.insert(res.begin(),bin[i]=='0'?'1':'0');
                       }
               }
               if(jiewei) cout << "Impossible" << endl;
               else cout << res << endl;
    }
}
