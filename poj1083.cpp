#include<iostream>
#include<algorithm>
using namespace std;

struct node{
       int l,r;
}nn[200];
int cnt[401];
bool operator < (const node &a, const node &b){
     return a.l < b.l;
}

int main(){
    int nc;
    cin >> nc;
    while(nc--){
                int n;
                cin >> n;
                for(int i = 0; i < n; i++){
                        int a,b;
                        cin >> a >> b;
                        nn[i].l = min(a,b);
                        nn[i].r = max(a,b);
                        if(nn[i].l%2==0)
                                        nn[i].l--;
                        if(nn[i].r%2==0)
                                        nn[i].r--;
                }
                sort(nn,nn+n);
                int res = 0;
                for(int i = 1; i < n; i++){
                        int t = 1;
                        for(int j = i-1; j >= 0; j--)
                                if(nn[i].l<=nn[j].r)
                                                    t++;
                        res = max(res,t);
                }
                cout << res*10 << endl;
    }
}
    
