#include<iostream>
#include<string>
#include<queue>
#include<stack>
using namespace std;

int a[9],m[10][9],st;
int pre[1<<19];

void init(){
      string s[9] = {"ABDE","ABC","BCEF","ADG","BDEFH","CFI","DEGH","GHI","EFHI"};    
      for(int i = 1; i <= 9; i++){
              for(int j = 0; j < 9; j++)  m[i][j] = 0;
              for(int j = 0; j < s[i-1].size(); j++){
                      m[i][s[i-1][j]-'A'] = 1;
              }
      }
}

void bfs(){
     memset(pre,-1,sizeof(pre));
     queue<int> q;
     q.push(st);
     while(!q.empty()){
                       
                       int t = q.front();
                       //cout << t << endl;
                       q.pop();
                       if(t==0) break;
                       
                       if(t==st) pre[t] = 0;
                       for(int i = 1; i <= 9; i++){
                               int temp = t;
                               for(int j = 0; j < 9; j++)
                                       if(m[i][j]){
                                                   if(temp&(1<<(2*j)))
                                                                      temp ^= (1<<(2*j))+(1<<(2*j+1));
                                                                       
                                                   else
                                                        temp+=(1<<(2*j));
                                       }
                               if(pre[temp]<0){
                                               pre[temp] = i;
                                               q.push(temp);
                               }
                       }
     }
}

void print(int p){
      int t = pre[p], curp = p;
     
      if(t==-1) return;
      for(int j = 0; j < 9; j++)
              if(m[t][j]){
                          if(p&(1<<(2*j)))
                                          p -= (1<<(2*j));
                          else
                              p ^= (1<<(2*j))+(1<<(2*j+1));
              }
      if(p==st){
               cout << t << " ";
               return;
      }
      else if(curp==0){
           print(p);
           cout << t << endl;
      }
      else{
           print(p);
           cout << t << " ";
      }
}

int main(){
    init();
    st = 0;
    int x,bit;
    for(int i = 0; i < 9; i++){
            bit = 2*i;
            cin >> x;
            st += x*(1<<bit);
            //cout << x*(1<<bit) << endl;
    }
    bfs();
    print(0);
    //cout << st << endl;
    system("pause");
}
             
