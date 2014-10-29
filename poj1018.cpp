#include<iostream>
#include<algorithm>
#include<set>
#include<iomanip>
using namespace std;

struct node{
       int b, p;
       
};
bool cmp(const node &a, const node &b){
            return a.p<b.p;
}
int main(){
    int nc,nd,nm[100];
    cin >> nc;
    node nn[101][101];
    set<int> h;
    while(nc--){
                   float ratio=0;
                   h.clear();
                   cin >> nd;
                   for(int i = 1; i <= nd; i++){
                           cin >> nm[i];
                           for(int j = 1; j <= nm[i]; j++){
                                   cin >> nn[i][j].b >>  nn[i][j].p;
                                   if(h.find(nn[i][j].b)==h.end())
                                                                  h.insert(nn[i][j].b);
                           }
                           sort(nn[i]+1,nn[i]+nm[i]+1,cmp);
                   }
                   for(set<int>::iterator it = h.begin(); it!=h.end(); it++){
                                          int bb = *it, cost = 0,i,j;
                                          for(i = 1; i <= nd; i++){
                                                  for(j = 1; j <= nm[i]; j++)
                                                          if(nn[i][j].b>=bb){
                                                                             cost+=nn[i][j].p;
                                                                             break;
                                                          }
                                                  if(j==nm[i]+1) break;
                                          }
                                          if(i<=nd) break;
                                          if(ratio<(bb*1.0/cost)){
                                                                  //cout << bb << " " << cost << endl;
                                                                 ratio = bb*1.0/cost;
                                          }
                   }
                   cout <<setiosflags(ios::fixed)<< setprecision(3) << ratio << endl;
    }
}
