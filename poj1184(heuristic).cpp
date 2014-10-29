#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int st, ed, to[7], sortto[7];
char dis[1000000][7];
int base[7] = {1,100000,10000,1000,100,10,1};

struct node{
       int val, x, g, h, f;
};

void geth(node &n){
     int from[7], to[7], val = n.val;
     for(int i = 1; i <= 6; i++){
             from[i] = val%10;
             val/=10;
     }
     int res = 0;
     for(int i = 1; i <= 6; i++)
             if(i!=n.x){
                        res += from[i]!=to[i];
             }
     
     sort(from+1,from+7);
     
     for(int i = 1; i <= 6; i++)
             res += max(from[i]-sortto[i], sortto[i]-from[i]);
     
     n.h = res;
     n.f = n.h+n.g;
}

bool operator <(const node &a, const node &b){
     if(a.f==b.f)
                 return a.g < b.g;
     return a.f > b.f;
}

int bfs(){
     priority_queue<node> q;
     node n;
     n.val = st, n.x = 1, n.g = dis[st][1] = 0;
     geth(n);
     
     q.push(n);
     while(!q.empty()){
                       node t = q.top();
                       q.pop();
                       int val = t.val, x = t.x, g = t.g, h = t.h;
                       //cout << val << " " << x << " " << g << " " << h << endl;
                       if(val==ed)
                                  return dis[val][x];
                       
                       if(x<6&&g+1<dis[val][x+1]){
                                                  n.val = val;
                                                  n.g = g+1;
                                                  dis[val][x+1] = g+1;
                                                  n.x = x+1;
                                                  geth(n);
                                                  q.push(n);
                       }
                       
                       int cur = val/base[x]%10;
                       if(cur<9&&g+1<dis[val+base[x]][x]){
                                                          n.val = val+base[x];
                                                          n.g = g+1;
                                                          dis[val+base[x]][x] = g+1;
                                                          n.x = x;
                                                          geth(n);
                                                          q.push(n);
                       }
                       
                       if(cur>0&&g+1<dis[val-base[x]][x]){
                                                          n.val = val-base[x];
                                                          n.g = g+1;
                                                          dis[val-base[x]][x] = g+1;
                                                          n.x = x;
                                                          geth(n);
                                                          q.push(n);
                       }
                       
                       int s1 = val/base[1], s6 = val%10;
                       if(x>1&&s1!=cur&&g+1<dis[val+(s1-cur)*base[x]+(cur-s1)*base[1]][x]){
                                                                                       n.val = val+(s1-cur)*base[x]+(cur-s1)*base[1];
                                                                                       n.g = g+1;
                                                                                       dis[n.val][x] = g+1;
                                                                                       n.x = x;
                                                                                       geth(n);
                                                                                       q.push(n);
                       }
                       if(x<6&&s6!=cur&&g+1<dis[val+(s6-cur)*base[x]+(cur-s6)*base[6]][x]){
                                                                                       n.val = val+(s6-cur)*base[x]+(cur-s6)*base[6];
                                                                                       n.g = g+1;
                                                                                       dis[n.val][x] = g+1;
                                                                                       n.x = x;
                                                                                       geth(n);
                                                                                       q.push(n);
                       }
     }
}

int main(){
    while(cin>>st>>ed){
                       int val = ed;
                       for(int i = 1; i <= 6; i++){
                               to[i] = val%10;
                               val/=10;
                               sortto[i] = to[i];
                       }
                       sort(sortto+1, sortto+7);
                       memset(dis,-1,sizeof(dis));
                       int res = bfs();
                       cout << res << endl;
    }
}
