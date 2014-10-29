#include<iostream>
#include<string>
using namespace std;

int n;
int mutate(string &s, int p){
    if(p>=n)
           return 0;
    if(s[p]<='Z'&&s[p]>='A'){
                             int mut = mutate(s,p+1);
                             s[p] = mut%10+'0';
                             return mut+1;
    }
    else if(s[p]>='1'&&s[p]<='9'){
         int t = s[p]-'0';
         s[p]--;
         if(p+t>=n){
                      int mut = mutate(s,p+1);
                      return mut+1;
         }
         else{
              int mut = mutate(s,p+t);
              return mut+1;
         }
    }
    else
        return 0;
}

int main(){
    string s;
    while(cin>>s&&s!="ENDOFINPUT"){
                                   cin >> n;
                                   cin >> s;
                                   mutate(s,0);
                                   cout << s << endl;
                                   cin >> s;
    }
}

       
 
