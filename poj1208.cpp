#include<iostream>
#include<stack>
#include<string>
using namespace std;

struct bucket{
       stack<int> s;
}bb[30];

int N,block[30];

void reset(int bkt, int target){
     while(bb[bkt].s.top()!=target){
                                    int t = bb[bkt].s.top();
                                    bb[bkt].s.pop();
                                    bb[t].s.push(t);
                                    block[t] = t;
     }
}
void pilemove(int from, int to, int target){
     stack<int> temp;
     while(bb[from].s.top()!=target){
                                     int t = bb[from].s.top();
                                     bb[from].s.pop();
                                     temp.push(t);
     }
     bb[from].s.pop();
     temp.push(target);
     while(!temp.empty()){
                          int t = temp.top();
                          temp.pop();
                          bb[to].s.push(t);
                          block[t] = to;
     }
}

int main(){
    while(cin>>N){
                  for(int i = 0; i < N; i++)
                          bb[i].s.push(i);
                  for(int i = 0; i < N; i++)
                          block[i] = i;
                  string s;
                  int x,y;
                  while(cin>>s&&s!="quit"){
                                           if(s=="move"){
                                                         cin >> x;
                                                         cin >> s;
                                                         if(s=="onto"){
                                                                       cin >> y;
                                                                       int from = block[x], to = block[y];
                                                                       reset(from,x), reset(to,y);
                                                                       bb[from].s.pop();
                                                                       bb[to].s.push(x);
                                                                       block[x] = to;
                                                         }
                                                         else{
                                                              cin >> y;
                                                              int from = block[x],to = block[y];
                                                              reset(from,x);
                                                              bb[from].s.pop();
                                                              bb[to].s.push(x);
                                                              block[x] = to;
                                                         }
                                           }
                                           else{
                                                cin >> x;
                                                cin >> s;
                                                if(s=="onto"){
                                                              cin >> y;
                                                              int from = block[x], to = block[y];
                                                              reset(to,y);
                                                              pilemove(from,to,x);
                                                }
                                                else{
                                                     cin >> y;
                                                     int from = block[x], to = block[y];
                                                     pilemove(from,to,x);
                                                }
                                           }
                  }
                  for(int i = 0; i < N; i++){
                          cout << i << ":";
                          stack<int> temp;
                          while(!bb[i].s.empty()){
                                                  int t = bb[i].s.top();
                                                  bb[i].s.pop();
                                                  temp.push(t);
                          }
                          while(!temp.empty()){
                                               int t =temp.top();
                                               cout << " " << t;
                                               temp.pop();
                          }
                          cout << endl;
                  }
    }
}
                                                                       
                                                         
