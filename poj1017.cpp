#include<iostream>
using namespace std;

int main(){
    int a[7], res;
    while(1){
             res = 0;
             for(int i = 1; i  < 7; i++) cin >> a[i];
             if(a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0&&a[6]==0) break;
             res+=a[6]+a[5]+a[4];
             a[1]-=a[5]*11;
             a[1]=a[1]>0?a[1]:0;
             if(a[4]*5>=a[2]){
                             a[1]-=4*(5*a[4]-a[2]);
                             a[1] = a[1]>0?a[1]:0;
                             a[2] = 0;
             }
             else
                 a[2]-=a[4]*5;
             
             res+=a[3]/4;
             if(a[3]%4){
                        res+=1;
                        int t = a[3]%4;
                        if(a[2]<=7-2*t){
                                        a[1] -= 36-9*t-a[2]*4;
                                        a[1] = a[1]>0?a[1]:0;
                                        a[2] = 0;
                        }  
                        else{
                             a[1] -= 36-9*t-4*(7-2*t);
                             a[1] = a[1]>0?a[1]:0;
                             a[2] -= 7-2*t;
                        }
             }
             
             res+=a[2]/9;
             if(a[2]%9){
                        res+=1;
                        int t =a[2]%9;
                        a[1]-= 36 - 4*t;
                        a[1] = a[1]>0?a[1]:0;
             }
             res+=a[1]/36;
             if(a[1]%36) res+=1;
             cout << res << endl;
    }
}
