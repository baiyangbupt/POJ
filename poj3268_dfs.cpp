#include<iostream>
#include <vector>
using namespace std;

int dfs(int p, int acu, int target, vector<int> &v){
    if(acu>target||p==v.size()) return acu;
    
    int m = 0x7fffffff;
    for(int i = p; i < v.size(); i++){
            acu+=v[i];
            int t = dfs(i+1,acu,target,v);
            m = t>=target?min(t,m):m;
            acu-=v[i];
    }
    return m;
}

int main(){
    int n,s;
    cin >> n >> s;
    vector<int> v(n);
    bool dp[200000];
    for(int i = 0; i < n; i++) cin >> v[i];
    
    int res = dfs(0,0,s,v);
    cout << res-s << endl;
    system("pause");
} 
