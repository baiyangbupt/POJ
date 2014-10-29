#include<iostream>
#include<map>
#include<string>
using namespace std;

void reverse(string &s){
     int i = 0, j = s.size()-1;
     while(i<j){
                swap(s[i],s[j]);
                i++,j--;
     }
}

string getInv(string s){
       int h[10];
       string res;
       memset(h,0,sizeof(h));
       for(int i =0 ; i < s.size(); i++)
               h[s[i]-'0']++;
       
       for(int i = 0; i < 10; i++)
               if(h[i]){
                          int t = h[i];
                          string temp;
                          while(t){
                                   temp.push_back(t%10+'0');
                                   t/=10;
                          }
                          reverse(temp);
                          temp.push_back('0'+i);
                          res.append(temp);
               }
       return res;
}

int main(){
    string s;
    while(cin>>s){
                  if(s=="-1") break;
                  map<string, int> book;
                  book[s] = 0;
                  string origin = s, t = getInv(s);
                  int step = 0, interval;
                  while(step<16){
                              if(book.find(t)!=book.end()) {
                                                           interval = step-book[t];
                                                           break;
                              }
                              step++;
                              s = t;
                              book[t] = step;
                              t = getInv(s);
                  }
                  cout << origin;
                  if(step==0) cout << " is self-inventorying" << endl;
                  else if(step>14)
                       cout << " can not be classified after 15 iterations" << endl;
                  else if(interval==0)
                       cout << " is self-inventorying after " << step<<" steps" << endl;
                  else
                      cout << " enters an inventory loop of length " << interval+1 << endl;    
    }
}
