#include<iostream>
#include<sstream>
#include<string>
using namespace std;

string reverse(string s){
       int i = 0, j = s.size()-1;
       while(i<j){
                  swap(s[i],s[j]);
                  i++,j--;
       }
       string res = s;
       return res;
}

string add(string a,string b){
       string res;
       a = reverse(a), b = reverse(b);
       if(a.size()<b.size())
                            swap(a,b);
       int i,jinwei = 0;
       for(i = 0; i<b.size(); i++){
               int t = a[i]-'0' + b[i]-'0' +jinwei;
               res.push_back(t%10+'0');
               jinwei = t/10;
       }
       
       while(i<a.size()){
                         int t = a[i]-'0'+jinwei;
                         res.push_back(t%10+'0');
                         jinwei = t/10;
                         i++;
       }
       if(jinwei) res.push_back('0'+jinwei);
       res = reverse(res);
       i = 0;
       while(i<res.size()&&res[i]=='0')
                                       i++;
       res = res.substr(i);
       if(res.size()==0)
                        return "0";
       return res;
}

string multi(string a, string b){
       if(a=="0"||b=="0")
                         return "0";
       string res(a.size()+b.size(),'0');
       a = reverse(a), b = reverse(b);
       for(int i = 0; i < a.size(); i++){
               int jinwei = 0,j;
               for(j = 0; j < b.size(); j++){
                       int t = (a[i]-'0')*(b[j]-'0')+jinwei+res[i+j]-'0';
                       res[i+j] = '0'+t%10;
                       jinwei = t/10;
               }
               while(jinwei){
                             int t = res[i+j]-'0'+jinwei;
                             res[i+j] = '0'+t%10;
                             jinwei = t/10;
                             j++;
               }
       }
       
       res = reverse(res);
       int i = 0;
       while(i<res.size()&&res[i]=='0') i++;
       res = res.substr(i);
       if(res.size()==0)
                        return "0";
       return res;
}

string sub(string a, string b){
       if(a.size()<b.size())
                            return "-1";
       string res;
       a = reverse(a), b = reverse(b);
       int i,jiewei = 0;
       for(i = 0; i < b.size(); i++){
               int t = a[i]-b[i]-jiewei;
               if(t<0)
                      t+=10,jiewei = 1;
               else
                   jiewei = 0;
               res.push_back('0'+t);
       }
       while(i<a.size()){
                         int t = a[i]-'0'-jiewei;
                         if(t<0)
                                t+=10, jiewei = 1;
                         else
                             jiewei = 0;
                         res.push_back(t+'0');
                         i++;
       }
       if(jiewei)
                 return "-1";
       res = reverse(res);
       i = 0;
       while(i<res.size()&&res[i]=='0')
                                       i++;
       res = res.substr(i);
       if(res.size()==0)
                        return "0";
       return res;
} 

string itoa(int t){
       stringstream ss;
       ss<<t;
       string res;
       ss>>res;
       return res;
}

int atoi(string a){
    stringstream ss;
    ss<<a;
    int res;
    ss>>res;
    return res;
}

string base[51];
int num[55];
bool used[55];

void init(){
     base[1] = "1";
     for(int i =2; i <= 50; i++){
             string t = itoa(i);
             base[i] = multi(base[i-1],t);
     }
}

int main(){
    init();
    string a;
    string sol;
    bool begin = 1;
    while(cin>>a&&a!="-1"){
                  string res = "0",temp;
                  int cnt = 0;
                  for(int i = 0; i < a.size(); i++)
                          if(a[i]>'9'||a[i]<'0'){
                                                 if(temp.size()>0){
                                                                   num[cnt++] = atoi(temp);
                                                                   temp.clear();
                                                 }
                          }
                          else
                              temp.push_back(a[i]);
                  if(temp.size()>0)
                                   num[cnt++] = atoi(temp);
                  int n = num[0];
                  memset(used,0,sizeof(used));
                  for(int i = 1; i < cnt; i++){
                          int pre = 0;
                          for(int j = 1; j < num[i]; j++)
                                  if(used[j]==0)
                                                pre++;
                          res = add(res,multi(itoa(pre),base[n-i]));
                          used[num[i]] = 1;                              
                  }
                  if(begin)
                           sol.append(add(res,"1")), begin = 0;
                  else
                      sol.append(","), sol.append(add(res,"1"));
    }
    cout << sol << endl;
    system("pause");
}
