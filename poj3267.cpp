#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int s,n;
    cin >> n >> s;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(),v.end());
    int res=0,i;
    for(i = n-1; i>=0; i--)
            if((res+=v[i])>=s) break;
    cout << n-1-i+1 << endl;
    system("pause");
}
