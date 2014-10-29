#include<iostream>
#include<cmath>
using namespace std;

int m,n,link[101];
bool map[101][101], visit[101];
struct point{
       int x,y;
};

point mroute[101],inp[101];

float dis(point a, point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int find(int x){
    for (int i = 1; i <= n-1; i++){
        if(map[x][i]&&visit[i]==0){
                                   visit[i] = 1;
                                   if(link[i]==0||find(link[i])){
                                                                 link[i] = x;
                                                                 //rlink[x] = i;
                                                                 return 1;
                                   }
        }
    }
    return 0;
}
        

void print(){
     for(int i = 1; i <= m; i++)
             for(int j = 1;  j< n; j++){
                     cout << mroute[j].x << " " << mroute[j].y << " " << inp[i].x << " "<< inp[i].y << " " << mroute[j+1].x << " " << mroute[j+1].y << " " << map[i][j] << endl;
             }
}

void init(){
     memset(map,0,sizeof(map));
     memset(link,0,sizeof(link));
     //memset(rlink,0,sizeof(rlink));
     for(int i = 1; i <= m; i++){
             for(int j = 1; j < n; j++)
                     if(dis(mroute[j],inp[i])+dis(mroute[j+1],inp[i])<=2*dis(mroute[j],mroute[j+1]))
                                                                                                    map[i][j] = 1;
     }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> mroute[i].x >> mroute[i].y;
    for(int i = 1; i <= m; i++) cin >> inp[i].x >> inp[i].y;
    init();
    //print();
    int s = 0;
    for(int i = 1; i <= m; i++){
            memset(visit,0,sizeof(visit));
            if(find(i))
                       s++;
    }
    cout << s+n << endl;
    for(int i = 1; i < n; i++){
            cout << mroute[i].x << " " <<mroute[i].y<<" ";
            if(link[i]!=0) cout << inp[link[i]].x << " " << inp[link[i]].y << " ";
    }
    cout << mroute[n].x << " " << mroute[n].y <<endl;
    system("pause");
}
