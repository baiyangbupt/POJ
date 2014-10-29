#include<iostream>
#include<sstream>
#include<string>
using namespace std;

string itoa(int t){
       string res;
       stringstream ss;
       ss<<t;
       ss>>res;
       return res;
}

void reverse(string &a){
     int i = 0, j = a.size()-1;
     while(i<j){
                swap(a[i],a[j]);
                i++, j--;
     }
}

string multi(string a, string b){
       reverse(a), reverse(b);
       string res(a.size()+b.size(),'0');
       for(int i = 0; i < a.size(); i++){
               int j,jinwei = 0;
               for(j = 0; j < b.size(); j++){
                       int t = (a[i]-'0')*(b[j]-'0')+jinwei+res[i+j]-'0';
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
       int i = 0;
       while(i<res.size()&&res[i]=='0')
                                       i++;
       res = res.substr(i);
       if(res.size()==0)
                        return "0";
       return res;
}

string fac[200];

int main(){
    
    fac[1] = "1";
    for(int i = 2; i < 200; i++){
            fac[i] = multi(fac[i-1],itoa(i));
            //cout << fac[i] << endl;
            }
    int n;
    while(cin>>n&&n!=-1){
                         cout << "N=" << n<< ":" << endl;
                         cout << multi("2",fac[n-1])<<endl;
    }
}
                             
