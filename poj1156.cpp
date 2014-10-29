#include<iostream>
#include<queue>

using namespace std;

int u,v,c,h[701][701],m[701],M[701],quemax[701],quemin[701],maxhead,minhead,maxtail,mintail;

int main(){
    while(cin >> u >> v >> c){
            for(int i = 0; i < v; i++)
                    for(int j = 0; j < u; j++)
                            cin >> h[i][j];
            
            int maxarea = 0;
            for(int i = 0; i < u; i++){
                    for(int k = 0; k < v; k++)
                            m[k] = M[k] = h[k][i];
                    
                    for(int j = i; j < min(i+100,u); j++){
                            for(int k = 0; k < v; k++) m[k] = min(m[k],h[k][j]), M[k] = max(M[k],h[k][j]);
                            int st = 0, res = 0;
                            maxhead = maxtail = minhead = mintail = 0;
                            quemax[maxtail++] = 0, quemin[mintail++] = 0;
                            
                            //if(v*(j-i)<maxarea) continue;
                            //if(i==3&&j==9) cout << i << " " << j << endl;
                            for(int k = 0; k < v &&(v-st)*(j-i+1)>maxarea; k++){
                                    while(minhead<mintail&&m[k]<m[quemin[mintail-1]])
                                                                                     mintail--;
                                    quemin[mintail++] = k;
                                    while(maxhead<maxtail&&M[k]>M[quemax[maxtail-1]])
                                                                                     maxtail--;
                                    quemax[maxtail++] = k;
                                    
                                    while(maxtail>maxhead&&mintail>minhead&&m[quemin[minhead]]+c<M[quemax[maxhead]]){
                                                                                                                     st++;
                                                                                                                     while(minhead<mintail&&quemin[minhead]<st)
                                                                                                                                                               minhead++;
                                                                                                                     while(maxhead<maxtail&&quemax[maxhead]<st)
                                                                                                                                                               maxhead++;
                                    }
                                    res = max(res,k-st+1);
                            }
                            maxarea = max(maxarea,res*(j-i+1));
                    }
            }                
            
            cout << maxarea << endl;
    }
}
