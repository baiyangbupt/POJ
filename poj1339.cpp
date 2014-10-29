#include<iostream>
#include<queue>
#include<vector>
using namespace std;


int main(){
    int m,n;
    cin >> n;
    while(n--){
               cin >> m;
               priority_queue<int,vector<int>, greater<int> > q;
               int c;
               for(int i = 0; i < m; i++){
                       cin >> c;
                       q.push(c);
               }
               int res = 0;
               while(q.size()>1){
                                 int a = q.top();
                                 q.pop();
                                 int b = q.top();
                                 q.pop();
                                 //cout << a << ' ' << b << endl;
                                 res+=a+b;
                                 q.push(a+b);
               }
               cout << res << endl;
    }
}
