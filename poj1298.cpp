#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    while(cin>>s&&s!="ENDOFINPUT"){
                                   cin.get();
                                   getline(cin,s);
                                   string res = s;
                                   for(int i = 0; i < s.size(); i++)
                                           if(res[i]>='A'&&res[i]<='Z')
                                                                       res[i] = (res[i]-'A'+26-5)%26+'A';
                                   
                                   cout << res << endl;
                                   cin >> s;
    }
}
