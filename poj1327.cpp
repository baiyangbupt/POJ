#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

char grid[256][256];
bool visit[256][256];

int T,m,k,dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
double center[1000][2];

int dfs(int x, int y, vector<int> &px, vector<int> &py){
    if(grid[x][y]=='.'||visit[x][y])
                   return 0;
    
    visit[x][y] = 1;
    int res = 0;
    px.push_back(x), py.push_back(y);
    for(int i = 0; i < 4; i++){
            int nx = x+dx[i], ny = y+dy[i];
            if(nx>=0&&nx<m&&ny>=0&&ny<k)
                                        res+=dfs(nx,ny,px,py);
    }
    return res+1;
}

int main(){
    while(cin>>m>>k&&m){
                     string s;
                     T = 0;
                     while(s!=string(m,'=')){
                                             for(int i = 0; i < k; i++)
                                                     for(int j = 0; j < m; j++)
                                                             cin >>grid[j][i];
                                             cin >> s;
                                             memset(visit,0,sizeof(visit));
                                             int area = 0,cx,cy;
                                             double tcenterx, tcentery;
                                             for(int i = 0; i < k; i++)
                                                     for(int j = 0; j < m; j++)
                                                             if(grid[j][i]=='x'&&visit[j][i]==0){
                                                                                 vector<int> px, py;
                                                                                 int n;
                                                                                 if(area<(n=dfs(j,i,px,py))){
                                                                                                             area = n;
                                                                                                             int sum = 0;
                                                                                                             for(int i = 0; i < px.size(); i++)
                                                                                                                     sum+=px[i];
                                                                                                             tcenterx = sum*1.0/n;
                                                                                                             sum = 0;
                                                                                                             for(int i = 0; i < py.size(); i++)
                                                                                                                     sum+=py[i];
                                                                                                             tcentery = sum*1.0/n;
                                                                                                             //cout << n << " " << tcenterx << " " << tcentery << endl;
                                                                                 }
                                                             }
                                             center[T][0] = tcenterx, center[T][1] = tcentery;
                                             T++;
                                             //cout << tcenterx << " " << tcentery << endl;
                     }
                     int dt = T/2;
                     double resx = 0, resy = 0;
                     for(int i = 0; i < dt; i++)
                             resx+=center[i+dt][0]-center[i][0], resy = center[i+dt][1]-center[i][1];
                     resx /= dt*dt*1.0, resy /=dt*dt*1.0;
                     cout << setiosflags(ios::fixed) << setprecision(2) << resx << " " << resy <<endl;
    }
}
                     
    
