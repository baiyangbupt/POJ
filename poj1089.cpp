#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct interval{
       int l,r;
}nn[50000];

bool operator <(const interval &a, const interval &b){
     return a.l < b.l;
}

vector<interval> res;

int main(){
    int n;
    cin >> n;
    for(int i=  0; i < n; i++)
            cin >> nn[i].l >> nn[i].r;
    
    sort(nn,nn+n);
    int l = nn[0].l, r = nn[0].r;
    for(int i = 1; i < n; i++)
            if(nn[i].l<=r)
                          r = max(r,nn[i].r);
            else{
                 interval t;
                 t.l = l, t.r = r;
                 res.push_back(t);
                 l = nn[i].l, r =  nn[i].r;
            }
    interval t;
    t.l = l, t.r = r;
    res.push_back(t);
    for(int i = 0; i < res.size(); i++)
            cout << res[i].l <<" " << res[i].r << endl;
    system("pause");
}
