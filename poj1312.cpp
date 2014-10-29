#include<iostream>
#include<string>
using namespace std;

string base[20];

void reverse(string &s){
     int i = 0, j = s.size()-1;
     while(i<j){
                swap(s[i],s[j]);
                i++,j--;
     }
}

string add(string a, string b){
       if(a.size()>b.size()) swap(a,b);
       reverse(a),reverse(b);
       string res;
       int jinwei = 0, l1 = a.size(), l2 = b.size();
       int i;
       for(i = 0; i < l1; i++){
               int t1 = a[i]-'0', t2 = b[i]-'0';
               int t = t1+t2+jinwei;
               res.push_back('0'+t%10);
               jinwei = t/10;
       }
       while(i<l2){
                   int t = b[i]-'0'+jinwei;
                   res.push_back('0'+t%10);
                   jinwei = t/10;
                   i++;
       }
       if(jinwei) res.push_back('1');
       reverse(res);
       if(res.size()==0)
                        res = "0";
       return res;
}

string multi(string a, string b){
       reverse(a), reverse(b);
       int l1 = a.size(), l2 = b.size();
       string res(l1+l2+1,'0');
       for(int i = 0; i< l1; i++){
               int jinwei = 0;
               for(int j = 0; j < l2; j++){
                       int t1 = a[i]-'0', t2 = b[j]-'0';
                       int s = t1*t2+jinwei+res[i+j]-'0';
                       res[i+j] = s%10+'0', jinwei = s/10;
               }
               int p = i+l2;
               while(jinwei){
                             int t = res[p]-'0'+jinwei;
                             res[p] = t%10+'0', jinwei = t/10;
                             p++;
               }
       }
       reverse(res);
       int i = 0;
       while(i<res.size()&&res[i]=='0')
                                     i++;
       if(i==res.size()) return "0";
       return res.substr(i);
}

string minu(string a, string b){
       reverse(a),reverse(b);
       if(a.size()<b.size())
                            return "-1";
       
       string res;
       int jiewei = 0;
       for(int i = 0; i < b.size(); i++){
               int t1 = a[i]-'0', t2 = b[i]-'0';
               int t = t1-t2-jiewei;
               if(t<0)
                      t+=10, jiewei = 1;
               else jiewei = 0;
               res.push_back(t+'0');
       }
       int p = b.size();
       while(p<a.size()){
                     int t = a[p]-'0'-jiewei;
                     if(t<0)
                            t+=10, jiewei = 1;
                     else jiewei = 0;
                     res.push_back(t+'0');
                     p++;
       }
       if(jiewei) return "-1";
       reverse(res);
       int i = 0;
       while(i<res.size()&&res[i]=='0') i++;
       if(i==res.size()) return "0";
       return res.substr(i);
}

void init(){
     base[0] = "1", base[1] = "26";
     for(int i = 2; i < 20; i++)
             base[i] = multi(base[i-1],"26");
}

string solvealpha(string s){
     string res = "0";
     reverse(s);
     for(int i = 0; i < s.size(); i++){
             string t(1,s[i]-'a'+'1'), temp = multi(t,base[i]);
             res = add(res,temp);
     }
     return res;
}

string solvenum(string s){
     int i = 0;
     s = minu(s,"1");
     string res,t;
     while(i<20&&(t=minu(s,base[i]))!="-1"){
                                       if(t=="0"){
                                                  res.append(string(i+1,'a'));
                                                  return res;
                                       }
                                       i++;
     }
     i--;
     int st = i;
     while(i>=0){
                 int p = 0;
                 while((t=minu(s,base[i]))!="-1"){
                                                  //cout << s << " " << base[i] << endl;
                                                 p++;
                                             if(t=="0"){
                                                        if(i==0)
                                                                res.push_back(p+'a');
                                                        else res.push_back(p-1+'a');
                                                        res.append(string(i,'a'));
                                                        return res;
                                             }
                                             s = t;
                 }
                 if(i==0) res.push_back(p+'a');
                 else res.push_back(p-1+'a');
                 i--;
     }
     return res;
}
                                     
string print(string num){
     string res;
     reverse(num);
     for(int i = 0; i < num.size(); i++)
             if(i%3==2){
                        res.push_back(num[i]);
                        if(i!=num.size()-1) res.push_back(',');
             }
             else
                 res.push_back(num[i]);
                 
     reverse(res);
     return res;
}

string toprint(string s){
       s.append(string(22-s.size(),' '));
       return s;
}
                        

int main(){
    string a,b;
    init();
    while(cin>>a&&(a!="*")){
                  if(a[0]<='9'&&a[0]>='0')
                                          cout << toprint(solvenum(a)) << print(a) << endl;
                  else
                      cout << toprint(a) << print(solvealpha(a)) << endl;             
    }
}
