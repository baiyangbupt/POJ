#include<iostream>
using namespace std;

int weight[12];

int main(){
    int n;
    cin >> n;
    while(n--){
               for(int i = 0; i < 12; i++) weight[i] = 0;
               string a,b,c;
               for(int i = 0; i < 3; i++){
                   cin >> a >> b >> c;
                   if(c=="even"){
                                 for(int i = 0; i < a.size(); i++)
                                         weight[a[i]-'A'] = 1000;
                                 for(int i = 0; i < b.size(); i++)
                                         weight[b[i]-'A'] = 1000;
                   }
                   else if(c=="up"){
                        for(int i = 0; i < a.size(); i++)
                                         if(weight[a[i]-'A']!=1000)
                                                                weight[a[i]-'A']++;
                        for(int i = 0; i < b.size(); i++)
                                         if(weight[b[i]-'A']!=1000)
                                                                weight[b[i]-'A']--;
                   }
                   else if(c=="down"){
                        for(int i = 0; i < a.size(); i++)
                                         if(weight[a[i]-'A']!=1000)
                                                                weight[a[i]-'A']--;
                        for(int i = 0; i < b.size(); i++)
                                         if(weight[b[i]-'A']!=1000)
                                                                weight[b[i]-'A']++;
                   }
               }
               int m = 0, res;
               for(int i = 0; i < 12; i++)
                       if(weight[i]!=1000){
                           int t = weight[i]>0?weight[i]:-1*weight[i];
                           if(t>m) m = t, res = i;
                       }
               cout << char('A'+res) << " is the counterfeit coin and it is " << (weight[res]>0?"heavy":"light")<<"."<<endl;
    }
}
