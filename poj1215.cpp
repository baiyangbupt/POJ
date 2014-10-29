#include<iostream>
#include<string>
#include<sstream>
#include<cstdio>
using namespace std;

double rate[5][3] = {{0.10,0.06,0.02},{0.25,0.15,0.05},{0.53,0.33,0.13},{0.87,0.47,0.17},{1.44,0.80,0.30}};
int atoi(string s){
    stringstream ss;
    ss << s;
    int res;
    ss >> res;
    return res;
}


int main(){
    string s;
    char number[100];                                                                                     
    char c;
    while(cin>>c&&c!='#'){
                          int type = c-'A', sth,stm,edh,edm;
                          int t1=0, t2=0, t3=0;
                          cin >> number;
                          cin >> s;
                          sth = atoi(s);
                          cin >> s;
                          stm = atoi(s);
                          cin >> s;
                          edh = atoi(s);
                          cin >> s;
                          edm = atoi(s);
                          if(sth>edh||sth==edh&&stm>edm){
                                                         if(sth<18){
                                                                    t1+=min(10*60,((17-sth)*60+60-stm));
                                                                    t2+=4*60;
                                                                    t3+=2*60;
                                                         }
                                                         else if(sth<22){
                                                              t2+=((21-sth)*60+60-stm);
                                                              t3+=2*60;
                                                         }
                                                         else
                                                             t3+=((23-sth)*60+60-stm);
                                                         
                                                         t3+=min(8*60,edh*60+edm);
                                                         if(edh>=8) 
                                                                    t1+=min(10*60,(edh-8)*60+edm);
                                                         if(edh>=18)
                                                                    t2+=min((edh-18)*60+edm,4*60);
                                                         if(edh>=22)
                                                                    t3+=min((edh-22)*60+edm,2*60);
                          }
                          else{
                               if(edh>=18){
                                           if(sth<18)
                                                     t1+=((17-sth)*60+60-stm);
                                           if(edh>=22){
                                                       if(sth<22)
                                                                 t2+=min(((21-sth)*60+60-stm),4*60);
                                                       t3+=min((edh-22)*60+edm,(edh-sth)*60+edm-stm);
                                           }
                                           else
                                               t2+=min((edh-18)*60+edm,(edh-sth)*60+edm-stm);
                               }
                               else
                                   t1+=(edh*60-sth*60+edm-stm);
                          }
                          double p = t1*rate[type][0]+t2*rate[type][1]+t3*rate[type][2];
                          printf("%10s%6d%6d%6d%3c%8.2lf\n",number,t1,t2,t3,c,p);
                          //cout << "  " << number<<"     "<<t1<<"     " << t2<<"     "<<t3<<"  " << c<<"    " << p << endl;                 
    }
    
}
