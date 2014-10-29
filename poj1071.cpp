#include<iostream>
#include<vector>
using namespace std;

bool grid[101][101];
struct node{
       int r1, r2;
       node(int a = 0, int b = 0):r1(a), r2(b){};
};

vector<node> range;
vector<char> direction;
int row,col;
                
bool dfs(int r, int c, int p){
     if(p==range.size()) return 1;
     if(r>row||r<1||c>col||c<1) return 0;
     if(grid[r][c]) return 0;
     
     int dr, dc;
     if(direction[p]=='R') dc = 1,  dr = 0;
     else if(direction[p]=='L') dc = -1, dr = 0;
     else if(direction[p]=='U') dr = -1, dc = 0;
     else dr = 1, dc = 0;
     
     int i = 0;
     while(i<=range[p].r2&&r+i*dr>0&&r+i*dr<=row&&c+i*dc>0&&c+i*dc<=col&&grid[r+i*dr][c+i*dc]==0) i++;
     if(i<range[p].r1) return 0;
     
     for(int j = range[p].r1; j < i; j++){
             int t1,t2;
             t1 = j*dr, t2 = j*dc;
             if(dfs(r+t1,c+t2,p+1)) return 1;
     }
     return 0;
}
     

int main(){
    int nc;
    cin >> nc;
    while(nc--){
                cin >> row >> col;
                for(int i = 1; i <= row; i++)
                        for(int j = 1; j <= col; j++)
                                cin >> grid[i][j];
                int r1,r2;
                char dir;
                range.clear();
                direction.clear();
                while(cin>>r1>>r2&&(r1||r2)){
                                             range.push_back(node(r1,r2));
                                             cin >> dir;
                                             direction.push_back(dir);
                }
                
                int count = 0;
                for(int i = 1; i <= row; i++)
                        for(int j = 1; j <= col; j++)
                                if(grid[i][j]==0&&dfs(i,j,0)){
                                                              //cout << i << " " << j << endl;
                                                           count++;
                                }
                cout << count << endl;
    }
}
