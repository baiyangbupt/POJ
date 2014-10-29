#include<iostream>
#include<string>
#include<queue>
using namespace std;

int base[10] = {100000000,10000000,1000000,100000,10000,1000,100,10,1};
string res;
const int HASHSIZE = 1e6+3;
const int MAXSIZE = 1e6;
int hashtable[HASHSIZE],cur,init,initp;
struct hashnode{
       int v, nxt;
}nn[MAXSIZE];
       
bool insert(int p){
     int num = p%HASHSIZE;
     int target = hashtable[num];
     if(target==-1){
                    nn[cur].v = p;
                    nn[cur].nxt = -1;
                    hashtable[num] = cur++;
                    return 1;
     }
     
     while(target!=-1){
                       if(nn[target].v==p)
                                          return 0;
                       target = nn[target].nxt;
     }
     nn[cur].v = p;
     nn[cur].nxt = hashtable[num];
     hashtable[num] = cur;
     cur++;
     return 1;
}
     

struct node{
       int value,p,pre;
       char c;
}q[MAXSIZE];
       
void shift(int type, int &value, int &p){
     int tochange;
     if(type==1)
                tochange = p-3;
     else if(type==2)
          tochange = p+3;
     else if(type==3)
          tochange = p-1;
     else
         tochange = p+1;
     
     int inposition = value/base[tochange]%10;
     value-=inposition*base[tochange];
     value+=inposition*base[p];
     p = tochange;
}

void print(int p){
     if(q[p].pre==-1){
                      //cout << q[p].c ;
                      return;
     }
     
     print(q[p].pre);
     cout << q[p].c;
     return ;
}

void bfs(){
     int front=0,tail=0;
     memset(hashtable,-1,sizeof(hashtable));
     q[0].value = init, q[0].p = initp, q[0].pre = -1;
     tail++;
     while(tail>front){
                       int value = q[front].value, p = q[front].p;
                       if(value==123456780){
                                            print(front);
                                            cout << endl;
                                            return;
                       }
                       
                       if(p/3>0){
                                 int tv = value,tp = p;
                                 shift(1,tv,tp);
                                 if(insert(tv)){
                                                q[tail].value = tv, q[tail].p = tp, q[tail].pre = front, q[tail].c = 'u';
                                                tail++;
                                 }
                       }
                       if(p/3<2){
                                 int tv = value, tp = p;
                                 shift(2,tv,tp);
                                 if(insert(tv)){
                                                q[tail].value = tv, q[tail].p = tp, q[tail].pre = front, q[tail].c = 'd';
                                                tail++;
                                 }
                       }
                       if(p%3>0){
                                 int tv = value, tp = p;
                                 shift(3,tv,tp);
                                 if(insert(tv)){
                                               q[tail].value = tv, q[tail].p = tp, q[tail].pre = front, q[tail].c = 'l';
                                               tail++;
                                 }
                       }
                       if(p%3<2){
                                 int tv = value, tp = p;
                                 shift(4,tv,tp);
                                 if(insert(tv)){
                                                q[tail].value = tv, q[tail].p = tp, q[tail].pre = front, q[tail].c = 'r';
                                                tail++;
                                 }
                       }
                       front++;
     }
     cout << "unsolvable" << endl;
}
     

int main(){
    char c;
    for(int i = 0; i < 9; i++){
            cin >> c;
            if(c=='x')
                      initp = i, init*=10;
            else
                init*=10, init+=c-'0';
    }
    
    bfs();
    system("pause");
}
     
