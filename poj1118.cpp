#include<iostream>
#include<vector>
using namespace std;

struct point{
       int x,y;
}pp[705];

bool oneline(const point &p1, const point &p2, const point &p3){
     return (p1.x-p3.x)*(p2.y-p3.y)==(p1.y-p3.y)*(p2.x-p3.x);
} 

int main(){
    int n;
    while(cin >> n&&n){
        for(int i = 0; i < n; i++)
                cin >> pp[i].x >> pp[i].y;
        int res = 0;
        for(int i = 0; i < n; i++)
                for(int j = i+1; j < n; j++)
                        {
                                 int t = 2;
                                 for(int k = j+1; k < n; k++)
                                         if(oneline(pp[i],pp[j],pp[k]))
                                                                                   t++;
                                 res = max(res,t);
                        }
         cout << res << endl;
    }
} 
