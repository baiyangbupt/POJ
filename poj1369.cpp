#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int op[10000][2];
char c[10000];

int atoi(string s){
    stringstream ss;
    ss<<s;
    int res;
    ss>>res;
    return res;
}

int main(){
    string s;
    int cnt = 0;
    while(cin >> op[cnt][0]){
            if(op[cnt][0]==0)
                             cin >> c[cnt++];
            cin.get();
            while(getline(cin,s)&&s!=""){
                                          if(s[0]=='0'){
                                                        op[cnt][0] = 0, c[cnt++] = s[2];
                                                        continue;
                                          }
                                          string temp;
                                          for(int i = 0; i < s.size(); i++){
                                                  if(s[i]==' '&&temp.size()>0)
                                                             op[cnt][0] = atoi(temp), temp.clear();
                                                  else
                                                      temp.push_back(s[i]);
                                          }
                                          op[cnt++][1] = atoi(temp);
            }
            string w;
            for(int i = 0; i < cnt; i++)
                    if(op[i][0]==0)
                                    w.push_back(c[i]);
                    else
                        w.append(w.substr(w.size()-op[i][0],op[i][1]));
            //cout << w << endl;
            int res = 0;
            string u;
            for(int i = 0; i <cnt-1; i++){
                    if(op[i][0]==0)
                                   u.push_back(c[i]);
                    else
                        u.append(u.substr(u.size()-op[i][0],op[i][1]));
                    
                    string v;
                    bool valid = 1;
                    for(int j = i+1; j < cnt; j++)
                            if(op[j][0]==0)
                                           v.push_back(c[j]);
                            else if(op[j][0]>v.size()){
                                 valid = 0;
                                 break;
                            }
                            else
                                v.append(v.substr(v.size()-op[i][0],op[i][1]));
                    if(valid==0)
                                continue;
                    if(w==u.append(v))
                                      res++;
                    //cout << u << ' ' << v << endl;
            }
            cout << res << endl;
            cnt = 0;
    }
}
                                          
                                          
