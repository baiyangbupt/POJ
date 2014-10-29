#include<iostream>
using namespace std;

int throws[1001],jump[101],player,thrownum,p[7],tomiss[7];
bool miss[101], extra[101];

int main(){
    int n, i = 0, x, y, winner;
    while(cin>>n&&n!=0) throws[i++] = n;
    thrownum = i;
    while(cin>>n&&n!=0){
                        winner = -1;
                        for(int i = 0; i <= 100; i++) jump[i] = i;
                        memset(miss,0,sizeof(miss));
                        memset(extra,0,sizeof(extra));
                        memset(p,0,sizeof(p));
                        memset(tomiss,0,sizeof(tomiss));
                        player = n;
                        while(cin>>x>>y&&(x||y)) jump[x] = y;
                        while(cin>>n&&n!=0){
                                            if(n>0) extra[n] = 1;
                                            else miss[-1*n] = 1;
                        }
                        int curplayer = 0;
                        for(int i = 0; i < thrownum && winner<0; i++){
                                if(tomiss[curplayer]) 
                                                      tomiss[curplayer] = 0, curplayer = (curplayer+1)%player;
                                if(p[curplayer]+throws[i]<=100)
                                                               p[curplayer]+=throws[i];
                                if(miss[p[curplayer]]) 
                                                       tomiss[curplayer] = 1;
                                else if(extra[p[curplayer]]) 
                                     curplayer = (curplayer-1)%player;
                                p[curplayer] = jump[p[curplayer]];
                                //cout << curplayer << " " << p[curplayer] << endl;
                                curplayer = (curplayer+1)%player;
                                if(p[curplayer]==100) winner = curplayer;
                                
                        }
                        cout << winner+1 << endl;
    }
                                
                        }
                                
