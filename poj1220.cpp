#include<iostream>
#include<string>
#include<sstream>
using namespace std;

void reverse(string &s){
     int i = 0, j = s.size()-1;
     while(i<j){
                swap(s[i],s[j]);
                i++,j--;
     }
}

string mul(string a, string b){
       string res(a.size()+b.size()+1,'0');
       reverse(a), reverse(b);
       
       int i,j;
       for(i = 0; i < b.size(); i++){
               int jinwei = 0, tb = b[i]-'0';
               for(j = 0; j < a.size(); j++){
                       int ta = a[j]-'0';
                       int t = res[i+j]-'0'+ta*tb+jinwei;
                       res[i+j] = t%10+'0';
                       jinwei = t/10;
               }
               while(jinwei){
                             int t = res[i+j]-'0'+jinwei;
                             res[i+j] = '0'+t%10;
                             jinwei = t/10;
                             j++;
               }
       }
                       
       reverse(res);
       while(res.size()>1&&res[0]=='0') res.erase(res.begin());
       
       return res;
}

string add(string a, string b){
       string res;
       reverse(a), reverse(b);
       int i, jinwei = 0, l = min(a.size(), b.size());
       for(i = 0; i < l; i++){
               int t = a[i]+b[i]-'0'-'0'+jinwei;
               res.push_back((t%10)+'0');
               jinwei = t/10;
       }
       while(i<a.size()){
                         int t = a[i]-'0'+jinwei;
                         res.push_back((t%10)+'0');
                         jinwei = t/10;
                         i++;
       }
       while(i<b.size()){
                         int t = b[i]-'0'+jinwei;
                         res.push_back((t%10)+'0');
                         jinwei = t/10;
                         i++;
       }
       if(jinwei) res.push_back('0'+jinwei);
       reverse(res);
       return res;
}

char tosymbol(int t){
     if(t<=9) return '0'+t;
     if(t<=35) return 'A'+t-10;
     return 'a'+t-36;
}

string itoa(int t){
       stringstream ss;
       string res;
       ss << t;
       ss >> res;
       return res;
}

string todigit(char c){
       if('0'<=c&&c<='9')
                          return itoa(c-'0');
       if('A'<=c&&c<='Z')
                         return itoa(c-'A'+10);
       return itoa(c-'a'+36);
}

char div(string &numerator, int denominator){
       string res;
       int t = 0;
       for(int i = 0; i < numerator.size(); i++){
               t*=10, t+=numerator[i]-'0';
               int temp = t/denominator;
               res.push_back('0'+temp);
               t%=denominator;
       }
       int i = 0;
       while(res.size()>1&&res[0]=='0') res.erase(res.begin());
       numerator = res;
       return tosymbol(t);
}

string convert(string base10, int newbase){
       string res;
       while(base10!="0"){
                          //cout << base10 << endl;
                          res.push_back(div(base10,newbase));
       }
       
       reverse(res);
       return res;
}
       

int main(){
    string s,b;
    int a,nc;
    cin >> nc;
    for(int i = 0; i < nc; i++){
            string from, base = "1";
            int to;
            cin >> from >> to;
            cin >> s;
            cout << from << " " << s << endl;
            if(from!="10"){
                         string temp = "0",onedigit;
                         for(int j = s.size()-1; j >= 0; j--){
                                 onedigit = mul(todigit(s[j]),base);
                                 //cout << onedigit << endl;
                                 //cout << temp << endl;
                                 temp = add(temp,onedigit);
                                 base = mul(base,from);
                         }
                         s = temp;
            }
            
            if(to!=10){
                       string res = convert(s,to);
                       if(res.size()==0)
                                        res = "0";
                      cout <<to << " " << res << endl;
            }
            else
                cout << to << " " << s << endl;
            cout << endl;
    }
} 
