#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct node{
       int row, col;
       node(int a, int b) : row(a), col(b){}
};

bool operator<(const node &a, const node &b){
     if(a.col==b.col) return a.row<b.row;
     return a.col < b.col;
}

bool map[5001][5001];

int main(){
    int r,c;
    vector<node> vv;
    cin >> r >> c;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
            int x,y;
            cin >> x >> y;
            map[x][y] = 1;
            node n(x,y);
            vv.push_back(n);
    }
    sort(vv.begin(), vv.end());
    
    int res = 0, count;
    for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                    count = 2;
                    int dr = vv[j].row - vv[i].row, dc = vv[j].col-vv[i].col, pr = vv[j].row+dr, pc = vv[j].col+dc;
                    if(vv[j].col+dc>c) break;
                    if(vv[i].row-dr>0&&vv[i].col-dc>0&&vv[i].row-dr<r&&vv[i].col-dc<c) continue;
                    while(pr>0&&pc>0&&pr<=r&&pc<=c){
                                                    if(map[pr][pc]==0){
                                                                       count = 0;
                                                                       break;
                                                    }
                                                    count++, pr+=dr, pc+=dc;
                    }
                    res = max(res,count);
            }
    }
    if(res<3) cout << 0 << endl;
    else cout << res << endl;
    system("pause");
}
    
