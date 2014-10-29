#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

struct team{
       string name;
       int score[7], total, avg, solved;
       team(string s, int a, int b, int c, int d, int e, int f, int g){
                   name = s;
                   total = 0;
                   solved = 0;
                   total+=(score[0] = a);
                   total+=(score[1] = b);
                   total+=(score[2] = c);
                   total+=(score[3] = d);
                   total+=(score[4] = e);
                   total+=(score[5] = f);
                   total+=(score[6] = g);
                   double t = 0.;
                   for(int i = 0; i < 7; i++)
                           if(score[i]!=0){
                                           solved++;
                                           t+=log(score[i]*1.0);
                           }
                   t/=solved;
                   if(t>0) avg = exp(t)+0.5;
                   else avg = 0;
       }
       bool tiewith(const team &b){
            return solved==b.solved&&total==b.total&&avg==b.avg;
       }
};

bool operator<(const team &a, const team &b){
     if(a.solved==b.solved){
                            if(a.total==b.total){
                                                 if(a.avg==b.avg)
                                                                 return a.name<b.name;
                                                 return a.avg<b.avg;
                            }
                            return a.total<b.total;
     }
     return a.solved>b.solved;
}


int n;
int main(){
    int nc = 1;
    while(cin>>n&&n){
                     vector<team> v;
                     string s;
                     int a,b,c,d,e,f,g;
                     for(int i = 0; i < n; i++){
                             cin >> s >> a >> b >> c >> d >> e >> f>>g;
                             v.push_back(team(s,a,b,c,d,e,f,g));
                     }
                     sort(v.begin(),v.end());
                     cout << "CONTEST " << nc << endl;
                     int p = 1;
                     cout << p <<" " << v[0].name << " " << v[0].solved << " " <<v[0].total << " "<< v[0].avg ;
                     for(int i = 0; i < 7; i++)
                             cout << " " << v[0].score[i];
                     cout << endl;
                     
                     for(int i = 1; i < v.size(); i++){
                             if(v[i].tiewith(v[i-1])==0) p = i+1;
                             cout << p <<" " << v[i].name << " " << v[i].solved << " " << v[i].total << " " << v[i].avg ;
                             for(int j = 0; j < 7; j++)
                                     cout << " " << v[i].score[j];
                             cout << endl;
                     }
                     
                     nc++;
    }
}
