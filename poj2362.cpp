#include<iostream>
using namespace std;

bool cmp(int a, int b){
     return a>b;
}

bool dfs(int p, int n, int *a, int target, int cur, bool *used, int count){
     if(cur==target){
                     if(count==3) return 1;
                     int i = 0;
                     while(i<n&&used[i]) i++;
                     used[i] = 1;
                     if(dfs(i,n,a,target,0,used,count+1))
                                                         return 1;
                     used[i] = 0;
     }
     else{
          if(p==n) return 0;
          
          if(used[p]||cur+a[p]>target) return 0;
}

int main(){
    int n,a[100001], total;
    bool used[1000000];
    cin >> n;
    while(n--){
               int m, mm = 0;
               total = 0;
               cin >> m;
               memset(used,0,sizeof(used));
               for(int i = 0; i < m; i++) {
                       cin >> a[i];
                       total += a[i];
                       mm = max(mm,a[i]);
               }
               sort(a,a+m,cmp);
               if(total%4){
                           cout << "no" << endl;
                           continue;;
               }
               total/=4;
               if(mm>total){
                            cout << "no" << endl;
                            continue;
               }
               used[0] = 1;
               if(dfs(0,m,a,total,a[0],used,0))
                                              cout << "yes" << endl;
               else
                   cout << "no" << endl;
    }
}
