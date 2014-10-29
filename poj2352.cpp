#include<iostream>
using namespace std;

const int MAX = 32001;
int c[MAX], num[15001], mx, n,x[15001];

int lowbit(int x){
    return x&(-x);
}

void update(int x, int inc){
     while(x<=mx+1)
                c[x] += inc, x+=lowbit(x);
}

int get(int p){
    int res = 0;
    while(p>=1)
                res += c[p], p-=lowbit(p);
    return res;
}

int main(){
    scanf("%d", &n);
                  memset(num,0,sizeof(num));
                  memset(c,0,sizeof(c));
                  mx = 0;
                  int y;
                  for(int i = 0; i < n; i++){
                          scanf("%d %d", &x[i], &y);
                          mx = max(mx,x[i]);
                  }
                  for(int i = 0; i < n; i++){
                          int t = get(x[i]+1);
                          num[t]++;
                          update(x[i]+1,1);
                  }
                  for(int i = 0; i < n; i++)
                          cout << num[i] << endl;
                          system("pause");
    
}
    
