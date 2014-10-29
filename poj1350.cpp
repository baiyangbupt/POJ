#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

int atoi(string a){
    stringstream ss;
    ss<<a;
    int res;
    ss>>res;
    return res;
}

string itoa(int a){
       stringstream ss;
       ss<<a;
       string res;
       ss>>res;
       return res;
}

string simulate(string a){
    string s = a;
    int Max = 0, Min = 0;
    sort(s.begin(),s.end());
    int i = 0;
    while(i<s.size()&&s[i]=='0') i++;
    Min = atoi(s.substr(i));
    for(int i = s.size()-1; i>=0; i--){
            Max *= 10;
            Max += s[i]-'0';
    }
    cout << Max << "-" << Min << '=' << Max-Min<<endl;
    return itoa(Max-Min);
}
                        
     
int main(){
    string n;
    while(cin>>n&&n!="-1"){
                         cout << "N=" << n <<":" << endl;
                         string t  = n;
                         if(t.size()!=4){
                                         cout << "No!!" <<endl;
                                         continue;
                         }
                         bool valid = 1;
                         for(int i = 1; i < 10; i++)
                                 if(t==string(4,'0'+i)){
                                                        cout << "No!!" << endl;
                                                        valid = 0;
                                                        break;
                                 }
                         if(valid==0)
                                     continue;
                         int cnt = 0;
                         while(n!="6174"&&n!="0"){
                                              n = simulate(n);
                                              cnt++;
                         }
                         cout << "Ok!! " << cnt << " times" << endl;
    }
}
