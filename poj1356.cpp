#include<iostream>
#include<algorithm>
using namespace std;

struct node{
       int x, y;
}nn[1001];

bool operator<(const node &a, const node &b){
     if(a.x==b.x)
                 return a.y < b.y;
     return a.x<b.x;
}
int n,r;

int main(){
    int nc;
    cin >> nc;
    while(nc--){
                cin >> n >> r;
                for(int i = 0; i < n; i++)
                        cin >> nn[i].x >> nn[i].y;
                sort(nn,nn+n);
                
                int res = 0;
                for(int i = 0; i < n; i++){
                        int t = 1;
                        for(int j = i+1; j < n; j++)
                                if(nn[j].x<=nn[i].x+r&&nn[j].y<=nn[i].y+r&&nn[j].y>=nn[i].y)
                                                                        t++;
                                else if(nn[j].x>nn[i].x+r)
                                     break;
                        res = max(res,t);
                        t = 1;
                        for(int j = i-1; j >= 0; j--)
                                if(nn[j].x>=nn[i].x-r&&nn[j].y>=nn[i].y-r&&nn[j].y<=nn[i].y)
                                                                          t++;
                                else if(nn[j].x<nn[i].x-r)
                                     break;
                        res = max(res,t);
                        t = 1;
                        for(int j = i-1; j >= 0; j--)
                                if(nn[j].x<nn[i].x||nn[j].y<nn[i].y-r)
                                                   break;
                                else if(nn[j].y<=nn[i].y&&nn[j].y>=nn[i].y-r)
                                     t++;
                        for(int j = i+1; j < n; j++)
                                if(nn[j].x<=nn[i].x+r&&nn[j].y<=nn[i].y&&nn[j].y>=nn[i].y-r)
                                                                                            t++;
                                else if(nn[j].x>nn[i].x+r)
                                     break;
                        res = max(res,t);
                        t = 1;
                        for(int j = i+1; j < n; j++)
                                if(nn[j].x>nn[i].x||nn[j].y>nn[i].y+r)
                                                                      break;
                                else if(nn[j].y>=nn[i].y&&nn[j].y<=nn[i].y+r)
                                     t++;
                        for(int j = i-1; j>=0; j--)
                                if(nn[j].x>=nn[i].x-r&&nn[j].y>=nn[i].y&&nn[j].y<=nn[i].y+r)
                                                                                            t++;
                                else if(nn[j].x<nn[i].x-r)
                                     break;
                        res = max(res,t);
                }
                cout << res << endl;
    }
}
                        
                                     
