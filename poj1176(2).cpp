#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int last[101],n,c;
bool f[101],g[101];

void turn1(){
     for(int i = 1; i <= n; i++)
             f[i] = !f[i];
}

void turn2(){
     for(int i = 1; i <= n; i+=2)
             f[i] = !f[i];
}

void turn3(){
     for(int i = 2; i <= n; i+=2)
             f[i] = !f[i];
}

void turn4(){
     for(int i = 1; i <= n; i+=3)
             f[i] = !f[i];
}

bool judge(){
     for(int i = 1; i<=n; i++)
             if(last[i]!=-1&&last[i]!=f[i])
                                           return 0;
     return 1;
}

int main(){
    while(cin>>n>>c){
                     int x;
                     vector<string> res;
                     memset(last,-1,sizeof(last));
                     while(cin>>x&&x!=-1)
                                         last[x] = 1;
                     while(cin>>x&&x!=-1)
                                         last[x] = 0;
                     for(int i1 = 0; i1<=1; i1++)
                             for(int i2 = 0; i2<=1; i2++)
                                     for(int i3 = 0; i3<=1;i3++)
                                             for(int i4 = 0; i4<=1; i4++)
                                                     if(c>=i1+i2+i3+i4&&(c-(i1+i2+i3+i4))%2==0){
                                                                                              for(int i = 1; i <= n; i++)
                                                                                                      f[i] = 1;
                                                                                              if(i1) turn1();
                                                                                              if(i2) turn2();
                                                                                              if(i3) turn3();
                                                                                              if(i4) turn4();
                                                                                              if(judge()){
                                                                                                          string s;
                                                                                                          for(int i = 1; i <= n; i++)
                                                                                                                  s+='0'+f[i];
                                                                                                          res.push_back(s);
                                                                                              }
                                                     }
                     sort(res.begin(), res.end());
                     for(int i = 0; i < res.size(); i++)    
                             cout << res[i] << endl;
    }
}
