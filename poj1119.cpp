#include<iostream>
#include<string>
#include<map>
#include<cmath>
#include<iomanip>

using namespace std;

string doc;
map<string, int> gtf,ltf;

string convert(string s){
      string res;
      for(int i = 0; i < s.size(); i++)
              if(s[i]<='Z'&&s[i]>='A') res.push_back(s[i]+'a'-'A');
              else if(s[i]<='z'&&s[i]>='a') res.push_back(s[i]);
              else if(s[i]>='0'&&s[i]<='9') res.push_back(s[i]);
      return res;
}

void init(string &s, map<string, int> &tf){
       string temp;
       for(int i = 0; i < s.size(); i++)
               if(s[i]!=' ') temp.push_back(s[i]);
               else if(temp.size()>0){
                    string t = convert(temp);
                    if(t.size()>0){
                                    if(tf.find(t)==tf.end()) tf[t] = 1;
                                    else tf[t]++;
                    }
                    temp.clear();
               }
       if(temp.size()>0){
                         string t = convert(temp);
                         if(t.size()>0){
                                         if(tf.find(t)==tf.end())
                                                                    tf[t] = 1;
                                         else
                                             tf[t]++;
                         }
       }
}

int main(){
    string s,input;
    while(getline(cin,s)&&s.compare("----------")!=0){
                                         cout << s.compare("----------") << endl;
                                         input.append(s);
    }
    init(input,gtf);
    input.clear();

    while(getline(cin,s)){
                                           if(s=="----------"){
                                                               init(input,ltf);
                                                               if(!ltf.empty()){
                                                                       double sum = 0.;
                                                                       for(map<string, int>::iterator it = ltf.begin(); it!=ltf.end(); it++){
                                                                                       if(gtf.find(it->first)==gtf.end()) continue;
                                                                                       sum += sqrt(gtf[it->first]*it->second*1.0);
                                                                       } 
                                                                       cout << setiosflags(ios::fixed) << setprecision(2) << sum << endl;
                                                               }
                                                               input.clear();
                                                               ltf.clear();
                                                               continue;
                                           }
                                           input.append(s);
    }
}
                                           
                                           
