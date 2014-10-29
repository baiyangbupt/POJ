#include <iostream>
#include <string>
using namespace std;

void reverse(string &a){
     int i = 0, j = a.size()-1;
     while(i<j){
                swap(a[i],a[j]);
                i++, j--;
     }
}

string multi(string a, string b){
      reverse(a); reverse(b);
      int la = a.size(), lb = b.size();
      int c[200];
      memset(c,0,sizeof(c));
      for(int i = 0; i < la; i++)
              for(int j = 0; j < lb; j++){
                      int t = (a[i]-'0')*(b[j]-'0');
                      c[i+j] += t;
              }
      
      int jinwei = 0;
      for(int i = 0; i < la+lb+2; i++){
              c[i] = c[i] + jinwei;
              jinwei = c[i]/10;
              c[i] = c[i]%10;
      }
      
      string res;
      int i = la+lb-1;
      while(i>=0&&c[i]==0) i--;
      if(i==-1) return "0";
      while(i>=0) res.push_back(c[i]+'0'), i--;
      return res;
}

int main(){
    string a;
    int n;
    while(cin >> a >> n){
        int dotindex, i = 0;
        while(i<a.size()&&a[i]!='.') i++;
        if(i<a.size()){
                        int j = a.size()-1;
                        while(j>=0&&a[j]=='0') j--;
                        a = a.substr(0,j+1);
                        //cout << a << endl;
        }
        string b,s;
        bool dot = 0;
        int dotpart = 0, dotnum = 0;
        for(int i = 0; i < a.size(); i++)
                if(dot==0&&a[i]!='.') s.push_back(a[i]);
                else if(dot==0&&a[i]=='.') dot = 1;
                else s.push_back(a[i]), dotpart++;
        b = "1";
        for(int i = 0; i < n; i++)
                b = multi(b,s), dotnum+=dotpart;
        int l = b.size();
        string res;
        if(dotnum==0){
                      cout << b << endl;
        }
        else{
            if(l<=dotnum){
                         string t(dotnum-l,'0');
                         res.push_back('.');
                         res.append(t);
                         res.append(b);
            }
            else{
                 res.append(b.substr(0,l-dotnum));
                 res.push_back('.');
                 res.append(b.substr(l-dotnum, dotnum));
            }
            int i = res.size()-1;
            while(i>=0&&(res[i]=='0'||res[i]=='.')) i--;
            if(i<0) res = "0";
            else res = res.substr(0,i+1);
            i = 0;
            while(i<res.size()&&res[i]=='0') i++;
            if(i==res.size()) cout << "0" << endl;
            else{
                 res = res.substr(i,res.size()-i);
                 cout << res << endl;
            }
        }
    }
}
