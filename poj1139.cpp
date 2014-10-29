#include<iostream>
using namespace std;


bool catin[101], mousein[101], catdoor[101][101], mousedoor[101][101];
int R,cat,mouse;

void dfs(int p, int sign){
     if(sign==0&&catin[p]) return;
     if(sign==1&&mousein[p]) return;
     
     sign==0?catin[p] = 1: mousein[p] = 1;
     
     for(int i = 1; i <= R; i++)
             if(sign==0&&catdoor[p][i])
                                       dfs(i,0);
             else if(sign==1&&mousedoor[p][i])
                  dfs(i,1);
     
     return ;
}

bool find(int origin, int p, int house){
     //cout << p << endl;
     if(p==origin&&house>=2)
                            return 1;
     
     if(catin[p]) return 0;
     for(int i = 1; i <= R; i++)
             if(mousedoor[p][i]){
                             if(find(origin, i, house+1))
                                             return 1;
             }
     return 0;
}

int main(){ 
    int ca;
    bool canmeet,canavoid;
    cin >> ca;
    while(ca--){
                canmeet = 0, canavoid = 0;
                cin >> R >> cat >> mouse;
                int x,y;
                memset(catin,0,sizeof(catin));
                memset(mousein,0,sizeof(mousein));
                memset(catdoor,0,sizeof(catdoor));
                memset(mousedoor,0,sizeof(mousedoor));
                while(cin>>x>>y&&x!=-1)
                                       catdoor[x][y] = 1;
                while(cin>>x>>y&&x!=-1)
                                       mousedoor[x][y] = 1;
                dfs(cat,0);
                dfs(mouse,1);
                for(int i = 1; i <= R; i++)
                        if(catin[i]&&mousein[i])
                                                canmeet = 1;
                canavoid = find(mouse,mouse,0);
                cout <<(canmeet?'Y':'N') << " " << (canavoid?'Y':'N') << endl;
    }
}
                
