#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int n,m,timetable[25][15],route[25],sum[25],start;

int atoi(string s){
    int res;
    stringstream ss;
    ss<<s;
    ss>>res;
    return res;
}

int main(){
    string s;
    while(getline(cin,s)&&s!="ENDOFINPUT"){
                                           string temp;
                                   for(int i = 0; i < s.size(); i++)
                                           if(s[i]<='9'&&s[i]>='0')
                                                                   temp.push_back(s[i]);
                                   n = atoi(temp);
                                   memset(route,0,sizeof(route));
                                   memset(sum,0,sizeof(sum));
                                   for(int i = 0; i < n; i++){
                                           getline(cin,s);
                                           string temp;
                                           for(int j = 0; j < s.size(); j++)
                                                   if(s[j]==' '&&temp.size()>0)
                                                              timetable[i][route[i]++] = atoi(temp), temp.clear();
                                                   else if(s[j]!=' ')
                                                        temp.push_back(s[j]);
                                           if(temp.size()>0)
                                                            timetable[i][route[i]++] = atoi(temp);
                                           for(int j = 0; j < route[i]; j++)
                                                   sum[i]+=timetable[i][j];
                                   }
                                   getline(cin,s);
                                   temp.clear();
                                   for(int i = 0; i < s.size(); i++)
                                           if(s[i]<='9'&&s[i]>='0')
                                                                   temp.push_back(s[i]);
                                   start = atoi(temp);
                                   int res = 100000000;
                                   for(int i = 0; i < n; i++){
                                           int rest = start;
                                           rest = rest%sum[i];
                                           int j = 0;
                                           while(rest>timetable[i][j]){
                                                                       rest-=timetable[i][j];
                                                                       j++;
                                           }
                                           if(rest==0){
                                                       res = 0;
                                                       break;
                                           }
                                           else
                                                res = min(res,timetable[i][j]-rest);
                                   }
                                   cout << res << endl;
                                   getline(cin,s);
    }
}
    
