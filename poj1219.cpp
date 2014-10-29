#include<iostream>
#include<string>
using namespace std;

int exist[26],here[26];

bool invalid(string s){
     if(s.size()!=5) return 1;
     for(int i = 0; i < 5; i++)
             if(s[i]<'A'||s[i]>'Z')
                                   return 1;
     return 0;
}

string lower(string s){
       string res;
       for(int i = 0;  i < 5; i++)
               res.push_back(s[i]+'a'-'A');
       
       return res;
}

int main(){
    string origin,guessed,previous;
    int ii = 0;
    while(cin>>origin&&origin!="LINGO"){
                                        if(ii!=0) cout << endl;
                                        ii++;
                                        memset(exist,0,sizeof(exist));
                                        for(int i = 0; i < 5; i++)
                                                exist[origin[i]-'A']++;
                                                
                                        previous = origin;
                                        for(int i = 1; i < 5; i++)
                                                previous[i] = '.';
                                        cout << previous << endl;
                                        int t = 0;
                                        cin.get();
                                        bool reachend = 0;
                                        while(getline(cin,guessed)&&guessed!=""){
                                                                                 if(t==5&&guessed!=origin){
                                                                                                           cout << lower(origin)<<endl;
                                                                                                           reachend = 1;
                                                                                                           break;
                                                                                 }
                                                                                 
                                                                                 if(guessed==origin){
                                                                                                     cout << origin << endl;
                                                                                                     reachend = 1;
                                                                                                     break;
                                                                                 }
                                                                                 
                                                                                 
                                                                                 if(invalid(guessed)){
                                                                                                      cout << previous << endl;
                                                                                                      t++;
                                                                                                      continue;
                                                                                 }
                                                                                 
                                                                                 memset(here,0,sizeof(here));
                                                                                 string temp(5,'a');
                                                                                 for(int i = 0; i < 5; i++)
                                                                                         if(guessed[i]==origin[i])
                                                                                                                  temp[i] = guessed[i], here[temp[i]-'A']++;
                                                                                 
                                                                                 for(int i = 0; i < 5; i++)
                                                                                         if(temp[i]=='a'){
                                                                                                          if(here[guessed[i]-'A']>=exist[guessed[i]-'A'])
                                                                                                                                                   temp[i] = '.';
                                                                                                          else 
                                                                                                               here[guessed[i]-'A']++, temp[i] = guessed[i]+'a'-'A';
                                                                                         }
                                                                                 
                                                                                 t++;
                                                                                 cout << temp << endl;
                                                                                 previous = temp;
                                        }
                                        while(guessed!="") getline(cin,guessed);
                                        if(reachend==0) cout << lower(origin) << endl;
    }
}
