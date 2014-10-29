#include<iostream>
using namespace std;

long double dis[6];
int n,g[6],y[6],r[6],p[6];

bool canbe[61];

bool test(int sped){
     for(int i = 0; i < n; i++){
             long double t = dis[i]*1.0*3600/sped;
             int times = (int)(t)/p[i];
             if(t-times*p[i]>g[i]+y[i])
                                       return 0;
     }
     return 1;
}
             

int main(){
    int nc = 1;
    while(cin>>n&&n!=-1){
                         memset(canbe,0,sizeof(canbe));
                         for(int i = 0; i < n; i++){
                                 cin >> dis[i] >> g[i] >> y[i] >> r[i];
                                 p[i] = g[i]+y[i]+r[i];
                         }
                         
                         for(int sped = 30; sped <= 60; sped++)
                                 if(test(sped))
                                               canbe[sped] = 1;
                         cout << "Case " << nc++ << ": ";
                         bool init = 1,in = 0;
                         int st,ed,valid=0;
                         for(int i = 30; i <= 60; i++)
                                 if(canbe[i]){
                                              valid++;
                                              if(in==0)
                                                       st = i, in = 1;
                                 }
                                 else{
                                      if(in==1){
                                                ed = i-1, in = 0;
                                                if(init==0) cout << ", ";
                                                init = 0;
                                                if(ed-st>0)
                                                           cout << st << "-" << ed;
                                                else
                                                    cout << st;
                                      }
                                 }
                         if(in){
                                valid++;
                                ed = 60;
                                if(init==0) cout << ", ";
                                if(ed-st>0)
                                           cout <<st << "-" << ed;
                                else cout<< st;
                         }
                         if(valid==0)
                                     cout <<"No acceptable speeds.";
                         cout << endl;
    }
}
