#include<iostream>
#include<string>
using namespace std;

char num2alph(int c){
     if(c==0) return '_';
     if(c==27) return '.';
     return c-1+'a';
}

int alph2num(char c){
    if(c=='_')
              return 0;
    if(c=='.')
              return 27;
    return c-'a'+1;
}

int k,cc[75],pc[75];

int main(){
    string s;
    while(cin>>k&&k){
                     cin >> s;
                     string res = s;
                     int n = s.size();
                     for(int i = 0; i < n; i++){
                             cc[i] = alph2num(s[i]);
                             //cout << cc[i] << " ";
                     }
                     //cout << endl;
                     for(int i = 0; i < n; i++){
                             int pi = k*i%n;
                             pc[pi] = (cc[i]+i)%28;
                     }
                     for(int i = 0; i < n; i++)
                             res[i] = num2alph(pc[i]);
                     cout << res << endl;
    }
}

