#include<iostream>
#include<string>
using namespace std;

int val(char c){
    if(c<='9'&&c>='0') return c-'0';
    if(c<='z'&&c>='a') return c-'a'+36;
    if(c<='Z'&&c>='A') return c-'A'+10;
}


int main(){
    string s;
    while(cin >> s){
              int base = 0;
              for(int i = 0; i < s.size(); i++) base = max(base,val(s[i]));
              int i;
              for(i = base+1; i < 63; i++){
                      int t = 0;
                      for(int j = s.size()-1; j >= 0; j--){
                              t+=val(s[j]);
                      }
                      //cout << t << endl;     
                      if(t%(i-1)==0) break;
              }
              if(i<63) cout << i << endl;
              else cout << "such number is impossible!" << endl;
    }
}
