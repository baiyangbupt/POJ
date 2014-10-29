#include<iostream>
#include<vector>
using namespace  std;

int fa[300], rank[300], high[300];

void Union(int win, int lose){
     fa[lose] = win;
     rank[win] += rank[lose];
}

void gethigh(int x){
     if(high[x]>0)
                  return;
     
     gethigh(fa[x]);
     high[x] = high[fa[x]]+1;
}

int main(){
    int n;
    while(cin>>n&&n){
                     memset(high,-1,sizeof(high));
                     int num =  1<<n;
                     for(int i = 1; i <= num; i++)
                             fa[i] = i, rank[i] = 1;
                     
                     vector<int> v;
                     for(int i = 1; i <= num; i++)
                             v.push_back(i);
                             
                     while(v.size()>1){
                                        vector<int> tv;
                                        int t = v.size(),win, lose;
                                        for(int i = 0; i < t/2; i++){
                                                cin >> win;
                                                tv.push_back(win);
                                                lose = v[2*i]+v[2*i+1]-win;
                                                Union(win,lose);
                                                //cout << win << " " << rank[win] <<" " << lose << " " << rank[lose] << endl; 
                                        }
                                        
                                        v = tv;
                     }
                     
                     int cham;
                     for(int i = 1; i <= num; i++)
                             if(rank[i]==num){
                                              cham = i, high[i] = 1;
                                              break;
                             }
                     
                     
                     int m;
                     cin >> m;
                     for(int i = 0; i < m; i++){
                             int ob;
                             cin >> ob;
                             gethigh(ob);
                             cout << "Player "<<ob<<" can be ranked as high as "<<high[ob]<<" or as low as "<< num-(rank[ob]-1) <<'.'<< endl;
                     }
                     cout << endl;
    }
}
