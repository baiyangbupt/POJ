#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct node{
       int x,y;
};

bool multi(node a, node b, node c){
     return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x)>0;
}

bool operator<(const node &a, const node &b){
     if(a.y==b.y)
                 return a.x<b.x;
     return a.y<b.y;
}

bool ononeline(node &a, node &b, node &c){
     return (b.x-a.x)*(c.y-a.y)==(b.y-a.y)*(c.x-a.x);
}

vector<node> nn,pp;
bool graham(int n){
     int i,len,k=0,top=1;
     pp = nn;
     sort(nn.begin(),nn.end());
     if(n==0) return 0;
     pp[0] = nn[0];
     if(n==1) return 0;
     pp[1] = nn[1];
     if(n==2) return 0;
     for(i = 2; i < n; i++){
           while(top&&multi(nn[i],pp[top],pp[top-1]))
                                                     top--;
           pp[++top] = nn[i];
     }
     len = top; pp[++top] = nn[n-2];
     for(i = n-3; i>=0; i--){
           while(top!=len&&multi(nn[i],pp[top],pp[top-1]))
                                                          top--;
           pp[++top] = nn[i];
     }
     /*cout << endl;
     for(int i = 0; i <= top; i++)
             cout << pp[i].x << " " << pp[i].y << endl;
     */
     node a = pp[0], b = pp[1];
     int onelinepoint = 2;
     for(int i = 2; i < n+1; i++){
             if(ononeline(a,b,pp[i]))
                                     onelinepoint++;
             else{
                  if(onelinepoint<3)
                                    return 0;
                  onelinepoint = 2;
             }
             a = b, b = pp[i];
     }
     if(onelinepoint==n+1||onelinepoint<3) return 0;
     return 1;
}


int main(){
    int t,n;
    cin >> t;
    while(t--){
               nn.clear();
               cin >> n;
               for(int i = 0; i < n; i++){
                       node tnode;
                       cin >> tnode.x >> tnode.y;
                       nn.push_back(tnode);
               }
               if(graham(n))
                            cout << "YES" << endl;
               else
                   cout << "NO" << endl;
    }
}
     
     
