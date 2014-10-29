#include<iostream>
#include<string>
#include<set>

using namespace std;

struct point{
       int x,y;
}pp;

char grid[51][51];
int n;

int main(){
    int nc = 1;
    while(cin>>n&&n){
                     set<string> res;
                     memset(grid,0,sizeof(grid));
                     char c;
                     int x,y;
                     for(int i = 0; i < n; i++){
                             cin >> c >> x >> y;
                             grid[x][y] = c;
                     }
                     for(int line = 0; line <= 50; line++){
                             for(int i = 0; i <= 50; i++)
                                     if(grid[line][i]>0){
                                                         for(int j = i+1; j <= 50; j++)
                                                                 if(grid[line][j]){
                                                                                   for(int nextline = line+1; nextline<=50; nextline++)
                                                                                           if(grid[nextline][i]&&grid[nextline][j]){
                                                                                                                                    string t;
                                                                                                                                    t.push_back(grid[line][j]);
                                                                                                                                    t.push_back(grid[nextline][j]);
                                                                                                                                    t.push_back(grid[nextline][i]);
                                                                                                                                    t.push_back(grid[line][i]);
                                                                                                                                    res.insert(t);
                                                                                           }
                                                                 }
                                     }
                     }
                     cout << "Point set " << nc++ <<":";
                     if(res.size()>0){
                                      cout << endl;
                                      int num = res.size(), i = 1;
                                      for(set<string>::iterator it = res.begin(); it!=res.end(); i++,it++){
                                                                cout << " " << *it;
                                                                if(i%10==0)
                                                                           cout <<endl;
                                      }
                                               
                                      if(i%10!=1) cout << endl;
                     }
                     else
                         cout << " No rectangles" << endl;
    }
}
