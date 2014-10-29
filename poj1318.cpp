#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string dic[100], sortdic[100];

int main(){
    string s;
    int cnt = 0;
    while(cin>>s&&s!="XXXXXX"){
                               dic[cnt] = s;
                               sort(s.begin(),s.end());
                               sortdic[cnt] = s;
                               cnt++;
    }
    while(cin>>s&&s!="XXXXXX"){
                               string res[100];
                               int valid = 0;
                               sort(s.begin(),s.end());
                               for(int i = 0; i < cnt; i++)
                                       if(s==sortdic[i]){
                                                         res[valid++] = dic[i];
                                       }
                               if(valid==0){
                                            cout << "NOT A VALID WORD" << endl;
                               }
                               else{
                                    sort(res,res+valid);
                                    for(int i = 0; i< valid; i++)
                                            cout << res[i] << endl;
                               }
                               cout << "******" << endl;
    }
    system("pause");
}
