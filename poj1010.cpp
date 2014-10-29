#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool uniq = 0;
void dfs(int p, int n, int *a, int sum, int target, vector<int> &res, vector<int> &temp, int cate){
     //cout << sum << endl;
     if(temp.size()>4) return;
     if(sum>target||p>n) return;
     if(sum==target){
                     if(temp.size()>4) return;
                     if(res.empty()){
                                     res = temp;
                                     res.push_back(cate);
                                     uniq = 1;
                     }
                     else{
                          int lt = temp.size(), lr = res.size();
                          if(cate>res[lr-1]) res = temp, res.push_back(cate), uniq = 1;
                          else if(cate==res[lr-1]){
                               if(lr-1>lt)
                                          res = temp, res.push_back(cate), uniq = 1;
                               else if(lr-1==lt){
                                    if(res[lr-2]<temp[lt-1])
                                                            res = temp, res.push_back(cate), uniq = 1;
                                    else if(res[lr-2]==temp[lt-1])
                                         uniq = 0;
                               }
                          }
                     }
                     return;
     }
     int i = 0;
     vector<int> t = temp;
     while(t.size()<=4&&sum+i*a[p]<=target){
                          dfs(p+1,n,a,sum+i*a[p],target,res,t,cate+(i>0)), i++;
                               t.push_back(a[p]);
     }
}

int geta(int *a, int n){
     sort(a,a+n);
     int m = 1;
     int rep = 1;
     for(int i = 1; i < n; i++)
             if(a[i]!=a[i-1])
                             a[m++] = a[i], rep = 1;
             else if(rep<=4) a[m++] = a[i], rep++;
     return m;
}
     

int main(){
    int a[100], n, b[100];
    vector<int> res,temp;
    while(1){
             uniq = 1;
             res.clear();
             temp.clear();
             int n,i = 0, t;
             while(cin>>t){
                           if(t==0) break;
                           a[i++] = t;
             }
             i = geta(a, i);
             //cout << i << endl;
             while(cin>>t){
                             res.clear();
                             temp.clear();
                             if(t==0) break;
                             dfs(0,i,a,0,t,res,temp,0);
                             if(res.empty()) cout << t << " ---- ";
                             else cout << t << " (" << res[res.size()-1] << "): ";
                             
                             if(res.empty())
                                            cout << "none" << endl;
                             else if(uniq==0)
                                  cout << "tie" << endl;
                             else{
                                  for(int i = 0; i < res.size()-1; i++)
                                          cout << res[i] << " " ;
                                  cout << endl;
                             }
             }
    }
}
