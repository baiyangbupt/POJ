#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct node{
       int line, col;
       node(int a = 0, int b = 0):line(a),col(b){}
};

char grid[1001][1001];
char direction[8] = {'A','B','C','D','E','F','G','H'};

int L,C,W,x,y,dir;
vector<vector<node> > table(256);

void bfs(string s){
     int stline, stcol;
     for(int i = 0; i < table[s[0]].size(); i++){
             stline = table[s[0]][i].line, stcol = table[s[0]][i].col;
             //cout << i << " " << stline << " " << stcol << " " <<s.size() << endl;
             if(stline>=s.size()-1){
                                    int j = 0, line = stline, col = stcol;
                                    while(j<s.size()&&grid[line][col]==s[j]) j++, line--;
                                    if(j==s.size()){
                                                   dir = 0;
                                                   x = stline, y = stcol;
                                                   return;
                                    }
                                    if(C-col>=s.size()){
                                                        j = 0, line = stline;
                                                        while(j<s.size()&&grid[line][col]==s[j]) line--, col++, j++;
                                                        if(j==s.size()){
                                                                        dir = 1;
                                                                        x = stline, y = stcol;
                                                                        return;
                                                        }
                                    }
             }
             if(C-stcol>=s.size()){
                                   int j = 0, line = stline, col = stcol;
                                   while(j<s.size()&&grid[line][col]==s[j]) {
                                                                            //cout << grid[line][col] << " " << s[j] << endl;
                                                                            col++, j++;
                                   }
                                   if(j==s.size()){
                                                   dir = 2;
                                                   x = stline, y = stcol;
                                                   return;
                                   }
                                   if(L-line>=s.size()){
                                                        j = 0, col = stcol;
                                                        while(j<s.size()&&grid[line][col]==s[j]) line++, col++, j++;
                                                        if(j==s.size()){
                                                                        dir = 3;
                                                                        x = stline, y = stcol;
                                                                        return;
                                                        }
                                   }
             }
             if(L-stline>=s.size()){
                                    int j = 0, line = stline, col = stcol;
                                    while(j<s.size()&&grid[line][col]==s[j]) line++, j++;
                                    if(j==s.size()){
                                                    dir = 4;
                                                    x = stline, y = stcol;
                                                    return;
                                    }
                                    if(stcol>=s.size()-1){
                                                        j = 0, line = stline;
                                                        while(j<s.size()&&grid[line][col]==s[j]) j++, line++, col--;
                                                        if(j==s.size()){
                                                                        dir = 5;
                                                                        x = stline, y = stcol;
                                                                        return;
                                                        }
                                    }
             }
             if(stcol>=s.size()-1){
                                   int j = 0, line = stline, col = stcol;
                                   while(j<s.size()&&grid[line][col]==s[j]) j++, col--;
                                   if(j==s.size()){
                                                   dir = 6;
                                                   x = stline, y = stcol;
                                                   return;
                                   }
                                   if(stline>=s.size()-1){
                                                          j = 0, col = stcol;
                                                          while(j<s.size()&&grid[line][col]==s[j]) j++, col--, line--;
                                                          if(j==s.size()){
                                                                          dir = 7;
                                                                          x = stline, y = stcol;
                                                                          return;
                                                          }
                                   }
             }
             
     }
}
             

int main(){
    string s;
    while(cin>>L>>C>>W){
                        for(int i = 0; i < L; i++)
                                for(int j = 0; j < C; j++){
                                        cin >> grid[i][j];
                                        table[grid[i][j]].push_back(node(i,j));
                                }
                        for(int i = 0; i < W; i++){
                                cin >> s;
                                bfs(s);
                                cout << x << " " << y << " " << direction[dir] << endl;
                        }
    }
}
                                
