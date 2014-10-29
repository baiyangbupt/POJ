#include<iostream>
using namespace std;



bool dfs(int p, int *a, int cur, int target){
     if(cur==target) return 1;
     if(cur>target||p==6) return 0;
     
     for(int i = p; i < 6; i++){
             if(a[i]==0) continue;
             a[i]--;
             if(dfs(i,a,cur+i+1,target)) return 1;
             a[i]++;
     }
     return 0;
}

int main(){
    int a[6], total, t, s, i= 1, count, b[1000];
    bool dp[121000];
    while(1){
             memset(dp,0,sizeof(dp));
             total = s = count = 0;
             for(int i = 0; i < 6; i++){
                     cin >> a[i];
                     total+=(i+1)*a[i];
                     for(int k = 1; k <= a[i]; k<<=1){
                             b[count++] = k*(i+1);
                             a[i]-=k;
                     }
                     if(a[i]>0) b[count++] = a[i]*(i+1);
             }
             if(total==0) break;
             t = total/2;
             cout << "Collection #" << i<<":" << endl;
             if(total%2)
                        cout << "Can't be divided." << endl;
             else{
                  dp[0] = 1;
                  for(int i = 0; i < count; i++)
                     for(int j = t; j>=0; j--)
                             if(dp[j])
                                      dp[j+b[i]] = 1;
                 if(dp[t]) 
                                 cout << "Can be divided." << endl;
                 else cout << "Can't be divided." << endl;
             }
             i++;
             cout << endl;
    }
}
