#include<iostream>
using namespace std;

int total;

bool cmp(int i, int j){
     return i>j;
}

bool dfs(int p, int n, int *a, int cursum, int target, bool *used, int count, int num){
     if(cursum==target){
                        if(count == num-1)
                                 return 1;
                        int i = 0;
                        while(i<n&&used[i]) i++;
                        if(i==n) return 0;
                        used[i] = 1;        //the 1st one to be used   else   return 0
                        if(dfs(i+1,n,a,a[i],target,used,count+1,num))
                                                           return 1;
                        used[i] = 0;
     }
     else{
          if(p==n) return 0;
          for(int i = p; i < n; i++){
                  if(a[i]+cursum>target) continue;
                  if(i>0&&a[i]==a[i-1]&&!used[i-1]) continue;
                  if(used[i]) continue;
                  used[i] = 1;
                  if(dfs(i+1,n,a,cursum+a[i],target,used,count,num))
                                                                    return 1;
                  used[i] = 0;
          }
     }
     return 0;
}
int main(){
    int n, a[64], m;
    bool len[3300], used[64];
    while(cin>>n){
                  m = 0;
                  total = 0;
                  if(n==0) break;
                  memset(len,0,sizeof(len));
                  memset(used,0,sizeof(used));
                  len[0] = 1;
                  for(int i = 0; i < n; i++){
                          cin >> a[i];
                          total+=a[i];
                          m = max(m,a[i]);
                          for(int k = 50*i; k >= 0; k--)
                                  if(len[k])
                                             len[k+a[i]]=1;
                  }
                  sort(a,a+n,cmp);
                  int i;
                  for(i = m; i <= total/2; i++)
                          if(len[i]&&total%i==0){
                                                 int num = total/i;
                                                 used[0] = 1;
                                                 if(dfs(1,n,a,a[0],i,used,0,num)){
                                                                         cout << i << endl;
                                                                         break;
                                                 }
                                                 used[0] = 0;
                          }
                  if(i==total/2+1) cout << total << endl;
    }
}
                  
