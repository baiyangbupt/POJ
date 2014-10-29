#include<iostream>
#include<iomanip>
#include<cmath>
#define pi acos(-1.0)
#define eps 1e-6

using namespace std;

int n, sidenum, angnum;
double s[3],a[3],inputs[3],inputa[3];
bool givens[3], givena[3];

bool chk(){
     double suma = 0;
     for(int i = 0; i < 3; i++)
             if(givena[i]){
                           if(a[i]<=0||a[i]>=pi)
                                                return 0;
                           suma+=a[i];
             }
     if(suma>pi)
                return 0;
     if(sidenum==3){
                    for(int i = 0; i < 3; i++)
                            if(s[(i+1)%3]+s[(i+2)%3]<=s[i]||s[(i+1)%3]-s[(i+2)%3]>=s[i]||s[(i+2)%3]-s[(i+1)%3]>=s[i])
                                                                                                                     return 0;
     }
     return 1;
}

int solve(){
     if(sidenum==3){
                    double ta[3];
                    for(int i = 0; i < 3; i++){
                            double t = s[(i+1)%3]*s[(i+1)%3]+s[(i+2)%3]*s[(i+2)%3]-s[i]*s[i];
                            ta[i] = acos(t/(2.*s[(i+1)%3]*s[(i+2)%3]));
                            if(givena[i]&&abs(ta[i]-a[i])>eps)
                                                              return -1;
                    }
                    for(int i = 0; i < 3; i++)
                            a[i] = ta[i];
                    return 1;
     }
     if(sidenum==2&&angnum<2){
                              if(givens[0]==0)
                                               swap(s[0],s[2]), swap(a[0],a[2]), swap(givena[0], givena[2]);
                              else if(givens[1]==0)
                                   swap(s[1],s[2]), swap(a[1],a[2]), swap(givena[1], givena[2]);
                              
                              if(givena[2]){
                                            s[2] = s[0]*s[0]+s[1]*s[1]-2*s[0]*s[1]*cos(a[2]);
                                            a[0] = asin(s[0]*sin(a[2])/s[2]);
                                            a[1] = asin(s[1]*sin(a[2])/s[2]);
                                            return 1;
                              }
                              if(givena[1])
                                           swap(s[0],s[1]), swap(a[0],a[1]);
                              double derta = (2*s[1]*cos(a[0]))*(2*s[1]*cos(a[0]))-4*(s[1]*s[1]-s[0]*s[0]);
                              if(derta<0)
                                           return 0;
                              if(derta>0&&s[1]>s[0])
                                                      return 2;
                              s[2] = s[1]*cos(a[0])+sqrt(derta)/2;
                              a[1] = asin(s[1]*sin(a[0])/s[0]);
                              a[2]  =asin(s[2]*sin(a[0])/s[0]);
                              return 1;
     }
     if(givena[0]==0)
                     swap(a[2],a[0]), swap(s[2],s[0]), swap(givens[2], givens[0]);
     if(givena[1]==0)
                     swap(a[2],a[1]), swap(s[2],s[1]), swap(givens[2], givens[1]);
                     
     a[2] = pi-a[0]-a[1];
     double ts[3], k;
     for(int i = 0; i < 3; i++)
             if(givens[i]){
                           ts[i] = s[i], k = s[i]/sin(a[i]);
                           break;
             }
     for(int i = 0; i < 3; i++){
             ts[i] = k*sin(a[i]);
             if(givens[i]&&abs(ts[i]-s[i])>eps)
                                    return 0;
             s[i] = ts[i];
     }
     return 1;
}
     
     

int main(){
    cin >> n;
    while(n--){
               sidenum = angnum = 0;
               memset(givens,0,sizeof(givens));
               memset(givena,0,sizeof(givena));
               for(int i = 0; i < 3; i++){
                       double t1, t2;
                       cin >> t1 >> t2;
                       s[i] = inputs[i] = t1, a[i] = inputa[i] = t2;
                       if(t1>0)
                               sidenum++, givens[i] = 1;
                       if(t2>0)
                               angnum++, givena[i] = 1;
               }
               if(chk()==0||sidenum+angnum<3||sidenum==0){
                                                          cout << "Invalid input." << endl;
                                                          continue;
               }
               
               int res = solve();
               if(res==2)
                         cout << "More than one solution." << endl;
               else if(res==0)
                    cout << "Invalid input." << endl;
               else{
                    for(int i = 0; i < 3; i++)
                            for(int j = i+1; j < 3; j++){
                                    if(abs(s[i]-inputs[j])<eps||abs(a[i]-inputa[j])<eps)
                                                                                        swap(s[i],s[j]), swap(a[i],a[j]);
                            }
                    cout <<setiosflags(ios::fixed) << setprecision(6) << s[0] << " " << a[0] <<' ' << s[1] << ' ' << a[1]\
                     << ' ' << s[2] << ' ' << a[2] << endl;
               }
    }
}
               
               
