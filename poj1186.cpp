#include<iostream>
using namespace std;

const int MAX = 1000000;

struct hash{
       int num, count;
       hash *next;
       hash(){
              count = 0;
              next = NULL;
       }
}hh[MAX+10];

int k[7],pp[7],n,cnt,m;

int pow(int a, int b){
    int res = 1;
    for(int i = 0; i < b; i++)
            res *= a;
    return res;
}

void leftdfs(int p, int sum){
     if(p==n/2){
                int curnum = sum%MAX+1;
                while(curnum<0) curnum+=MAX;
                
                if(hh[curnum].count>0){
                                       hash *node = &hh[curnum];
                                       while(node->next!=NULL){
                                                         if(node->num==sum)
                                                                            break;
                                                         node = node->next;
                                       }
                                       if(node->num==sum) node->count++;
                                       else{
                                            hash *newnode = new hash;
                                            newnode->num = sum;
                                            newnode->count = 1;
                                            node->next = newnode;
                                       }
                }
                else{
                     hh[curnum].num = sum;
                     hh[curnum].count = 1;
                }
                
                return;
     }
     for(int i = 1; i<=m; i++)
             leftdfs(p+1,sum+k[p]*pow(i,pp[p]));
}

void rightdfs(int p, int sum){
     if(p==n){
              int cursum = (-1*sum)%MAX+1;
              while(cursum<0)
                             cursum+=MAX;
              
              if(hh[cursum].count==0) return;
              
              hash *node = &hh[cursum];
              while(node->next!=NULL){
                                      if(node->num==-1*sum)
                                                           break;
                                      node = node->next;
              }
              
              if(node->num==-1*sum)
                                   cnt+=node->count;
              return;
     }
     
     for(int i = 1; i <= m; i++)
             rightdfs(p+1,sum+k[p]*pow(i,pp[p]));
}
              


int main(){
    while(cin>>n){
                  cin >> m;
                  for(int i = 0; i < n; i++)
                          cin >> k[i] >> pp[i];
                  leftdfs(0,0);
                  rightdfs(n/2,0);
                  cout << cnt << endl;
    }
}
