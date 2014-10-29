#include<iostream>
#include<string>
using namespace std;

int s, n, mp[8], st, table[1<<16], num[1<<16];
int base[17];

void init(){
     base[0] = 1;
     for(int i = 1; i < 17; i++)
             base[i] = base[i-1]<<1;
}

int trans(int p){
    int res = 0;
    for(int i = n-1; i >= 0; i--){
            int p1 = (i+2)%n, p2 = i, p3 = (i+n-1)%n;
            int t = 0;
            t += (p&base[p1])>0; t<<=1; t+=(p&base[p2])>0; t<<=1; t+=(p&base[p3])>0;
            int add = mp[t];
            res<<=1;
            res += add;
            
    }
    return res;
}

string decode(int a){
       string res;
       for(int i = n-1; i >= 0; i--)
               if(a&base[i])
                            res.push_back('b');
               else
                   res.push_back('a');
       string p = res;
       for(int i = 0; i < res.size()-1; i++){
               string t1 = res.substr(0,i+1), t2 = res.substr(i+1);
               t2.append(t1);
               p = min(p,t2);
       }
       return p;
}

int main(){
    init();
     while(cin>>n){
                   string str;
                   cin >> str;
                   st = 0;
                   for(int i = 0; i < str.size(); i++)
                        st<<=1, st += str[i]=='b';
                   //cout << st << endl;
                   for(int i = 0; i < 8; i++){
                           cin >> str;
                           mp[i] = str[3]=='b';
                   }     
                   cin >> s;
                   int cnt = 0;
                   memset(table,-1,sizeof(table));
                   int p = st;
                   bool done = 0;
                   while(table[p]<0){
                                     if(cnt==s){
                                                done = 1;
                                                cout << decode(p) << endl;
                                                break;
                                     }
                                     num[cnt] = p;
                                     table[p] = cnt++;
                                     p = trans(p);
                   }
                   if(done)
                           continue;
                   int mid = table[p];
                   int period = cnt-mid;
                   if(s<=mid)
                             cout << decode(num[s]) << endl;
                   else{
                        cout << decode(num[(s-mid)%period+mid]) << endl;
                   }
     }
     }
